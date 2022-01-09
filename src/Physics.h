#pragma once

#include "Common.h"
#include "Entity.h"
#include "Components.h"
#include <math.h>

namespace Physics
{
	Vec2 GetOverlap(ptr<Entity> a, ptr<Entity> b);
	Vec2 GetPreviousOverlap(ptr<Entity> a, ptr<Entity> b);
};

