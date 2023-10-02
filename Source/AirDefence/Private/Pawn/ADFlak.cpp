// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawn/ADFlak.h"

DEFINE_LOG_CATEGORY_STATIC(LogADFlak, All, All);

AADFlak::AADFlak()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = Root;
	
	BarrelStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Barrel"));

	FlakFoundationStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FlakFoundation"));
}

void AADFlak::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AADFlak::SetRotation(float vertical_angle, float horizontal_angle)
{
	SetBarrelRotation(FRotator(vertical_angle, horizontal_angle, 0));
}

void AADFlak::BeginPlay()
{
	Super::BeginPlay();

	FVector DefaultLocation(0, 0, 0);
	SetFlakLocation(DefaultLocation);
	
	BarrelStaticMesh->SetRelativeLocation(FVector(0, 0, 100));
}

void AADFlak::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AADFlak::SetFlakLocation(FVector NewLocation)
{
	Root->SetWorldLocation(NewLocation);
}


FRotator AADFlak::GetBarrelRotation()
{
	return BarrelStaticMesh->GetComponentRotation();
}

void AADFlak::SetBarrelRotation(FRotator NewRotation)
{
	if(NewRotation.Pitch > 90) NewRotation.Pitch = 90;
	if(NewRotation.Pitch < -90) NewRotation.Pitch = -90;

	NewRotation.Roll = 0;
	
	BarrelStaticMesh->SetRelativeRotation(NewRotation);
}

void AADFlak::SetBarrelLocation(FVector& NewLocation)
{
	BarrelStaticMesh->SetRelativeLocation(NewLocation);
}




