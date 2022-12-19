#include "Subject.hpp"

void Subject::addObserver(std::shared_ptr<Observer> observer)
{
	observers.push_back(observer);
}

void Subject::removeObserver(std::shared_ptr<Observer> observer)
{
	observers.erase(remove(observers.begin(), observers.end(), observer));
}
