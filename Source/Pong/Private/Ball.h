// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PongObject.h"
#include "Ball.generated.h"

/**
 * 
 */
UCLASS()
class ABall : public APongObject
{
    GENERATED_BODY()
    
private:

public:
    ABall();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;
    
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
};

