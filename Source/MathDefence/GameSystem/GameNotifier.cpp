// Fill out your copyright notice in the Description page of Project Settings.


#include "GameNotifier.h"

bool UGameNotifier::IsListenerExist(TScriptInterface<IGameListener> listener)
{
	for (int i = 0; i < Listeners.Num(); i++)
	{
		if (Listeners[i] != nullptr && Listeners[i] == listener)
		{
			return true;
		}
	}
	return false;
}

void UGameNotifier::AddListener(TScriptInterface<IGameListener> listener)
{
	if (listener == nullptr)
	{
		return;
	}

	if (!IsListenerExist(listener))
	{
		Listeners.Add(listener);
	}
}

void UGameNotifier::RemoveListener(TScriptInterface<IGameListener> listener)
{
	Listeners.Remove(listener);
}

void UGameNotifier::Clear()
{
	Listeners.Empty();
}

void UGameNotifier::NotifyListeners(const FGameNotifyData& notifyData)
{
	for (int i = 0; i < Listeners.Num(); i++)
	{
		if (Listeners[i] != nullptr)
		{
			IGameListener::Execute_UpdateSelf(Listeners[i].GetObject(), notifyData);
		}
	}
}