// Fill out your copyright notice in the Description page of Project Settings.

#include "Pong.h"
#include "Ball.h"

ABall::ABall(): APongObject()
{
    boundaryFlags = 0;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABall::Tick( float DeltaTime )
{
    if (false)
    {
	if ((boundaryFlags & EBoundaryFlags::OUT_OF_VERTICAL_BOUNDS) == 0)
	{
	    addImpulse(FVector());
	}

	boundaryFlags |= EBoundaryFlags::OUT_OF_VERTICAL_BOUNDS;
    }

    else if (false)
    {
	if ((boundaryFlags & EBoundaryFlags::OUT_OF_HORIZONTAL_BOUNDS) == 0)
	{
	    addImpulse(FVector());
	}

	boundaryFlags |= EBoundaryFlags::OUT_OF_HORIZONTAL_BOUNDS;
    }

    else
    {
        boundaryFlags = 0;
    }

    Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void ABall::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
    Super::SetupPlayerInputComponent(InputComponent);
}
