#pragma once
#include <string>

enum Event
{
	
};

class Observer
{
public:
	virtual void onEvent(Event event, std::string description, void * data) = 0;
};
