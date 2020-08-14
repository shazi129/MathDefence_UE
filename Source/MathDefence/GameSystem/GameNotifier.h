// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "./Observer.h"
#include "CoreMinimal.h"

/**
 * 
 */
class MATHDEFENCE_API GameNotifier: public Observable
{
public:
	enum  NOTIFY_ID
	{
		E_BTN_INPUT,
	};

public:
	~GameNotifier();

	static GameNotifier * getInstance();

private:
	GameNotifier();
	static GameNotifier * _instance;
};
