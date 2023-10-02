// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"

#include "Components/StaticMeshComponent.h"

#include "ADFlak.generated.h"

UCLASS()
class AIRDEFENCE_API AADFlak : public APawn
{
	GENERATED_BODY()

public:
	AADFlak();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere, Category = "Meshes")
	UStaticMeshComponent* BarrelStaticMesh;

	UPROPERTY(EditAnywhere, Category = "Meshes")
	UStaticMeshComponent* FlakFoundationStaticMesh;
 
protected:
	//BP-callable functions

	UFUNCTION(Exec)
	void SetRotation(float vertical_angle, float horizontal_angle);

protected:
	// BP-properties
protected:
	// BeginPlay, EndPlay, Tick
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	void SetFlakLocation(FVector NewLocation);
	
	FRotator GetBarrelRotation();
	void SetBarrelRotation(FRotator NewRotation);
	void SetBarrelLocation(FVector& NewLocation);
};
