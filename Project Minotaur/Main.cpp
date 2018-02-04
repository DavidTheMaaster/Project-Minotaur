#include <stdlib.h>

#include "DynArray.h"
#include "App.h"

#include "SDL\include\SDL.h"

#pragma comment( lib, "SDL/lib/SDL2.lib" )
#pragma comment( lib, "SDL/lib/SDL2main.lib" )


enum States
{
	CREATE,
	AWAKE,
	START,
	UPDATE,
	CLEAN_UP,
	FAIL,
	EXIT, 

};

Application* App = NULL;

int main(int argc, char* args[])
{
	int result = EXIT_SUCCESS;
	int state = CREATE;
	while (state != EXIT)
	{
		switch (state)
		{
		case CREATE:

			App = new Application(argc, args);

			if (App != NULL)
			{
				state = AWAKE;
			}
			else
			{
				state = FAIL;
			}
			break;

		case AWAKE:
			if(App->Awake())
			{ 
				state = START;
			}
			else
			{
				state = FAIL;
			}
			break;
		case START:
			if (App->Start())
			{
				state = UPDATE;
			}
			else
			{
				state = FAIL;
			}
			break;

		case UPDATE:

			if (!App->Update())
			{
				state = CLEAN_UP;
			}
			break;

		case CLEAN_UP:

			if (App->CleanUp())
			{
				RELEASE(App);
				state = EXIT;
			}
			else
			{
				state = FAIL;
			}
			break;

		case FAIL:
			result = EXIT_FAILURE;
			state = EXIT;
			break;
		}
	}

	return result;
}