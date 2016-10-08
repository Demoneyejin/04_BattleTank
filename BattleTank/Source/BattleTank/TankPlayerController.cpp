// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


ATankPlayerController::ATankPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

}

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



void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshairs();
	
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshairs()
{
	//exit if we're not controlling anything
	if (!GetControlledTank())
	{
		return;
	}

	//We're going to utilize out parameters utilizing the OUT macro.
OUT	FVector hitLocation = FVector::ZeroVector;

	if (GetSightRayHitLocation(hitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Our hitlocation %s"), *hitLocation.ToString())
		
	}

	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OUT hitLocation) const
{
	//Find the crosshair position
		//Our viewport size in x and y
OUT	int32 viewportSizeX, viewportSizeY;
	GetViewportSize(viewportSizeX, viewportSizeY);

	FVector2D screenLocation = FVector2D(viewportSizeX * crosshairXLocation, viewportSizeY * crosshairYLocation);

	FVector lookDirection = FVector::ZeroVector;
	if (LookDirection(screenLocation, lookDirection))
	{
		//do something
		UE_LOG(LogTemp, Warning, TEXT("The World direction is: %s"), *lookDirection.ToString())
	}

	
	//line trace along that direction(look direction)
	FHitResult traceHit;
	//GetWorld()->LineTraceSingleByChannel(traceHit, worldLocation, worldDirection, ECollisionChannel::ECC_Camera);


	return false;
}

bool ATankPlayerController::LookDirection(FVector2D screenLocation, FVector & lookDirection) const
{
	FVector worldLocation; //to be discarded.
	//Deproject  the screen position of the cross hair  to a world direction
	return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, worldLocation, lookDirection);
	
}
