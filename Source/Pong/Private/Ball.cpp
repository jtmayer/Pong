// Fill out your copyright notice in the Description page of Project Settings.

#include "Pong.h"
#include "Ball.h"

ABall::ABall(): APongObject() {}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABall::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void ABall::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
    Super::SetupPlayerInputComponent(InputComponent);
}
