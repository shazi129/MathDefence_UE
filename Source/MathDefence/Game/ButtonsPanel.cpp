// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/EngineTypes.h"
#include "ButtonsPanel.h"


// Sets default values
AButtonsPanel::AButtonsPanel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PanelRoot = CreateDefaultSubobject<USceneComponent>("root");
	RootComponent = PanelRoot;

	
}

// Called when the game starts or when spawned
void AButtonsPanel::BeginPlay()
{
	Super::BeginPlay();

	FRotator rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters spawnInfo;

	FVector panelLocation = GetActorLocation();

	int colNum = 4;
	int rowNum = 3;

	//按钮， 3行4列
	for (int i = 0; i < rowNum; i++)
	{
		for (int j = 0; j < colNum; j++)
		{
			FVector newLocation(0.0f, 10.0f, 0.0f);
			newLocation.X = (j - 1.5f) * ButtonWidth;
			newLocation.Z = (1 - i) * ButtonHeight;

			AInputBtnActor * btn = GetWorld()->SpawnActor<AInputBtnActor>(InputBtnClass, newLocation, rotation, spawnInfo);
			btn->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

			//1-9
			if (j < colNum - 1)
			{
				btn->SetType(NUMBER);
				btn->SetText(FString::FromInt(i * 3 + j + 1));
			}
			//最后一列
			else
			{
				if(i == 0)
				{
					btn->SetType(CANCEL);
					btn->SetText("C");
				}
				//确认键
				else if (i == 1)
				{
					btn->SetType(CONFIRM);
					btn->SetText("OK");
				}
				//0
				else if (i == 2)
				{
					btn->SetType(NUMBER);
					btn->SetText("0");
				}
			}
// 			FVector origin;
// 			FVector boxExtent;
// 			btn->GetActorBounds(false, origin, boxExtent);
// 
// 			UE_LOG(LogTemp, Warning, TEXT("origin(%f, %f, %f), boxExtent(%f, %f, %f)"), origin.X, origin.Y, origin.Z, boxExtent.X, boxExtent.Y, boxExtent.Z);
		}
	}
}

