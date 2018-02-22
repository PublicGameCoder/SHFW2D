#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <string>
#include <map>

// Include GLAD
#include <glad\glad.h>

// Include GLFW
#include <glfw3.h>

#include "SHFWConfig.h"
#include "Shader.h"

class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	Shader* getShader(const std::string& vs, const std::string& fs);

private:

	void deleteShader(const std::string& shadername);

	std::map<std::string, Shader*> _shaders;
};

#endif /* RESOURCEMANAGER_H */
