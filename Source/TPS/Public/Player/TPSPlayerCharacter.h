// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/TPSBaseCharacter.h"
#include "EnhancedInput/Public/InputActionValue.h"
#include "EnhancedInput/Public/InputAction.h"

#include "TPSPlayerCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
//class UInputAction;
//struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogPlayerCharacter, Log, All);


UCLASS()
class TPS_API ATPSPlayerCharacter : public ATPSBaseCharacter
{
	GENERATED_BODY()
	
	/*METHODS*/

public:
	ATPSPlayerCharacter();

protected:
	virtual void BeginPlay() override;

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Zoom(bool bIsZooming);


private:

	/*PROPERTIES*/

public:

protected:

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category = "TPS|Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category = "TPS|Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category = "TPS|Input")
	UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category = "TPS|Input")
	UInputAction* MouseLookAction;

	/** Mouse Zoom Input Action */
	UPROPERTY(EditAnywhere, Category = "TPS|Input")
	UInputAction* ZoomAction;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

private:

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TPS|Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TPS|Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

};
