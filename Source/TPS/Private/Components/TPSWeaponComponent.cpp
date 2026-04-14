

#include "Components/TPSWeaponComponent.h"
#include "Weapons/TPSBaseWeaponGame.h"

DEFINE_LOG_CATEGORY_STATIC(LogTPSWeaponComponent, All, All)


UTPSWeaponComponent::UTPSWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UTPSWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UTPSWeaponComponent::InitWeaponComponent()
{
	/*Owner = Cast<ATPSBaseCharacter>(GetOwner());
	if (!Owner)
	{
		UE_LOG(LogTPSWeaponComponent, Error, TEXT("WeaponComponent -> Owner not valid"));
		return;
	}
	*/
	SpawnWeapon();

	EquipWeapon();

}

void UTPSWeaponComponent::StartFire()
{
	if (CurrentWeapon)
	{
		return;
	}
	CurrentWeapon->StartFire();
}

void UTPSWeaponComponent::StopFire()
{
	if (CurrentWeapon)
	{
		return;
	}
	CurrentWeapon->StopFire();
}

void UTPSWeaponComponent::Reload()
{
	if (CurrentWeapon)
	{
		return;
	}
	CurrentWeapon->Reload();
}

void UTPSWeaponComponent::NextWeapon()
{
}


void UTPSWeaponComponent::EquipWeapon()
{
}

void UTPSWeaponComponent::AttachWeaponToSocket()
{
}

void UTPSWeaponComponent::SpawnWeapon()
{
}



