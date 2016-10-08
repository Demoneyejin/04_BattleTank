// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetPossedTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not grab AI Tank"))
	}
	else
	{
		UE_LOG(LogTemp,Warning, TEXT("Found AI Controlled Tank %s "), *AIControlledTank->GetName())
	}
}

ATank * ATankAIController::GetPossedTank() const
{
	return Cast<ATank>(GetPawn());
}
