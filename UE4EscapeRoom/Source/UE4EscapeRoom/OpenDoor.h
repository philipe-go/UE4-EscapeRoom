// Copyright by Phil Go.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4ESCAPEROOM_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	void AlterDoorState(const float& DeltaTime, const float& FinalYaw, float Speed) const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float OpenYaw = 90.f;
	FRotator InitialRotation;

	//Trigger to check puzzle and open door
	UPROPERTY(EditAnywhere)
	class ATriggerVolume* QueueTrigger;
	UPROPERTY(EditAnywhere)
	AActor* OpenActor;
};
