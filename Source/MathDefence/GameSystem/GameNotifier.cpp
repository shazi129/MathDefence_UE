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
		UE_LOG(LogTemp, Warning, TEXT("%s::AddListener null"), *GetName());
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("%s::AddListener %s"), *GetName(), *(listener.GetObject()->GetName()));

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

void UGameNotifier::NotifyListeners(FGameNotifyData& notifyData)
{
	notifyData.Notifier = this;

	for (int i = 0; i < Listeners.Num(); i++)
	{
		if (Listeners[i] != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s::NotifyListeners[i]:%s"), *this->GetName(),i, *(Listeners[i].GetObject()->GetName()));

			IGameListener::Execute_UpdateSelf(Listeners[i].GetObject(), notifyData);
		}
	}
}