// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MDCameraPawn.generated.h"

class UCameraComponent;

UCLASS()
class MATHDEFENCE_API AMDCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMDCameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
		UCameraComponent * MainCamera;
};
