#include "core/application.h"
using namespace Tier2;

int main() {
	Application* app = new Application();

	app->Init();
	app->Run();
}