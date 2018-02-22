#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "SHTime.h"
#include "Renderer.h"
#include "InputManager.h"

class Core
{
public:
	Core();
	virtual ~Core();
	Renderer _renderer;
private:
	//Renderer _renderer;
};

#endif /* CORE_H */
