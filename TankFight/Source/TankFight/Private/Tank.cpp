// Fill out your copyright notice in the Description page of Project Settings.

#include "TankFight.h"
#include "TankBarrel.h"
#include "TankTrack.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* inputComponent)
{
	Super::SetupPlayerInputComponent(inputComponent);

}

void ATank::SetBarrelReference(UTankBarrel* Value)
{
	TankAimingComponent->SetBarrelReference(Value);
	Barrel = Value;
}

void ATank::SetTurretReference(UTankTurret* Value)
{
	TankAimingComponent->SetTurretReference(Value);
}

//void ATank::SetRightTrackReference(UTankTrack* Value);
//{
//	RightTrack = Value;
//}
//
//void ATank::SetLeftTrackReference(UTankTrack* Value);
//{
//	LeftTrack = Value;
//}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::FireProjectile()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && bIsReloaded)
	{

		auto SpawnedProjectile = GetWorld()->SpawnActor<AProjectile>(Projectile, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		SpawnedProjectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
		UE_LOG(LogTemp, Warning, TEXT("%d"), LastFireTime);

	}
}
