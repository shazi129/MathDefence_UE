// Fill out your copyright notice in the Description page of Project Settings.


#include "InputBtnActor.h"

// Sets default values
AInputBtnActor::AInputBtnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	InputBtnRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = InputBtnRoot;

	//µã»÷ÏìÓ¦
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box collision"));
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->BodyInstance.SetCollisionProfileName(TEXT("MDInputBtn"));
	
}

// Called when the game starts or when spawned
void AInputBtnActor::BeginPlay()
{
	Super::BeginPlay();
	CollisionBox->OnClicked.AddUniqueDynamic(this, &AInputBtnActor::OnInputBtnClick);
}


void  AInputBtnActor::OnInputBtnClick(UPrimitiveComponent * primitiveComponent, FKey fKey)
{
	UE_LOG(LogTemp, Warning, TEXT("OnInputBtnClick"));
}

