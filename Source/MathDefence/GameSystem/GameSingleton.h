// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Templates/SubclassOf.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameSingleton.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class MATHDEFENCE_API UGameSingleton : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
		static UGameSingleton * GetGameSingleton();

	UFUNCTION(BlueprintCallable)
		UObject * GetInstance(UClass * classType);

protected:
	UPROPERTY(EditAnywhere)
		TMap<FString, UObject*> InstancesMap;
};
