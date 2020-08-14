// Fill out your copyright notice in the Description page of Project Settings.


#include "InputResultText.h"
#include "./../GameSystem/GameNotifier.h"

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

	GameNotifier::getInstance()->addObserver(this);
}

void AInputResultText::BeginDestroy()
{
	Super::BeginDestroy();
	GameNotifier::getInstance()->removeObserver(this);
}

void AInputResultText::updateSelf(void* data)
{
	UE_LOG(LogTemp, Warning, TEXT("AInputResultText::updateSelf"));
	if (data != nullptr)
	{
		ObserverParam * param = (ObserverParam *)data;
		if (param->id == (int)GameNotifier::E_BTN_INPUT)
		{
			AInputBtnActor * btn = (AInputBtnActor*)(param->updateData);
			if (btn != nullptr)
			{
				handleInput(btn->GetBtnType(), *btn->GetText());
			}
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
		_number = 0;
	}

	ResultText->SetText(FText::FromString(FString::FromInt(_number)));
}