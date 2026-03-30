// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/TPSWeaponComponent.h"
#include "Components/TPSHealthComponent.h"

#include "TPSBaseCharacter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogBaseCharacter, Log, All);


UCLASS()
class TPS_API ATPSBaseCharacter : public ACharacter
{
	GENERATED_BODY()

	/*METHODS*/
public:
	// Sets default values for this character's properties
	ATPSBaseCharacter();

	//virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	/*PROPERTIES*/

public:


protected:

	UPROPERTY(EditDefaultsOnly)
	UTPSWeaponComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly)
	UTPSHealthComponent* HealthComponent;

private:

};
