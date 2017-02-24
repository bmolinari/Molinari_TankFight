// Fill out your copyright notice in the Description page of Project Settings.

#include "TankFight.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	//auto Elevation = FMath::Clamp<float>(RawNewRotation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
	//UE_LOG(LogTemp, Warning, TEXT("Moving Turret!"));

}


