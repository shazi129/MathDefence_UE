// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Components/SceneComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Attacker.generated.h"

UCLASS()
class MATHDEFENCE_API AAttacker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAttacker();

public:
	UFUNCTION(BlueprintCallable)
	void SetTextRender(UTextRenderComponent * textRender);

	void SetNumber(int number);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int _number;
	UTextRenderComponent * _attackNumText;

};
