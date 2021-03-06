// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find player/ player tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found player/Player Tank %s"), *PlayerTank->GetName())
	}
}

ATank * ATankAIController::GetPossedTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerReference = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerReference)
		return PlayerReference;
	else
		return nullptr;
}
