

#include "TPSDamageActor.h"
#include "Kismet/GameplayStatics.h"

ATPSDamageActor::ATPSDamageActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATPSDamageActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATPSDamageActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), Radius, Segments, FColor::Red);
	UGameplayStatics::ApplyRadialDamage(GetWorld(), Damage, GetActorLocation(), Radius, DamageType, {}, this, nullptr, bDoFullDamage, ECollisionChannel::ECC_Visibility);

}

