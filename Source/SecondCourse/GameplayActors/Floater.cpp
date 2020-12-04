// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));
	// StaticMesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh1"));

	InitialLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrigin = FVector(0.0f);

	InitialDirection = FVector(0.0f);

	bInitializeFloaterLocations = false;
	bShouldFloat = false;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	//FVector InitialLocation = FVector(0.0f); //we saw the overloaded constructor with only a single parameter will assign that param to x, y and z

	PlacedLocation = GetActorLocation();

	if (bInitializeFloaterLocations)
	{
		SetActorLocation(InitialLocation); //sets position of the "Floater actor" to 0.0 for all axis. 
	}
	
	// lesson 20 and previous
	//FHitResult HitResult;
	// Translation
	//FVector LocalOffset = FVector(200.f, 0.0f, 0.0f);
	//AddActorLocalOffset(LocalOffset, true, &HitResult);
	//AddActorWorldOffset(LocalOffset, true, &HitResult);
	// Rotation
	//FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f);
	//AddActorLocalRotation(Rotation);
	
	//lesson 21 force and torque
	InitialForce = FVector(8000000.0f, 0.0f, 0.0f);
	StaticMesh->AddForce(InitialForce);

	
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		//FHitResult HitResult;
		//AddActorLocalOffset(InitialDirection, true, &HitResult);

		//FVector HitLocation = HitResult.Location;

		//UE_LOG(LogTemp, Warning, TEXT("Hit Location: X= %f, Y= %f, Z =%f"), HitLocation.X, HitLocation.Y, HitLocation.Z)
	}

	// makes something spin
	//FRotator Rotation = FRotator(0.0f, 0.0f, 0.5f);
	//AddActorLocalRotation(Rotation);
	//AddActorWorldRotation(Rotation);
}
