#pragma once
#include "Core.h"

#include "Window.h"
#include "Hades/LayerStack.h"
#include "Hades/Events/Event.h"
#include "Hades/Events/ApplicationEvent.h"

namespace Hades
{
	class HADES_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();

}
