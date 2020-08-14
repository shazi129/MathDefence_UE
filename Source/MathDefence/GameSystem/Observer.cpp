// Fill out your copyright notice in the Description page of Project Settings.


#include "Observer.h"

bool Observable::equals(const Observable& obser)
{
	if (&observers == &obser.observers)
		return true;
	else
		return false;
}

//addObserver 
void Observable::addObserver(Observer*a)
{
	if (!isObserverExist(a))
		observers.push_back(a);
}

//notifyObservers 
void Observable::notifyObservers(void* data)
{
	std::vector<Observer*> tmpObservers(observers.begin(), observers.end());
	for (std::vector<Observer*>::const_iterator observer_iterator = tmpObservers.begin(); observer_iterator != tmpObservers.end(); observer_iterator++)
	{
		if (data == nullptr)
		{
			ObserverParam param;
			param.self = this;
			param.bUpdateAll = true;
			(*observer_iterator)->updateSelf(&param);
		}
		else
		{
			ObserverParam* pParam = (ObserverParam*)data;
			pParam->self = this;
			pParam->bUpdateAll = false;
			(*observer_iterator)->updateSelf(pParam);
		}
	}
}

bool Observable::isObserverExist(Observer* target)
{
	for (int i = 0; i < observers.size(); i++)
	{
		Observer* observer = observers.at(i);
		if (!observer)
		{
			continue;
		}
		if (observer == target)
		{
			return true;
		}
	}
	return false;
}

void Observable::removeAllObservers()
{
	observers.clear();
}

void Observable::removeObserver(Observer* target)
{
	if (observers.size() == 0)return;
	std::vector<Observer*>::iterator it = observers.begin();
	while (it != observers.end())
	{
		if (*it == NULL)
		{
			continue;
		}
		if (*it == target)
		{
			observers.erase(it);
			return;
		}
		++it;
	}
}
