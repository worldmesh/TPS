

#include "Weapons/TPSBaseWeaponGame.h"

DEFINE_LOG_CATEGORY_STATIC( LogTPSBaseWeapon, All, All)


ATPSBaseWeaponGame::ATPSBaseWeaponGame()
{
	PrimaryActorTick.bCanEverTick = false;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>( "Weapon Mesh" );
	SetRootComponent(WeaponMesh);

}

void ATPSBaseWeaponGame::BeginPlay()
{
	Super::BeginPlay();
	check(WeaponMesh);

}

void ATPSBaseWeaponGame::StartFire()
{
	GetWorldTimerManager().SetTimer(ShotTimerHandle, this, &ATPSBaseWeaponGame::MakeShot, TimeBetweenShots, true, -1.0f);
}

void ATPSBaseWeaponGame::StopFire()
{
	if (!IsValid(this))
		return;
	if (ShotTimerHandle.IsValid())
	{
		GetWorldTimerManager().ClearTimer(ShotTimerHandle);
	}
}
void ATPSBaseWeaponGame::Reload()
{
}

bool ATPSBaseWeaponGame::IsCanReload() const
{
	return false;
}

void ATPSBaseWeaponGame::DecreaseAmmo()
{
}

bool ATPSBaseWeaponGame::IsClipEmpty() const
{
	return false;
}

void ATPSBaseWeaponGame::MakeShot()
{
	UE_LOG(LogTPSBaseWeapon, Warning, TEXT("Bam-bam"));
}

