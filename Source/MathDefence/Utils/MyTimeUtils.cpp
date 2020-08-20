// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTimeUtils.h"

int UMyTimeUtils::Now()
{
	return FDateTime::Now().ToUnixTimestamp();
}