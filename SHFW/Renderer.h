#ifndef RENDERER_H
#define RENDERER_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "ResourceManager.h"
#include "Entity.h"
#include "Shader.h"
#include "SHFWConfig.h"

class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	int init();

	GLFWwindow* getWindow() { return _window; };

private:
	ResourceManager _resman;

	GLFWwindow* _window;

	Shader* _defaultShader;
};

#endif /* RENDERER_H */
