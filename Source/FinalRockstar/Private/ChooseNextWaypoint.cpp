// Fill out your copyright notice in the Description page of Project Settings.

#include "FinalRockstar.h"
#include "../Public/ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
//TODO see if req
#include "AIController.h"
#include "../Public/PatrollingComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	

	auto AIController = OwnerComp.GetAIOwner();
	auto AICharacter = AIController->GetPawn() ;

	///Deal with no patrol route components
	auto PatrolRoute = AICharacter->FindComponentByClass<UPatrollingComponent>();

	if (!ensure(PatrolRoute))
	{
		return EBTNodeResult::Failed;	
	}

	///Protect against empty patrol points
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();

	
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is Missing Patrol Point"),*AICharacter->GetName());
		return EBTNodeResult::Failed;
	}

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto IndexInt = BlackboardComp->GetValueAsInt(Index.SelectedKeyName);
	

	//Get Patrol Points
	if (AICharacter)
	{
		//PatrolPointsInternal = AICharacter->GetPatrolPoints();



		//Get Next Waypoint
		BlackboardComp->SetValueAsObject(Waypoint.SelectedKeyName, PatrolPoints[IndexInt]);



		//Cycle Index

		BlackboardComp->SetValueAsInt(Index.SelectedKeyName, (IndexInt + 1)%PatrolPoints.Num());


	}
	 
	
	return EBTNodeResult::Succeeded;
}


