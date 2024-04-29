#include "engine/renderer.h"
#include "engine/input.h"

int main() {
	Renderer renderer;
	if (!renderer.init()) {
		return -1;
	}

	GLFWwindow* window = renderer.getWindow();
	Input input(window);

	while (!glfwWindowShouldClose(window)) {
		input.processInput();

		// Logic here

		renderer.render(); // scene?

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	renderer.shutdown();

	return 0;
}