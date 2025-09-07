#include <Kulo.h>

class Sandbox : public Kulo::Application {
public:
	Sandbox() {
	}

	~Sandbox() {

	}
};

Kulo::Application* Kulo::CreateApplication() { 
	return new Sandbox(); 
}
