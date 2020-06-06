#pragma once
#include "CoreMinimal.h"

class DNA
{
public:
  DNA* Crossover(DNA* Parent);
  DNA();
  DNA(FString NewString);
  int Fitness();
  void Mutate();
  FString OutString;
  const FString GoalPhrase = "Evolutionary Algorithms";
private:
  const FString Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
  const int StringLength = 23;
  const int MutationLevel = 3;
};
