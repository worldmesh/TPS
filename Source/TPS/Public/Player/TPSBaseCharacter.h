// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/TPSWeaponComponent.h"
#include "Components/TPSHealthComponent.h"
#include "BehaviorTree/BehaviorTree.h"

#include "TPSBaseCharacter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogBaseCharacter, Log, All);


UCLASS()
class TPS_API ATPSBaseCharacter : public ACharacter
{
	GENERATED_BODY()

	/*METHODS*/
public:
	ATPSBaseCharacter();

	UFUNCTION(BlueprintCallable)
	bool GetAimPoint(FHitResult& HitResult, FVector& OutPoint, float MaxDistance) const;


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnDeath();

	void HealthChanged(float Health, float HealthDelta);

private:

	/*PROPERTIES*/

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UBehaviorTree* BehaviorTreeAsset;

protected:

	UPROPERTY(EditDefaultsOnly)
	UTPSWeaponComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly)
	UTPSHealthComponent* HealthComponent;

private:

};
