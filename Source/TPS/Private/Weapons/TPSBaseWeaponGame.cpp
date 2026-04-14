

#include "Weapons/TPSBaseWeaponGame.h"

DEFINE_LOG_CATEGORY_STATIC( LogTPSBaseWeapon, All, All)


ATPSBaseWeaponGame::ATPSBaseWeaponGame()
{
	PrimaryActorTick.bCanEverTick = false;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>( "Weapon Mesh" );
	SetRootComponent(WeaponMesh);

}

void ATPSBaseWeaponGame::StartFire()
{
}

void ATPSBaseWeaponGame::StopFire()
{
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
}

void ATPSBaseWeaponGame::BeginPlay()
{
	Super::BeginPlay();
	
}

