// Copyright by Phil Go.

#include "Grabber.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DetectObjects();
}

/**
 * @brief Method to keed checking which objects are being intercated
 * It detects the objects through a Line tracing. 
 */
void UGrabber::DetectObjects()
{
	//The following parameters will be modified by the OUT in the GetPlayerViewPoint
	FVector LocationPlayerViewPoint;
	FRotator RotationPlayerViewPoint;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(LocationPlayerViewPoint, RotationPlayerViewPoint);

	FVector LineTraceEnd = LocationPlayerViewPoint + (RotationPlayerViewPoint.Vector() * LineTraceReach);

	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(
		Hit,
		LocationPlayerViewPoint,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams);

	#if WITH_EDITOR
		DrawDebugLine(GetWorld(), LocationPlayerViewPoint, LineTraceEnd, FColor::Orange, false, -1.f, 0.f, 1.f);
		if (Hit.GetActor())
		{
			UE_LOG(LogTemp, Warning, TEXT("Hit actor name: %s"), *Hit.GetActor()->GetName());
		}
	#endif
}
