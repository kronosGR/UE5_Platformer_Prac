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
	GetComponentAndBind();
}


// Called every frame
void UHook::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(GetReachEnd());
	}
}

void UHook::GetComponentAndBind()
{
	// get them from the root element/parent component
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	// bind actions to methods
	InputComponent->BindAction("Grab", IE_Pressed, this, &UHook::Grab);
	InputComponent->BindAction("Grab", IE_Released, this, &UHook::Release);
}

void UHook::Grab()
{
	FHitResult HitResult = GetPhysicsBodyInReach();
	auto GrabComponent = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

	if (ActorHit)
	{
		PhysicsHandle->GrabComponentAtLocation(GrabComponent,NAME_None,GrabComponent->GetOwner()->GetActorLocation());
	}
}

void UHook::Release()
{
	PhysicsHandle->ReleaseComponent();
}


FHitResult UHook::GetPhysicsBodyInReach()
{
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	FHitResult HitResult;

	GetWorld()->LineTraceSingleByObjectType(
		HitResult,
		GetReachStart(),
		GetReachEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters		
	);
	
	return HitResult;
}

FVector UHook::GetReachStart()
{
	FVector PlayerViewPoint;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		PlayerViewPoint,
		PlayerViewPointRotation);
	
	return FVector();
}

FVector UHook::GetReachEnd()
{
	FVector PlayerViewPoint;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		PlayerViewPoint,
		PlayerViewPointRotation);
	
	FVector LineTraceEnd = PlayerViewPoint + PlayerViewPointRotation.Vector() * Reach;
	return FVector();
}

