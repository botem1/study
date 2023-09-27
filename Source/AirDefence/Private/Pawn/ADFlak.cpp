// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawn/ADFlak.h"

DEFINE_LOG_CATEGORY_STATIC(LogADFlak, All, All);

AADFlak::AADFlak()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AADFlak::BeginPlay()
{
	Super::BeginPlay();
}

void AADFlak::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AADFlak::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("PrintingHello", IE_Pressed, this, &AADFlak::PrintingHello);
}

void AADFlak::PrintingHello()
{
	UE_LOG(LogADFlak, Warning, TEXT("Hi!"));
}
