// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HomeWork_Actor.generated.h"

UCLASS()
class TPS_API AHomeWork_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHomeWork_Actor();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 0, ClampMax = 100), Category = "MyCategory")
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "MyCategory")
	float Stamina;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "MyCategory")
	int32 Level;

	UFUNCTION(BlueprintCallable)
	inline float GetHealth() 
	{
		return Health;
	}

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxTraceDistance = 500.0f;

	UPROPERTY()
	FTimerHandle TraceTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetTraceLocation() const;

	UFUNCTION(BlueprintImplementableEvent)
	void NotifyActor(AActor* Actor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool TraceForPhysicsBody(AActor*& HitActor, UPrimitiveComponent*& HitComponent);

	void OnTimerTick();


private:	
	// Called every frame
	
};
