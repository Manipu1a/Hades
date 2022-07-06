#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Hades
{
	class HADES_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}
