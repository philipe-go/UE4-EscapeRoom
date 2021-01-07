// Copyright by Phil Go.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

UOpenDoor::UOpenDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	InitialRotation = GetOwner()->GetActorRotation(); 
	OpenYaw = InitialRotation.Yaw - 80.f;
}

void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// GetOwner()->SetActorRelativeRotation(FMath::Lerp(GetOwner()->GetActorRotation(), OpenYaw, 0.05f));
	float targetYaw = FMath::FInterpTo(GetOwner()->GetActorRotation().Yaw, OpenYaw, DeltaTime, 2);
	GetOwner()->SetActorRelativeRotation(FRotator(InitialRotation.Pitch, targetYaw, InitialRotation.Roll));

}
