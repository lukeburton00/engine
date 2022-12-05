//
//  TestComponent.cpp
//  Engine
//
//  Created by Luke Burton on 12/4/22.
//

#include "Component.hpp"

class TestComponent : public Component
{
    public:
        virtual void Update();
        bool componentUpdated;
};

void TestComponent::Update()
{
    componentUpdated = true;
}
