#include "App.h"
#include "Defines.h"

#include "Window.h"
#include "Render.h"

Application::Application(int argc, char * args[])
{
	window = new Window();
	render = new Render();

	AddModule(window);
	AddModule(render);


}

Application::~Application()
{
}

bool Application::Awake()
{
	bool ret = true;

	for (int i = 0; i < modules.Count(); i++)
	{
		if (ret)
			ret = modules[i]->Awake();
	}
	return ret;
}

bool Application::Start()
{
	bool ret = true;

	for (int i = 0; i < modules.Count(); i++)
	{
		if (ret)
			ret = modules[i]->Start();
	}
	return ret;
}

bool Application::Update()
{
	bool ret = true;

	if (ret)
	{
		ret = PreUpdate();
	}
	if (ret)
	{
		ret = doUpdate();
	}
	if (ret)
	{
		ret = PostUpdate();
	}

	return ret;
}

bool Application::PreUpdate()
{
	bool ret = true;

	for (int i = 0; i < modules.Count(); i++ && ret)
	{
		ret = modules[i]->PreUpdate();
	}
	return ret;
}

bool Application::doUpdate()
{
	bool ret = true;

	for (int i = 0; i < modules.Count(); i++ && ret)
	{
		ret = modules[i]->Update();
	}
	SDL_Rect rect; 
	rect.x = 0; rect.y = 0; rect.w = 10; rect.h = 10;
	App->render->DrawQuad(rect,255,255,0,255);

	return ret;
}

bool Application::PostUpdate()
{
	bool ret = true;

	for (int i = 0; i < modules.Count(); i++ && ret)
	{
		ret = modules[i]->PostUpdate();
	}
	return ret;
}


bool Application::CleanUp()
{
	bool ret = true;

	for (int i = 0; i < modules.Count(); i++ && ret)
	{
		ret = modules[i]->CleanUp();
	}
	return ret;
}

void Application::AddModule(Module* module)
{
	module->Init();
	modules.PushBack(module);
}