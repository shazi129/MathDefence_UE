// Fill out your copyright notice in the Description page of Project Settings.


#include "MDCameraPawn.h"

// Sets default values
AMDCameraPawn::AMDCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//根节点
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	//相机
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMDCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

