// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "./Game/InputBtnActor.h"

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MDGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MATHDEFENCE_API AMDGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void handleBtnInput(INPUT_BTN_TYPE btnType, FText btnText);

public:
	UPROPERTY(BlueprintReadOnly)
		int InputNumber;

};
