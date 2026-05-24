// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/TPSAIController.h"
#include "Player/TPSBaseCharacter.h"

ATPSAIController::ATPSAIController()
{
}

void ATPSAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATPSAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (auto lPosssessedCharacter = Cast<ATPSBaseCharacter>(InPawn))
	{
		RunBehaviorTree(lPosssessedCharacter->BehaviorTreeAsset);
	}
}
