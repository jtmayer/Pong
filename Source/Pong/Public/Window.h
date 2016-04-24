// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Window.generated.h"

UCLASS()
class AWindow : public APawn
{
    GENERATED_BODY()

private:
    UCameraComponent* cameraComponent;
    
public:	
    // Sets default values for this actor's properties
    AWindow();
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;
    
    static FIntRect getRectangle(const AWindow& window);
    
};
