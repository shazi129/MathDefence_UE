// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSingleton.h"

UGameSingleton * UGameSingleton::GetGameSingleton()
{
	return Cast<UGameSingleton>(GEngine->GameSingleton);
}

UObject * UGameSingleton::GetInstance(UClass * classType)
{
	FString instanceName = classType->GetName();
	if (InstancesMap.Contains(instanceName))
	{
		return InstancesMap[instanceName];
	}
	else
	{
		UObject * newInstance = NewObject<UObject>(this, classType);
		InstancesMap.Add(instanceName, newInstance);
		return newInstance;
	}
}