// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProcessor.h"
#include "MassCommonFragments.h"
#include "MassNavigationFragments.h"
#include "MyTrait.h"

UMyProcessor::UMyProcessor()
{
    bAutoRegisterWithProcessingPhases = true;
    ExecutionFlags = (int32)EProcessorExecutionFlags::All;
    ExecutionOrder.ExecuteBefore.Add(UE::Mass::ProcessorGroupNames::Avoidance);
}

void UMyProcessor::ConfigureQueries()
{
    // I want to modify FTransformFragment and FMassMoveTargetFragment
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	EntityQuery.AddRequirement<FMassMoveTargetFragment>(EMassFragmentAccess::ReadWrite);
    
    // I want to process all entities with tag FMyTag
	EntityQuery.AddTagRequirement<FMyTag>(EMassFragmentPresence::All);

}

void UMyProcessor::Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context)
{
    EntityQuery.ForEachEntityChunk(EntitySubsystem, Context, ([this](FMassExecutionContext& Context)
		{
            const TArrayView<FTransformFragment> TransformsList = Context.GetMutableFragmentView<FTransformFragment>();
			const TArrayView<FMassMoveTargetFragment> TargetsList = Context.GetMutableFragmentView<FMassMoveTargetFragment>();

			for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); ++EntityIndex)
			{
                FTransform& Transform = TransformsList[EntityIndex].GetMutableTransform();
				FMassMoveTargetFragment& Target = TargetsList[EntityIndex];
                
                // Dynamically set the target (though we don't have any logic here)
                Target.Center = FVector(1000.f, 100.f, 0.f);
                
                // Set the orientation to facing the target
                Target.Forward = (Target.Center - Transform.GetLocation()).GetSafeNormal();
                Transform.SetRotation(FQuat::FindBetweenVectors(FVector::ForwardVector, Target.Forward));

			}
		}));
}
