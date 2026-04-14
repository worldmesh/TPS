// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TPS.h"
#include "TPSHealthComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTPSHealthComponent, All, All)


class UDamageType;
class AController;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPS_API UTPSHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	/*METHODS*/
public:	
	
	UTPSHealthComponent();

	UFUNCTION()
	void InitHealthComponent();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
	void GetDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION()
	void SetHealth(float newHealth);

	UFUNCTION()
	FORCEINLINE float GetHealth() const
	{
		return Health;
	}

	UFUNCTION()
	bool IsDead()
	{
		return FMath::IsNearlyZero(Health);
	}


private:

	/*PROPERTIES*/
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxHealth = 100.0f;

	FOnDeathSignature OnDeath;

	FOnHealthChangedSignature OnHealthChanged;

protected:
	

private:

	UPROPERTY()
	float Health = 0.0f;
};
