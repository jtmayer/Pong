// Fill out your copyright notice in the Description page of Project Settings.

#include "Pong.h"
#include "PongObject.h"

void APongObject::integrate(float deltaTime)
{
    if (netForce != prevNetForce || velocity != prevVelocity)
    {
	position += ((prevVelocity * time) +
		     (0.5 * prevNetForce * inverseMass * time * time));

	if (velocity == prevVelocity)
	{
	    velocity = ((prevVelocity +
			 (prevNetForce * inverseMass * time)) *
			damping);
	}
	
	time = 0;
    }

    time += deltaTime;
    SetActorLocation(position +
		     (velocity * time) +
		     (0.5 * netForce * inverseMass * time * time),
		     true);
    prevVelocity = velocity;
    prevNetForce = netForce;
    clearNetForce();
}

// Sets default values
APongObject::APongObject()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if
    // you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    time = 0;
    inverseMass = 0;
    damping = 0.99;
    velocity = FVector();
    prevNetForce = FVector();
    netForce = FVector();
    Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
}

// Called when the game starts or when spawned
void APongObject::BeginPlay()
{
    Super::BeginPlay();	
    position = GetActorLocation();
}

// Called every frame
void APongObject::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );
    integrate(DeltaTime);
}

// Called to bind functionality to input
void APongObject::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
    Super::SetupPlayerInputComponent(InputComponent);
}

void APongObject::addForce(const FVector& force)
{
    netForce += force;
}

void APongObject::clearNetForce()
{
    netForce = FVector();
}
