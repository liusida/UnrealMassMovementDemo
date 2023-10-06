// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "MassEntityTypes.h"


#include "MyTrait.generated.h"


USTRUCT()
struct V5_API FMyTag : public FMassTag
{
	GENERATED_BODY()
};


UCLASS()
class V5_API UMyTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()
	
protected:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;
};
