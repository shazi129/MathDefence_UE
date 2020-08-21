// Fill out your copyright notice in the Description page of Project Settings.


#include "InputResultText.h"
#include "./MDGameNotifier.h"
#include "./../GameSystem/GameSingleton.h"

// Sets default values
AInputResultText::AInputResultText()
{
	_number = 0;

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
	UMDGameNotifier * notifier = Cast<UMDGameNotifier>(UGameSingleton::GetGameSingleton()->GetInstance(UMDGameNotifier::StaticClass()));
	if (notifier != nullptr)
	{
		notifier->AddListener(this);
	}
}

void AInputResultText::BeginDestroy()
{
	Super::BeginDestroy();

	UMDGameNotifier * notifier = Cast<UMDGameNotifier>(UGameSingleton::GetGameSingleton()->GetInstance(UMDGameNotifier::StaticClass()));
	if (notifier != nullptr)
	{
		notifier->RemoveListener(this);
	}
}

void AInputResultText::UpdateSelf_Implementation(const FGameNotifyData & notifyData)
{
	UE_LOG(LogTemp, Warning, TEXT("AInputResultText::updateSelf"));

	if (notifyData.ID == (int)E_BTN_INPUT)
	{
		AInputBtnActor * btn = Cast<AInputBtnActor>(notifyData.Data);
		if (btn != nullptr)
		{
			handleInput(btn->GetBtnType(), *btn->GetText());
		}
	}
}

void AInputResultText::handleInput(INPUT_BTN_TYPE inputType, FString value)
{
	UE_LOG(LogTemp, Warning, TEXT("GameNotifier::E_BTN_INPUT %s"), *value);

	if (inputType == NUMBER)
	{
		int num = FCString::Atoi(*value);
		_number = _number * 10 + num;
	}
	else if (inputType == CANCEL)
	{
		_number = _number / 10;
	}
	else
	{
		UMDGameNotifier * notifier = Cast<UMDGameNotifier>(UGameSingleton::GetGameSingleton()->GetInstance(UMDGameNotifier::StaticClass()));
		FGameNotifyData notifyData;
		notifyData.ID = (int)E_START_TO_CHECK_RESULT;
		notifyData.Data = this;
	
		notifier->NotifyListeners(notifyData);

		_number = 0;
	}

	ResultText->SetText(FText::FromString(FString::FromInt(_number)));
}

int AInputResultText::GetNumber()
{
	return _number;
}