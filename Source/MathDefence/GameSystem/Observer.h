// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
/**
 * 
 */
class Observable;

struct ObserverParam 
{
	ObserverParam()
		: self(nullptr)
		, addData(nullptr)
		, deleteData(nullptr)
		, updateData(nullptr)
		, bUpdateAll(true)
		, id(0)
	{
	}

	//自身
	Observable* self;
	//增加数据
	void* addData;
	//删除数据
	void* deleteData;
	//更新数据
	void* updateData;
	//是否全部更新
	bool bUpdateAll;
	//类型ID
	int id;
};


class Observer
{
public:
	virtual void updateSelf(void*) = 0;
};

class Observable
{
public:
	Observable() {}
	~Observable()
	{
		observers.clear();
	}

private:
	//observers 
	std::vector<Observer*> observers;

	std::vector<int> scriptObservers;

public:

	bool equals(const Observable& obser);

	//addObserver 
	void addObserver(Observer*a);

	//notifyObservers 
	void notifyObservers(void* data = NULL);

	bool isObserverExist(Observer* target);

	void removeAllObservers();

	void removeObserver(Observer* target);
};
