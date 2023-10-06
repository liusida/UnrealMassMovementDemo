// Fill out your copyright notice in the Description page of Project Settings.

#include "MassEntityTemplateRegistry.h"
#include "MyTrait.h"


void UMyTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext,const UWorld& World) const
{
    // All entities with UMyTrait should have the tag FMyTag, so the processors can filter them out.
    BuildContext.AddTag<FMyTag>();
}