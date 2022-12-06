#include "ComponentSystem.hpp"

void ComponentSystem::registerComponent(Component * component, vector<Component> * componentVector)
{
	componentVector->push_back(*component);
}
