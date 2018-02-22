#include "Core.h"
#include <iostream>

int main()
{
	Core core;
	while (1) {
		GLFWwindow* window = core._renderer.getWindow();
		InputManager::getManager()->update(window);
		if (InputManager::getManager()->getKeyDown(KeyCode::Esc) || glfwWindowShouldClose(window)) {
			break;
		}
	}
	return 0;
}