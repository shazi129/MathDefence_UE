// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacker.h"

// Sets default values
AAttacker::AAttacker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

// 	AttackerRoot = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
// 	RootComponent = AttackerRoot;
// 
// 	AttackerRoot->SetSimulatePhysics(true);
// 
// 	AttackNum = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Attack Number"));
// 	AttackNum->SetupAttachment(RootComponent);
// 	AttackNum->HorizontalAlignment = EHTA_Center;
// 	AttackNum->VerticalAlignment = EVRTA_TextCenter;
// 
// 	CollisionBox = CreateDefaultSubobject< UBoxComponent>(TEXT("Collision Box"));
// 	CollisionBox->SetupAttachment(RootComponent);
}

void AAttacker::SetTextRender(UTextRenderComponent * textRender)
{
	_attackNumText = textRender;
}

void AAttacker::SetNumber(int number)
{
	//AttackNum->SetText(FText::FromString(FString::FromInt(number)));
}

// Called when the game starts or when spawned
void AAttacker::BeginPlay()
{
	Super::BeginPlay();
	
}
