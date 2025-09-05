#pragma once

#ifdef KL_PLATFORM_WIN 

extern Kulo::Application* Kulo::CreateApplication();

int main(int argc, char** argv) {
	auto app = Kulo::CreateApplication(); 
	app->Run();
	delete app;
}

#endif
