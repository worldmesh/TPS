// Fill out your copyright notice in the Description page of Project Settings.


#include "HomwWork/HomeWork_Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"
//#include "Math/UnrealMath.h"

/*
#include "Engine/World.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
*/


DEFINE_LOG_CATEGORY_STATIC(LogHWActor, All, All);


// Sets default values
AHomeWork_Actor::AHomeWork_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogHWActor, Warning, /*Message, Error, Log*/ TEXT("Constructor HWActor"));
}

// Called when the game starts or when spawned
void AHomeWork_Actor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogHWActor, Warning, TEXT("BeginPlay HWActor"));

	NotifyActor(this);

	GetWorldTimerManager().SetTimer(TraceTimerHandle, this, &AHomeWork_Actor::OnTimerTick, 0.003f, true);
	
}

void AHomeWork_Actor::OnTimerTick()
{
	AActor* HitActor = nullptr;
	UPrimitiveComponent* HitComponent = nullptr;
	TraceForPhysicsBody(HitActor, HitComponent);
}

// GetTraceLocationFunction
FVector AHomeWork_Actor::GetTraceLocation() const
{
	return GetActorLocation() + GetActorRotation().Vector() * MaxTraceDistance;
}

bool AHomeWork_Actor::TraceForPhysicsBody_Implementation(AActor*& HitActor, UPrimitiveComponent*& HitComponent)
{
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Red, TEXT("TraceForPhysicsBody ia called"));
	return false;
}

// Called every frame
void AHomeWork_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogHWActor, Warning, TEXT("Tick HWActor"));

}

