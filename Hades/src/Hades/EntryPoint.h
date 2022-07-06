#pragma once

#ifdef HADES_PLATFORM_WINDOWS

extern Hades::Application* Hades::CreateApplication();

int main(int argc, char** argv)
{
	Hades::Log::Init();
	HADES_CORE_WARN("Initialized Log!");
	HADES_INFO("Hello! Var={0}", 5);

	auto app = Hades::CreateApplication();
	app->Run();
	delete app;
}

#endif