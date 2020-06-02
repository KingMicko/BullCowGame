// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    HiddenWord = TEXT("cake");  // Word to guess.
    PrintLine(TEXT("Hello. Welcome to the Bulls and Cows Game!"));
    PrintLine(TEXT("Guess the four letter word\n"));    // Remove magic number.
    PrintLine(TEXT("Press enter to continue....\n"));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    PrintLine(Input);

    if (Input == HiddenWord)
    {
        //GameWon();
        PrintLine(TEXT("Well done, you won!"));
    }
    else
    {
        PrintLine(TEXT("Hard luck, you lost!"));
    }
}