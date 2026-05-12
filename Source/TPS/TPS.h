
#pragma once

#include "CoreMinimal.h"
#include "TPS.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTPS, Log, All);


/* Health Delegates */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, Health, float, HealthDelta);


// AmmoData
USTRUCT(BlueprintType)
struct FAmmoData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TPS|Weapons")
	int32 Bullets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TPS|Weapons")
	int32 Clips;
};