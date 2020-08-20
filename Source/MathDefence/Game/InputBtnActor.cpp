// Fill out your copyright notice in the Description page of Project Settings.


#include "InputBtnActor.h"
#include "Kismet/GameplayStatics.h"
#include "./../MDGameMode.h"
#include "./../GameSystem/GameNotifier.h"
#include "./../GameSystem/GameSingleton.h"
#include "./MDGameNotifier.h"

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
	
	BtnText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("BtnText"));
	BtnText->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AInputBtnActor::BeginPlay()
{
	Super::BeginPlay();
	CollisionBox->OnClicked.AddUniqueDynamic(this, &AInputBtnActor::OnInputBtnClick);
}


void  AInputBtnActor::OnInputBtnClick(UPrimitiveComponent * primitiveComponent, FKey fKey)
{
 	FGameNotifyData notifyData;
 	notifyData.ID = (int)E_BTN_INPUT;
 	notifyData.Data = (UObject*)this;
	UMDGameNotifier * notifier = Cast<UMDGameNotifier>(UGameSingleton::GetGameSingleton()->GetInstance(UMDGameNotifier::StaticClass()));
	notifier->NotifyListeners(notifyData);
// 	GameNotifier::getInstance()->notifyObservers((void*)&param);
}

void AInputBtnActor::SetType(INPUT_BTN_TYPE btnType)
{
	BtnType = btnType;
}

void AInputBtnActor::SetText(FString text)
{
	BtnText->SetText(FText::FromString(text));
}

FString AInputBtnActor::GetText()
{
	return BtnText->Text.ToString();
}

INPUT_BTN_TYPE AInputBtnActor::GetBtnType()
{
	return BtnType;
}

