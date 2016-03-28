// Fill out your copyright notice in the Description page of Project Settings.

#include "Pong.h"
#include "Window.h"


// Sets default values
AWindow::AWindow()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance
    //if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
    
    cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    cameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
    cameraComponent->OrthoWidth = 2048;
}

// Called when the game starts or when spawned
void AWindow::BeginPlay()
{
    Super::BeginPlay();
	
}

// Called every frame
void AWindow::Tick( float DeltaTime )
{
    Super::Tick( DeltaTime );

}

FIntRect AWindow::getRectangle(const AWindow& window)
{
    int height = window.cameraComponent->OrthoWidth / window.cameraComponent->AspectRatio;
    return FIntRect(FIntPoint(window.GetActorLocation().X -
			      window.cameraComponent->OrthoWidth/2,
			      window.GetActorLocation().Z -
			      height/2),
		    FIntPoint(window.GetActorLocation().X +
			      window.cameraComponent->OrthoWidth/2,
			      window.GetActorLocation().Z +
			      height/2));
}
