// Fill out your copyright notice in the Description page of Project Settings.


#include "Attacker.h"

// Sets default values
AAttacker::AAttacker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_number = 1;
}

void AAttacker::SetTextRender(UTextRenderComponent * textRender)
{
	_attackNumText = textRender;
}

void AAttacker::SetText(FString text)
{
	if (_attackNumText != nullptr)
	{
		_attackNumText->SetText(FText::FromString(text));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s::SetText:%s, num text is null"), *this->GetName(), *text);
	}
}

FString AAttacker::GetText()
{
	if (_attackNumText != nullptr)
	{
		return _attackNumText->Text.ToString();
	}
	return "";
}

void AAttacker::SetNumber(int number)
{
	_number = number;
}

void AAttacker::Print()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString::Printf(TEXT("%s = %d"), *GetText(), _number));
}

int AAttacker::GetNumber()
{
	return _number;
}

// Called when the game starts or when spawned
void AAttacker::BeginPlay()
{
	Super::BeginPlay();
	
}
