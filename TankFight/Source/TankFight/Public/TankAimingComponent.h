// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward Declaration
class UTankBarrel;
class UTankTurret;

// Hold Barrel Properties and Functions
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKFIGHT_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void SetBarrelReference(UTankBarrel* Value);
	void SetTurretReference(UTankTurret* Value);

	// TODO SetTurret

	void AimAt(FVector, float);

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector);
	void MoveTurretTowards(FVector);
};
