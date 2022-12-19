#pragma once
#include <vector>
#include "Observer.hpp"

class Subject
{
public:
	std::vector<std::shared_ptr<Observer>> observers;
	
	void addObserver(std::shared_ptr<Observer> observer);
	void removeObserver(std::shared_ptr<Observer> observer);
};
