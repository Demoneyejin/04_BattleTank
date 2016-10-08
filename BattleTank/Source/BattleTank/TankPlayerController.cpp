// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay(); //Calls parent
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"))

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Was not able to find the tank"))

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found tank player %s"), *ControlledTank->GetName())
	}

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


