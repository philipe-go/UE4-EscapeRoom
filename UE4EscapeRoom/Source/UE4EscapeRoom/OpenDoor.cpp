// Copyright by Phil Go.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


UOpenDoor::UOpenDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	InitialRotation = GetOwner()->GetActorRotation();
	OpenYaw += InitialRotation.Yaw;

	if (!QueueTrigger)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has an open door component without anything assigned to it."), *GetOwner()->GetName());
	}

	OpenActor = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (QueueTrigger && QueueTrigger->IsOverlappingActor(OpenActor))
	{
		AlterDoorState(DeltaTime, OpenYaw, .5f); //Open Door
	}
	else
	{
		AlterDoorState(DeltaTime, InitialRotation.Yaw, 2.f); //Close Door
	}
}

/**
 * @brief 
 * Alter the state of the door to Open or Closed. Using DeltaTime and SetRotation
 * @param DeltaTime 
 * @param FinalYaw 
 */
void UOpenDoor::AlterDoorState(const float &DeltaTime, const float& FinalYaw, float Speed) const
{
	float targetYaw = FMath::FInterpTo(GetOwner()->GetActorRotation().Yaw, FinalYaw, DeltaTime, Speed);
	GetOwner()->SetActorRelativeRotation(FRotator(InitialRotation.Pitch, targetYaw, InitialRotation.Roll));
}