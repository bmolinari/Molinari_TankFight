// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class UTankTrack;
class AProjectile;

UCLASS()
class TANKFIGHT_API ATank : public APawn
{
	GENERATED_BODY()
public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* inputComponent) override;
	void AimAt(FVector);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* Value);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* Value);
	
	/*UFUNCTION(BlueprintCallable, Category = Setup)
	void SetRightTrackReference(UTankTrack* Value);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetLeftTrackReference(UTankTrack* Value);*/

	UFUNCTION(BlueprintCallable, Category = Action)
	void FireProjectile();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 8000; // TODO find sensible default

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> Projectile;
	//UClass* ProjectileBluePrint;

	UTankBarrel* Barrel = nullptr;
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
		
	
};
