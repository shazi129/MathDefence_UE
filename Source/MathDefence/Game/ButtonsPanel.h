// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "./InputBtnActor.h"
#include "Components/SceneComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ButtonsPanel.generated.h"

UCLASS()
class MATHDEFENCE_API AButtonsPanel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AButtonsPanel();

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		USceneComponent * PanelRoot;

	UPROPERTY(EditDefaultsOnly);
		TSubclassOf<class AInputBtnActor> InputBtnClass;

		UPROPERTY(EditAnywhere)
			float ButtonWidth;

		UPROPERTY(EditAnywhere)
			float ButtonHeight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
