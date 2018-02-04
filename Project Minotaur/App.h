#ifndef _APP_H__
#define _APP_H__

#include "DynArray.h"
#include "Module.h"


class Window;
class Render;

class Application
{
public:
	Window* window;
	Render* render;
public:
	Application(int argc, char * args[]);

	virtual ~Application();

	bool Awake();
	bool Start();
	bool Update();
	bool CleanUp();
	void AddModule(Module* module);

private:
	
	bool PreUpdate();
	bool doUpdate();
	bool PostUpdate();


private:

	DynArray<Module*> modules;

};

extern Application* App;


#endif // !_APP_H__

