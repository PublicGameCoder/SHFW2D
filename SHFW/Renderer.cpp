#include "Renderer.h"
#include "Shader.h"

// Include GLAD
#include <glad\glad.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace glm;

Renderer::Renderer()
{
	_window = NULL;
	_defaultShader = NULL;

	this->init();
}

Renderer::~Renderer()
{
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}

int Renderer::init()
{
	// Initialise GLFW
	if( !glfwInit() ) {
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS X

	GLFWmonitor* primary = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(primary);
	std::cout << "monitor: " << mode->width << "x"  << mode->height << std::endl;

	// Open a window and create its OpenGL context
	if (FULLSCREEN) {
		_window = glfwCreateWindow(MINWINDOWWIDTH, MINWINDOWHEIGHT, SHFWTITLE, primary, NULL);
	} else {
		_window = glfwCreateWindow(MINWINDOWWIDTH, MINWINDOWHEIGHT, SHFWTITLE, NULL, NULL);
	}

	if( _window == NULL ) {
		fprintf( stderr, "Failed to open GLFW window.\n" );
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(_window);

	// vsync (0=off, 1=on)
	glfwSwapInterval(VSYNC);

	// Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Ensure we can capture keys being pressed
	glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(CLEARCOLOR_RED, CLEARCOLOR_GREEN, CLEARCOLOR_BLUE, 1.0f);

	if (USE3D) {
		// Cull triangles which normal is not towards the camera
		glEnable(GL_CULL_FACE);
	}

	_defaultShader =_resman.getShader(DEFAULTVERTEXSHADERPATH, DEFAULTFRAGMENTSHADERPATH);

	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Swap buffers
	glfwSwapBuffers(_window);

	return 0;
}