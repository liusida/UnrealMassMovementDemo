// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInitProcessor.h"
#include "MassCommonFragments.h"
#include "MassExecutionContext.h"
#include "MyTrait.h"

UMyInitProcessor::UMyInitProcessor()
{
    ObservedType = FAgentRadiusFragment::StaticStruct();
    Operation = EMassObservedOperation::Add;
}

void UMyInitProcessor::ConfigureQueries()
{
    // I want to modify FAgentRadiusFragment
	EntityQuery.AddRequirement<FAgentRadiusFragment>(EMassFragmentAccess::ReadWrite);

    // I want to process all entities with tag FMyTag
	EntityQuery.AddTagRequirement<FMyTag>(EMassFragmentPresence::All);
    EntityQuery.RegisterWithProcessor(*this);

}

void UMyInitProcessor::Execute(FMassEntityManager& EntitySubsystem, FMassExecutionContext& Context)
{
	EntityQuery.ForEachEntityChunk(EntitySubsystem, Context, ([this](FMassExecutionContext& Context)
    {
        const TArrayView<FAgentRadiusFragment> AgentRadiusList = Context.GetMutableFragmentView<FAgentRadiusFragment>();
        
        for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); ++EntityIndex)
        {
            FAgentRadiusFragment& AgentRadius = AgentRadiusList[EntityIndex];
            
            // Init the radius for Avoidence
            AgentRadius.Radius = 100.f;

        }
    }));
}