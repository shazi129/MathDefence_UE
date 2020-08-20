// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AttackerCreator.generated.h"

UCLASS()
class MATHDEFENCE_API AAttackerCreator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAttackerCreator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
