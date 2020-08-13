// Fill out your copyright notice in the Description page of Project Settings.


#include "MDCannon.h"

// Sets default values
AMDCannon::AMDCannon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMDCannon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMDCannon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

