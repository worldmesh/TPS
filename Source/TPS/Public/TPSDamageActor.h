
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TPSDamageActor.generated.h"

UCLASS()
class TPS_API ATPSDamageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATPSDamageActor();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Radius = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Segments = 16.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDoFullDamage = false;
};
