// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PongObject.h"
#include "Ball.generated.h"

namespace EBoundaryFlags
{
    enum BoundaryFlags
    {
	OUT_OF_VERTICAL_BOUNDS = 0x01,
	OUT_OF_HORIZONTAL_BOUNDS = 0x02
    };
};

/**
 * 
 */
UCLASS()
class ABall : public APongObject
{
    GENERATED_BODY()
    
private:
    uint32 boundaryFlags;

public:
    ABall();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;
    
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
};

