// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class TANKFIGHT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float) override;

	ATank* GetControlledTank() const;
private:
	ATank* MyTank = nullptr;
	
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FString&, FVector& ) const;
	bool GetLookDirection(FVector2D, FVector& ) const;
	bool GetLookVectorHitLocation(FVector2D, FVector&) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
	float RayTraceRange = 10000;

	
};
