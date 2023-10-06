// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityManager.h"
#include "MassObserverProcessor.h"
#include "MassEntityQuery.h"
#include "MyInitProcessor.generated.h"

/**
 * 
 */
UCLASS()
class V5_API UMyInitProcessor : public UMassObserverProcessor
{
	GENERATED_BODY()
public:
	UMyInitProcessor();

protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntitySubsystem, FMassExecutionContext& Context) override;

private:
	FMassEntityQuery EntityQuery;
};
