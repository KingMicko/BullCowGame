// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitializeGame();

    PrintLine(TEXT("The hidden word is %s."), *HiddenWord);    // Debug line.

    DisplayWelcomeMessage();

    GetPlayerGuess();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{   
    GuessLength = Input.Len();
    if (bGameOver)
    {
        EndGame();
    }
    else    // Check PlayerGuess.
    {
		if (Input == HiddenWord)
		{
			PrintLine(TEXT("Well done, you won!"));
            EndGame();
		}
		else
		{
            if (WordLength != GuessLength)
            {
                PrintLine(TEXT("The hidden word is %i characters long! \nPlease guess again."), WordLength);
                EndGame();
            }
            else
            {

            }
			
		}
    }

    
    // Check if isogram.
    // Prompt to guess again.
    // Check for right number of characters.

    // Remove Life.

    // Check if lives > 0.
    // If Yes, GuessAgain.
    // Show lives left.
    // If no show GameOver and HiddenWord.
    // Prompt to play again, press enter to play again.
    // Check user input.
    // PlayAgain or Quit.

}


void UBullCowCartridge::InitializeGame()
{
    bGameOver = false;
	HiddenWord = TEXT("cake");  // Word to guess.
    WordLength = HiddenWord.Len();  // Sets the length of word to be guessed.
    NumLives = WordLength;
    GuessLength = 0;
}

void UBullCowCartridge::DisplayWelcomeMessage()
{
	PrintLine(TEXT("Hello. Welcome to the Bulls and Cows Game!"));
    PrintLine(TEXT("The aim of the game is to guess the hidden word."));
}


void UBullCowCartridge::GetPlayerGuess()
{
	PrintLine(TEXT("Guess the %i letter word\n"), WordLength);
	PrintLine(TEXT("Type in your Guess and press enter."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
}
