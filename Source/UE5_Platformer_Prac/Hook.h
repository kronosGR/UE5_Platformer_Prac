// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Hook.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE5_PLATFORMER_PRAC_API UHook : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHook();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Read= 100.f;
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	void GetComponentAndBind();
	void Grab();
	void Release();

	FHitResult GetPhysicsBodyInReach();
	FVector GetReachStart();
	FVector GetReachEnd();
};
