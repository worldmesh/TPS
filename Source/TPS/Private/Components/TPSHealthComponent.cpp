// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TPSHealthComponent.h"


DEFINE_LOG_CATEGORY( LogTPSHealthComponent )



UTPSHealthComponent::UTPSHealthComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UTPSHealthComponent::BeginPlay()
{
	Super::BeginPlay();


	
}

void UTPSHealthComponent::GetDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f || IsDead())
	{
		return;
	}

	float lNewHealth = Health - Damage;

	UE_LOG(LogTPSHealthComponent, Warning, TEXT("Actor get %f damage. Current health is %f"), Damage, lNewHealth);

	SetHealth(lNewHealth);

	if (IsDead())
	{
		OnDeath.Broadcast();
		UE_LOG(LogTPSHealthComponent, Warning, TEXT("Actor is dead!"));
	}
}

void UTPSHealthComponent::SetHealth(float newHealth)
{
	float lUpdatehealth = FMath::Clamp(newHealth, 0.0f, MaxHealth);
	float lHealthDelta = lUpdatehealth - Health;

	Health = lUpdatehealth;

	OnHealthChanged.Broadcast(Health, lHealthDelta);

}

void UTPSHealthComponent::InitHealthComponent()
{
	AActor* lOwner = GetOwner();

	if (lOwner)
	{
		lOwner->OnTakeAnyDamage.AddDynamic(this, &UTPSHealthComponent::GetDamage);
		SetHealth(MaxHealth);
		UE_LOG(LogTPSHealthComponent, Warning, TEXT("Actor HealthComponent was successful initialized!"));
	}

}

