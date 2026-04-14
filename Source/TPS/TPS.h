
#pragma once

#include "CoreMinimal.h"
#include "TPS.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTPS, Log, All);


/* Health Delegates */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, float, Health, float, HealthDelta);

USTRUCT(BlueprintType)
struct FRestStats
{
	GENERATED_BODY()

public:

};