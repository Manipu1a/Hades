#include "Application.h"

#include "Hades/Events/ApplicationEvent.h"
#include "Hades/Log.h"

namespace Hades {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizedEvent e(1280, 720);
		HADES_TRACE(e);

		while (true);
	}

}