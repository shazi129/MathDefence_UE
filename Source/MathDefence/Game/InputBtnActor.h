// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputBtnActor.generated.h"

UENUM()
enum  INPUT_BTN_TYPE
{
	NUMBER,
	CONFIRM,
	CANCEL,
};

UCLASS()
class MATHDEFENCE_API AInputBtnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInputBtnActor();

	UFUNCTION(BlueprintCallable)
		void OnInputBtnClick(UPrimitiveComponent * primitiveComponent, FKey fKey);

	UFUNCTION(BlueprintCallable)
		void SetType(INPUT_BTN_TYPE btnType);

	UFUNCTION(BlueprintCallable)
		void SetText(FString text);

	FString GetText();
	INPUT_BTN_TYPE GetBtnType();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere)
		TEnumAsByte<INPUT_BTN_TYPE> BtnType;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		USceneComponent * InputBtnRoot;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		UBoxComponent * CollisionBox;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		UTextRenderComponent * BtnText;

};
