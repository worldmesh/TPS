// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TPSWeaponComponent.generated.h"


class ATPSBaseWeaponGame;
class ATPSBaseCharacter;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TPS_API UTPSWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

	/*METHODS*/
public:	
	UTPSWeaponComponent();

	UFUNCTION()
	void InitWeaponComponent();
	
	UFUNCTION()
	void StartFire();

	UFUNCTION()
	void StopFire();

	UFUNCTION()
	void Reload();

	UFUNCTION()
	void NextWeapon();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void EquipWeapon(int32 WeaponIndex);

	UFUNCTION()
	void AttachWeaponToSocket(ATPSBaseWeaponGame* WeaponToEquip, FName SocketName);

private:	

	UFUNCTION()
	void SpawnWeapon();


	/*PROPERTIES*/

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TPS|Weapons")
	ATPSBaseWeaponGame* CurrentWeapon = nullptr;

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ATPSBaseCharacter* Owner;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TPS|Weapons")
	TArray<TSubclassOf<ATPSBaseWeaponGame>> WeaponClasses;

	UPROPERTY(EditDefaultsOnly)
	FName WeaponArmorySocketName = "WeaponArmorySocket";
	
	UPROPERTY(EditDefaultsOnly)
	FName WeaponSocketName = "WeaponSocket";

	UPROPERTY(BlueprintReadOnly)
	TArray<ATPSBaseWeaponGame*> Weapons;

private:

	UPROPERTY()
	int32 CurrentWeaponIndex = 0;
		
};
