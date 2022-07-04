#include <Hades.h>

class Sandbox : public Hades::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Hades::Application* Hades::CreateApplication()
{
	return new Sandbox();
}