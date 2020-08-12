// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/EngineTypes.h"
#include "ButtonsPanel.h"


// Sets default values
AButtonsPanel::AButtonsPanel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PanelRoot = CreateDefaultSubobject<USceneComponent>("root");
	RootComponent = PanelRoot;

	
}

// Called when the game starts or when spawned
void AButtonsPanel::BeginPlay()
{
	Super::BeginPlay();

	FRotator rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters spawnInfo;

	FVector panelLocation = GetActorLocation();

	//°´Å¥£¬ 3ÐÐ4ÁÐ
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			FVector newLocation(0.0f, 10.0f, 0.0f);
			newLocation.X = (j - 1.5f) * ButtonWidth;
			newLocation.Z = (1 - i) * ButtonHeight;

			AInputBtnActor * btn = GetWorld()->SpawnActor<AInputBtnActor>(InputBtnClass, newLocation, rotation, spawnInfo);
			btn->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

// 			FVector origin;
// 			FVector boxExtent;
// 			btn->GetActorBounds(false, origin, boxExtent);
// 
// 			UE_LOG(LogTemp, Warning, TEXT("origin(%f, %f, %f), boxExtent(%f, %f, %f)"), origin.X, origin.Y, origin.Z, boxExtent.X, boxExtent.Y, boxExtent.Z);
		}
	}
}

