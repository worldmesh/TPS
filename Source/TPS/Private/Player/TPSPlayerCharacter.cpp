// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TPSPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "Components/TPSWeaponComponent.h"



DEFINE_LOG_CATEGORY(LogPlayerCharacter);

//
ATPSPlayerCharacter::ATPSPlayerCharacter()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 200.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void ATPSPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ATPSPlayerCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ATPSPlayerCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ATPSPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATPSPlayerCharacter::Move);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ATPSPlayerCharacter::Look);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATPSPlayerCharacter::Look);

		// Zooming
		EnhancedInputComponent->BindAction(ZoomAction, ETriggerEvent::Started, this, &ATPSPlayerCharacter::Zoom, true);
		EnhancedInputComponent->BindAction(ZoomAction, ETriggerEvent::Completed , this, &ATPSPlayerCharacter::Zoom, false);


		// Shooting
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Started, this, &ATPSPlayerCharacter::StartFire);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Completed, this, &ATPSPlayerCharacter::StopFire);
		
		//NextWeapon
		EnhancedInputComponent->BindAction(NextWeaponAction, ETriggerEvent::Started, this, &ATPSPlayerCharacter::NextWeapon);
	}
	else
	{
		UE_LOG(LogPlayerCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void ATPSPlayerCharacter::Zoom(bool bIsZooming)
{
	if (bIsZooming)
	{
		bUseControllerRotationYaw = true;
		FollowCamera->SetFieldOfView(60.0f);
	}
	else
	{
		bUseControllerRotationYaw = false;
		FollowCamera->SetFieldOfView(90.0f);
	}
}

void ATPSPlayerCharacter::StartFire()
{
	bUseControllerRotationYaw = true;
	WeaponComponent->StartFire();
}

void ATPSPlayerCharacter::StopFire()
{
	bUseControllerRotationYaw = false;
	WeaponComponent->StopFire();
}

void ATPSPlayerCharacter::NextWeapon()
{
	WeaponComponent->NextWeapon();
}