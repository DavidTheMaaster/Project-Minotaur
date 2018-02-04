#include "App.h"
#include "Window.h"

Window::Window() : Module()
{
	window = nullptr;
	surface = nullptr;
	
}

Window::~Window()
{
}

bool Window::Awake()
{
	flags = SDL_WINDOW_SHOWN;

	window_width = 500;
	window_height = 500; 

	flags |= SDL_WINDOW_RESIZABLE;

	window = SDL_CreateWindow("Project Minotaur", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, flags);

	if (window == NULL)
	{
		return false;
	}

	surface = SDL_GetWindowSurface(window);


	return true;
}

bool Window::CleanUp()
{
	SDL_DestroyWindow(window);

	SDL_Quit();
	return true;
}

void Window::GetWindowSize(int w, int h)
{
	w = window_width;
	h = window_height;
}