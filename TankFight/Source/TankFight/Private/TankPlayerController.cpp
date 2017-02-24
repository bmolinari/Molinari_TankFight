// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankFight.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MyTank = GetControlledTank();
	if (MyTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s Begin Play"), *MyTank->GetName());

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank is missing!"))
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }


	FVector HitLocation = FVector(0);
	FString ObjectHit = "";
	if (GetSightRayHitLocation(ObjectHit, HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
		//UE_LOG(LogTemp, Warning, TEXT("Object Hit: %s || Hit Location: %s"), *ObjectHit, *HitLocation.ToString());

	}


	//if (GetSightRayHitLocation(HitLocation))
	//{
	//	//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
	//}
	// Get World location of linetrace through crosshair
	// If it hits landscape
		// Tell controlled tank to aim at this point

}

// Get world location of ray trace through the crosshair, and returns true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FString& ObjectHit, FVector& HitLocation) const
{
	// Find Crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	bool bHit;
	FVector2D CrosshairPosition = FVector2D(ViewportSizeX / 2, ViewportSizeY / 3);
	FHitResult HitResult;

	bHit = GetHitResultAtScreenPosition(CrosshairPosition, ECollisionChannel::ECC_WorldStatic, false, HitResult);

	if (bHit)
	{
		HitLocation = HitResult.ImpactPoint;
		ObjectHit = HitResult.GetActor()->GetName();
	}

	DrawDebugLine(GetWorld(), HitResult.TraceStart, HitResult.TraceEnd, FColor::Red);

	return bHit;
	//auto ScreenLocation = FVector2D((ViewportSizeX * CrossHairXLocation), (ViewportSizeY * CrossHairYLocation));

	//// De-Project screen position of the crosshair to world direction
	//FVector LookDirection;
	//if (GetLookDirection(ScreenLocation, LookDirection))
	//{
	//	//UE_LOG(LogTemp, Warning, TEXT("World Location: %s"), *LookDirection.ToString());
	//	GetLookVectorHitLocation(ScreenLocation, HitLocation);
	//}


	//return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector2D LookDirection, FVector& HitLocation) const
{
	/*FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetLoca
	GetWorld()->LineTraceSingleByChannel(HitResult, LookDirection, HitLocation, ECC_Visibility,);*/
	return false;
}
