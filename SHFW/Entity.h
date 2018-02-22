#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <glm/glm.hpp>
#include <glm/gtx/matrix_decompose.hpp>

#include "SHFWConfig.h"
#include "InputManager.h"
#include "SHTime.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();
};

#endif /* ENTITY_H */
