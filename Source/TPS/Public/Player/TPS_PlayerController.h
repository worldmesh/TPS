// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TPS_PlayerController.generated.h"


class UInputMappingContext;
/**
 * 
 */
UCLASS()
class TPS_API ATPS_PlayerController : public APlayerController
{
	GENERATED_BODY()

	/*METHODS*/

public:
protected:
	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;
private:

	/*PROPERTIES*/

public:
protected:

	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;


private:
	
};
