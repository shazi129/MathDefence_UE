// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "./InputBtnActor.h"
#include "./../GameSystem/GameListener.h"
#include "Components/TextRenderComponent.h"
#include "Components/SceneComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputResultText.generated.h"

UCLASS()
class MATHDEFENCE_API AInputResultText : public AActor, public IGameListener
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInputResultText();

public:
// 	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
// 		void UpdateSelf(const FGameNotifyData & notifyData);

	virtual void UpdateSelf_Implementation(const FGameNotifyData & notifyData);

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		USceneComponent * ResultRoot;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		UTextRenderComponent * ResultText;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

private:
	void handleInput(INPUT_BTN_TYPE inputType, FString value);

private:
	int _number; 
};
