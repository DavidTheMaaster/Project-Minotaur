#ifndef _WINDOW_H__
#define _WINDOW_H__

#include "Module.h"
#include "Defines.h"
#include "SDL\include\SDL.h"


class Window : public Module
{
public:
	Window();
	virtual ~Window();

	bool Awake();
	bool CleanUp();

	void GetWindowSize(int w, int h);

public:

	SDL_Window*		window;
	SDL_Surface*	surface;

private:

	uint	window_width;
	uint	window_height;
	uint32	flags;
};


#endif // !_WINDOW_H__

