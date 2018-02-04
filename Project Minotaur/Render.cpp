#include "App.h"
#include "Render.h"

#include "Window.h"

Render::Render()
{
	render = nullptr;
}

Render::~Render()
{
}

bool Render::Awake()
{
	bool ret = true; 

	flags = SDL_RENDERER_ACCELERATED;

	scale = 1;

	render = SDL_CreateRenderer(App->window->window, -1, flags);

	if (render == NULL)
	{
		return false;
	}

	return ret;
}

bool Render::Start()
{
	SDL_RenderGetViewport(render, nullptr);

	return true;
}

bool Render::PreUpdate()
{
	SDL_RenderClear(render);
	return true;
}

bool Render::Update()
{
	return true;
}

bool Render::PostUpdate()
{
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderPresent(render);
	return true;
}

bool Render::CleanUp()
{
	SDL_DestroyRenderer(render);
	return true;
}

void Render::DrawQuad(const SDL_Rect & rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Rect aux_rect;

	aux_rect.x = rect.x *scale;
	aux_rect.y = rect.y *scale;
	aux_rect.w = rect.w *scale;
	aux_rect.h = rect.h *scale;



	SDL_RenderDrawRects(render, &aux_rect,1);

	SDL_SetRenderDrawColor(render,r,g,b,a);

	SDL_RenderFillRect(render, &aux_rect);
}
