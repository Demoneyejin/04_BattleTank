// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:

	ATankPlayerController(); //lets set the tick to go

	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	//Start the tank moving the barrel towards where the shot will be used where the cursor is.
	void AimTowardsCrosshairs();

	bool LookDirection(FVector2D screenLocation, FVector &lookDirection) const;

	bool GetSightRayHitLocation(FVector& OUT hitLocation)const;
	
protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category ="Crosshair")
	float crosshairXLocation = 0.5;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Crosshair")
	float crosshairYLocation = 0.33333;
};
