// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/TextRenderComponent.h"
#include "Components/SceneComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputResultText.generated.h"

UCLASS()
class MATHDEFENCE_API AInputResultText : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInputResultText();

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		USceneComponent * ResultRoot;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		UTextRenderComponent * ResultText;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
