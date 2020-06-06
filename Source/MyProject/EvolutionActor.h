// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DNA.h"
#include "EvolutionActor.generated.h"


UCLASS()
class MYPROJECT_API AEvolutionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEvolutionActor();
	TArray<DNA*> DNAList;
	void ChildGeneration();
	const int DNAListLength = 100;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool IsDone = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
