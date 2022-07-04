#pragma once
#include "Core.h"

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
