// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TPSWeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPS_API UTPSWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

	/*METHODS*/
public:	
	// Sets default values for this component's properties
	UTPSWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	// Called every frame

	/*PROPERTIES*/

public:


protected:


private:

		
};
