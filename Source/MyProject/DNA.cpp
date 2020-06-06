#include "DNA.h"
DNA::DNA()
{
  for (int i = 0; i < StringLength; i++)
    OutString += Alphabet[FMath::RandRange(0, 26)];
}

DNA::DNA(FString NewString)
{
  OutString = NewString;
}

int DNA::Fitness()
{
  int Fitness = 0;
  for (int i = 0; i < OutString.Len(); i++)
    if (OutString[i] == GoalPhrase[i])
      Fitness++;
  return Fitness;
}

DNA* DNA::Crossover(DNA* Parent)
{
  int Midpoint = FMath::RandRange(0, Parent->StringLength);
  FString NewString = OutString.Mid(0, Midpoint) + Parent->OutString.Mid(Midpoint, Parent->StringLength);
  DNA* Child = new DNA(NewString);
  return Child;
}

void DNA::Mutate()
{
  for (int i = 0; i < MutationLevel; i++) 
  {
    int RandSelection = FMath::RandRange(0, StringLength - 1);
    int RandReplacement = FMath::RandRange(0, Alphabet.Len() - 1);
    OutString[RandSelection] = Alphabet[RandReplacement];
  }
}

