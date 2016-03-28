// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PaperFlipbookComponent.h"
#include "PongObject.generated.h"

UCLASS()
class PONG_API APongObject : public APawn
{
    GENERATED_BODY()

private:
    float time;
    FVector position;
    FVector prevVelocity;
    FVector prevNetForce;
    FVector netForce;
    
    UPROPERTY(EditAnywhere) float inverseMass;
    UPROPERTY(EditAnywhere) float damping;
    UPROPERTY(EditAnywhere) FVector velocity;

    UPROPERTY(EditAnywhere)
    UPaperFlipbookComponent* Sprite;

    void integrate(float deltaTime);    
	
public:
    // Sets default values for this pawn's properties
    APongObject();
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;
    
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    
    void addForce(const FVector& force);

    void clearNetForce();
    
};
