// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldPosition.h"

UWorldPosition::UWorldPosition()
{
	PrimaryComponentTick.bCanEverTick = true;

	UE_LOG(LogTemp, Display, TEXT("UE LOG"));
	UE_LOG(LogTemp, Error, TEXT("Hello"));
	UE_LOG(LogTemp, Warning, TEXT("World"));
}

void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();
}

void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
