// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "MyProcessor.generated.h"

/**
 * 
 */
UCLASS()
class V5_API UMyProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:
	UMyProcessor();

protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context) override;

private:
	FMassEntityQuery EntityQuery;
};
