// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "./GameListener.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameNotifier.generated.h"


/**
 * 
 */
UCLASS()
class MATHDEFENCE_API UGameNotifier : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void AddListener(TScriptInterface<IGameListener> listener);

	UFUNCTION(BlueprintCallable)
	void RemoveListener(TScriptInterface<IGameListener> listener);

	UFUNCTION(BlueprintCallable)
		void Clear();

	UFUNCTION(BlueprintCallable)
	void NotifyListeners(const FGameNotifyData& notifyData);

	UFUNCTION(BlueprintCallable)
		bool IsListenerExist(TScriptInterface<IGameListener> listener);

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<TScriptInterface<IGameListener>> Listeners;
};
