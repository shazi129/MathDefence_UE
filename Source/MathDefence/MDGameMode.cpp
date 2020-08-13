// Fill out your copyright notice in the Description page of Project Settings.


#include "MDGameMode.h"

void AMDGameMode::handleBtnInput(INPUT_BTN_TYPE btnType, FText btnText)
{
	if (btnType == NUMBER)
	{
		int number = FCString::Atoi(*btnText.ToString());
		UE_LOG(LogTemp, Warning, TEXT("OnInputBtnClick: %d"), number);
	}
	else if (btnType == CONFIRM)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnInputBtnClick: ok btn"));
	}
	else if (btnType == CANCEL)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnInputBtnClick: cancel btn"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnInputBtnClick: invalid btn"));
	}
}