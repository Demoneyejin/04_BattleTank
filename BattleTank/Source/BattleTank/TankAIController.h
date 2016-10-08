// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:

	//Our custom begin play
	virtual void BeginPlay() override;

	//Returns the tank we posses.
	ATank* GetPossedTank() const;
	
	//Returns the tank the player posses.
	ATank* GetPlayerTank() const;
	
};
