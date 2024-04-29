#include "core/application.h"

int main() {
	Tier2::ApplicationSpecification spec;
	spec.name = "Tier2";

	Tier2::Application* app = new Tier2::Application(spec);

	app->Run();

	delete app;
}