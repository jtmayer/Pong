// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Pong.h"
#include "PongGameMode.h"
#include "PongCharacter.h"

APongGameMode::APongGameMode()
{
    // set default pawn class to our character
    DefaultPawnClass = APongCharacter::StaticClass();	
}
