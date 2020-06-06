// Fill out your copyright notice in the Description page of Project Settings.


#include "EvolutionActor.h"

#include "Engine/Engine.h"

// Sets default values
AEvolutionActor::AEvolutionActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEvolutionActor::BeginPlay()
{
	Super::BeginPlay();
	for (int i = 0; i < DNAListLength; i++)
	{
		DNA* TempDNA = new DNA;
		DNAList.Add(TempDNA);
	}
	
}

// Called every frame
void AEvolutionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!IsDone)
		ChildGeneration();
}

void AEvolutionActor::ChildGeneration()
{
	TArray<DNA*>Roulette;
	TArray<DNA*> NewArray;
	for (int i = 0; i < DNAListLength; i++)
	{
		DNA* Child = DNAList[i];
		for (int j = 0; j < Child->Fitness() + 1; j++)
			Roulette.Add(Child);
	}

	for (int i = 0; i < 50; i++)
	{
		DNA* Parent1 = Roulette[FMath::RandRange(0, Roulette.Num() - 1)];
		DNA* Parent2 = Roulette[FMath::RandRange(0, Roulette.Num() - 1)];
		DNA* ChildOne = Parent1->Crossover(Parent2);
		DNA* ChildTwo = Parent2->Crossover(Parent1);
		ChildOne->Mutate();
		ChildTwo->Mutate();
		if (ChildOne->OutString == ChildOne->GoalPhrase || ChildTwo->OutString == ChildTwo->GoalPhrase)
			IsDone = true;
		NewArray.Add(ChildOne);
		NewArray.Add(ChildTwo);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, ChildOne->OutString);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, ChildTwo->OutString);
	}
	DNAList = NewArray;
};


