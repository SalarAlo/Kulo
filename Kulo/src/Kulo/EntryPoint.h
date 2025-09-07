#pragma once

#ifdef KL_PLATFORM_WIN 

Kulo::Application* Kulo::CreateApplication();

int main(int argc, char** argv) {
	Kulo::Log::Init();

	KL_CORE_WARN("Initialized Core logger");
	KL_INFO("Initialized Client logger");

	auto app = Kulo::CreateApplication(); 
	app->Run();
	delete app;
}

#endif
