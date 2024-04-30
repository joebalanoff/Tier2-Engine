#include "core/application.h"

int main() {
	Tier2::ApplicationSpecification specs;
	specs.name = "Tier2";
	Tier2::Application* app = new Tier2::Application(specs);

	app->Run();

	delete app;
	return 0;
}