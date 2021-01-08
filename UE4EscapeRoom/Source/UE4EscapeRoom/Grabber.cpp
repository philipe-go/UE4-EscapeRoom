// Copyright by Phil Go.

#include "Grabber.h"
#include "Components/SceneComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	SetupPhysicsHandle();
	SetupInput();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//If player has grabbed an object
	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(GrabberReach());
	}
}

/**
 * @brief Use Line Trace to check which objects are being interacted.
 * @return FHitResult Interactable detected
 */
FHitResult UGrabber::DetectObjects() const 
{
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		Hit,
		GetOwner()->GetActorLocation(),
		GrabberReach(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParams);

	return Hit;
}

/**
 * @brief 
 * Return the reach's line based on the player's location and rotation
 * @return FVector the reach vector (like hands location)
 */
FVector UGrabber::GrabberReach() const
{
	FVector LocationPlayerViewPoint;
	FRotator RotationPlayerViewPoint;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(LocationPlayerViewPoint, RotationPlayerViewPoint);
	return LocationPlayerViewPoint + (RotationPlayerViewPoint.Vector() * LineTraceReach);
}

/**
 * @brief Pickup physics objects detected on DetectObjects()
 * Binded to Input RIGHTMOUSE
 */
void UGrabber::Pickup()
{
	PickedObject = DetectObjects();
	UPrimitiveComponent* ComponentToPick = PickedObject.GetComponent();

	if (PickedObject.GetActor())
	{
		PhysicsHandle->GrabComponentAtLocation(ComponentToPick, NAME_None, GrabberReach());

#if WITH_EDITOR
		UE_LOG(LogTemp, Warning, TEXT("Picked up object: %s"), *PickedObject.GetActor()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No objects to pickup"));
#endif

	}
}

/**
 * @brief Drop interactable objects which where picked up
 * Binded to Input RIGHTMOUSE
 */
void UGrabber::Drop()
{
	if (PickedObject.GetActor())
	{
		PhysicsHandle->ReleaseComponent();
		
#if WITH_EDITOR
		UE_LOG(LogTemp, Warning, TEXT("Dropped up object: %s"), *PickedObject.GetActor()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No objects to drop"));
#endif

	}
}

/**
 * @brief 
 * Get PhysicsHandle Component and check if it is attached to the AActor
 */
void UGrabber::SetupPhysicsHandle()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

#if WITH_EDITOR
	if (!PhysicsHandle)
	{
		UE_LOG(LogTemp, Error, TEXT("PhysicsHandle component not found in %s"), *GetOwner()->GetName());
	}
#endif
}

/**
 * @brief Sets up the input binding to pickup/drop objects
 */
void UGrabber::SetupInput()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Pickup", IE_Pressed, this, &UGrabber::Pickup);
		InputComponent->BindAction("Pickup", IE_Released, this, &UGrabber::Drop);
	}

#if WITH_EDITOR
	if (!InputComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("Input component not found in %s"), *GetOwner()->GetName());
	}
#endif
}


