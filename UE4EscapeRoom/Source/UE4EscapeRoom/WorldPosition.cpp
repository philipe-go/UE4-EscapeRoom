// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldPosition.h"

UWorldPosition::UWorldPosition()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();
}

void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
