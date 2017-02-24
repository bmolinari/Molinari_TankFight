// Fill out your copyright notice in the Description page of Project Settings.
#include "TankFight.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto MyTank = GetControlledTank();
	if (MyTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is reporting for duty, and is alive."), *MyTank->GetName());

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Tank Controller is missing!"));
	}

	auto PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank: %s was found."), *PlayerTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player Tank: was not found."))
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank)
	{
		return nullptr;
	}

	return PlayerTank;
}

