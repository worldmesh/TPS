

#include "Components/TPSWeaponComponent.h"
#include "Weapons/TPSBaseWeaponGame.h"
#include "Player/TPSBaseCharacter.h"

DEFINE_LOG_CATEGORY_STATIC(LogTPSWeaponComponent, All, All)


UTPSWeaponComponent::UTPSWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentWeapon = nullptr;
	CurrentWeaponIndex = -1;
	WeaponSocketName = TEXT("HandGrip_R");
	WeaponArmorySocketName = TEXT("WeaponArmorySocket");
}

void UTPSWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UTPSWeaponComponent::InitWeaponComponent()
{
	Owner = Cast<ATPSBaseCharacter>(GetOwner());
	if (!Owner)
	{
		UE_LOG(LogTPSWeaponComponent, Error, TEXT("WeaponComponent -> Owner not valid"));
		return;
	}
	
	SpawnWeapon();
	if (!Weapons.IsEmpty())
	{
		EquipWeapon(0);
		CurrentWeaponIndex = 0;
	}
	else
	{
		UE_LOG(LogTPSWeaponComponent, Warning, TEXT("No weapons to equip!"));
	}

	EquipWeapon(CurrentWeaponIndex);

}

void UTPSWeaponComponent::StartFire()
{
	if (!CurrentWeapon)
	{
		return;
		//CurrentWeapon->StartFire();
	}
	CurrentWeapon->StartFire();
}

void UTPSWeaponComponent::StopFire()
{
	if (!CurrentWeapon)
	{
		return;
		//CurrentWeapon->StopFire();
	}
	CurrentWeapon->StopFire();
}

void UTPSWeaponComponent::Reload()
{
	if (!CurrentWeapon)
	{
		//CurrentWeapon->Reload();
		return;
	}
	CurrentWeapon->Reload();
}

void UTPSWeaponComponent::NextWeapon()
{
	if (Weapons.IsEmpty())
		return;

	CurrentWeaponIndex = (CurrentWeaponIndex + 1) % Weapons.Num();
	EquipWeapon(CurrentWeaponIndex);

}


void UTPSWeaponComponent::EquipWeapon(int32 WeaponIndex)
{
	if (Weapons.IsEmpty() || !Weapons.IsValidIndex(WeaponIndex))
	{
		//UE_LOG(LogTPSWeaponComponent, Warning, TEXT("Invalid weapon index: %d"), WeaponIndex);
		return;
	}

	//UE_LOG(LogTPSWeaponComponent, Log, TEXT("Equipping weapon %d: %s"), WeaponIndex, *lNewWeapon->GetName());


	ATPSBaseWeaponGame* lNewWeapon = Weapons[WeaponIndex];
	if (!IsValid(lNewWeapon))
		return;

	if (IsValid(CurrentWeapon) && CurrentWeapon != lNewWeapon)
	{
		CurrentWeapon->StopFire();
		AttachWeaponToSocket(CurrentWeapon, WeaponArmorySocketName);

	}

	CurrentWeapon = lNewWeapon;
	AttachWeaponToSocket(CurrentWeapon, WeaponSocketName);
	CurrentWeaponIndex = WeaponIndex;
}

void UTPSWeaponComponent::AttachWeaponToSocket(ATPSBaseWeaponGame* WeaponToEquip, FName SocketName)
{
	auto lCharMesh = Owner->GetMesh();

	if (!lCharMesh || !WeaponToEquip)
	{
		UE_LOG(LogTPSWeaponComponent, Error, TEXT("Failed to attach weapon: mesh or weapon is invalid"));
		return;
	}

	UE_LOG(LogTPSWeaponComponent, Display, TEXT("Attaching weapon %s to socket %s"),
		*WeaponToEquip->GetName(), *SocketName.ToString());

	FAttachmentTransformRules lAttachmentRules(EAttachmentRule::SnapToTarget, true);
	WeaponToEquip->AttachToComponent(lCharMesh, lAttachmentRules, SocketName);
}

void UTPSWeaponComponent::SpawnWeapon()
{
	if (!GetWorld()) return;

	for (auto lWeaponClass : WeaponClasses)
	{
		if (!lWeaponClass) continue;

		ATPSBaseWeaponGame* ISpawnedWeapon = GetWorld()->SpawnActor<ATPSBaseWeaponGame>(lWeaponClass);
		if (!ISpawnedWeapon) continue;

		ISpawnedWeapon->SetOwner(Owner);
		AttachWeaponToSocket(ISpawnedWeapon, WeaponArmorySocketName);
		Weapons.Add(ISpawnedWeapon);
	}
		
}



