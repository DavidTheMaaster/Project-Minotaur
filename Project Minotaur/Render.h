#ifndef _RENDER_H__
#define _RENDER_H__

#include "Module.h"
#include "Defines.h"
#include "SDL\include\SDL.h"


class Render : public Module
{
public:
	Render();
	virtual ~Render();

	bool Awake();
	bool Start();

	bool PreUpdate();
	bool Update();
	bool PostUpdate();

	bool CleanUp();

	void Blit();
	void DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

private:
	SDL_Renderer*	render;
	SDL_Rect		viewport;

	Uint32			flags;
	uint			scale;
};





#endif // !_RENDER_H__

