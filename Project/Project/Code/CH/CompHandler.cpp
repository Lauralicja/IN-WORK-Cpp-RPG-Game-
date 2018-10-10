#include "CompHandler.h"

void Entity::addGroup(Group mGroup)
{
	groupBitSet[mGroup] = true;
	manager.AddtoGroup(this, mGroup);
}
