// Fill out your copyright notice in the Description page of Project Settings.


#include "InputResultText.h"

// Sets default values
AInputResultText::AInputResultText()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ResultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = ResultRoot;

	ResultText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Result Text"));
	ResultText->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AInputResultText::BeginPlay()
{
	Super::BeginPlay();
}

