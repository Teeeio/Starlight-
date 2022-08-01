// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include"D:\Epic Games\UE_4.27\Engine\Source\Runtime\Engine\Classes\Camera\CameraComponent.h"
#include"D:\Epic Games\UE_4.27\Engine\Source\Runtime\Engine\Classes\GameFramework\SpringArmComponent.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	SpringComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("MySpring"));
	SpringComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("MyCamera"));
	CameraComp->SetupAttachment(SpringComp);

}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void ASCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(),value);
}

void ASCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

// Called every frame	
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);

	PlayerInputComponent->BindAxis("MoveRight",this,&ASCharacter::MoveRight);

	PlayerInputComponent->BindAxis("TurnYaw", this, &APawn::AddControllerYawInput);

	PlayerInputComponent->BindAxis("TurnRoll", this, &APawn::AddControllerRollInput);

}

