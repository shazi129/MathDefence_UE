// Fill out your copyright notice in the Description page of Project Settings.


#include "GameNotifier.h"

GameNotifier * GameNotifier::_instance = nullptr;
GameNotifier*	GameNotifier::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new GameNotifier();
	}
	return _instance;
}

GameNotifier::GameNotifier()
{
}

GameNotifier::~GameNotifier()
{
}
