// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;

	// Your declarations go below!
private:
	bool bGameOver;
	FString HiddenWord;	// Word to guess.
	int32 NumLives;
	int32 WordLength;
	int32 GuessLength;

	// Functions.
	void InitializeGame();
	void DisplayWelcomeMessage();
	void GetPlayerGuess();
	void EndGame();
};
