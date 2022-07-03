// Fill out your copyright notice in the Description page of Project Settings.


#include "Hook.h"

// Sets default values for this component's properties
UHook::UHook()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHook::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHook::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHook::GetComponentAndBind()
{
}

void UHook::Grab()
{
}

void UHook::Release()
{
}

FHitResult UHook::GetPhysicsBodyInReach()
{
}

FVector UHook::GetReachStart()
{
}

FVector UHook::GetReachEnd()
{
}

