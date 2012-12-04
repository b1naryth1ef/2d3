#include "entity.h"

Entity::Entity () {
	mass = defaultMass;
	inertia = defaultInertia;
}

Entity::Entity (cpFloat m, cpFloat i) {
	mass = m;
	inertia = i;
}
