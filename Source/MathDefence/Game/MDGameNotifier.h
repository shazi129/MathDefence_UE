// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "./../GameSystem/GameNotifier.h"
#include "MDGameNotifier.generated.h"

UENUM(BlueprintType)
enum MD_GAME_NOTIFY_ID
{
	E_BTN_INPUT,

	E_START_TO_CHECK_RESULT
};

/**
 * 
 */
UCLASS()
class MATHDEFENCE_API UMDGameNotifier : public UGameNotifier
{
	GENERATED_BODY()

};
