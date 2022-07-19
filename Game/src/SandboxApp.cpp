#include <Hades.h>


class ExampleLayer : public Hades::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	virtual ~ExampleLayer()
	{

	}
	void OnUpdate() override
	{
		HADES_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hades::Event& event) override
	{
		HADES_TRACE("{0}", event);
	}
};


class Sandbox : public Hades::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		PushOverlay(new Hades::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Hades::Application* Hades::CreateApplication()
{
	return new Sandbox();
}