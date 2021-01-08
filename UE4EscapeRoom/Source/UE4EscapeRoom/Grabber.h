// Copyright by Phil Go.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4ESCAPEROOM_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	// Called every frame update
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	//### Pickup Objects handling ###
	//Linetracing to detect objects
	UPROPERTY(EditAnywhere)
	float LineTraceReach = 120.f;
	FHitResult DetectObjects() const;
	FVector GrabberReach() const;
	
	//Attach & Drop picked object
	void Pickup();
	void Drop();

	//returns the actor to be pickedup
	FHitResult PickedObject;

	class UPhysicsHandleComponent* PhysicsHandle = nullptr;
	void SetupPhysicsHandle();
	class UInputComponent* InputComponent = nullptr;
	void SetupInput();
};
