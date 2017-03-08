// Fill out your copyright notice in the Description page of Project Settings.

#include "TankFight.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackValue, UTankTrack* RightTrackValue)
{
	if (!LeftTrackValue || !RightTrackValue) { return; }

	LeftTrack = LeftTrackValue;
	RightTrack = RightTrackValue;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}