
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TPSBaseWeaponGame.generated.h"


UCLASS()
class TPS_API ATPSBaseWeaponGame : public AActor
{
	GENERATED_BODY()
	
	/*METHODS*/

public:	
	ATPSBaseWeaponGame();

	void StartFire();
	void StopFire();
	void Reload();
	bool IsCanReload() const;
	void DecreaseAmmo();
	bool IsClipEmpty() const;
	void MakeShot();


protected:
	virtual void BeginPlay() override;

	/*PROPERTIES*/

public:
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TPS|Component")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TPS|Weapon")
	float TimeBetweenShots = 0.3f;

private:
};
