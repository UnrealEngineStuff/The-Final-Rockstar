// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * Chooses Next Patrol Point
 */
UCLASS()
class FINALROCKSTAR_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:

	UPROPERTY(EditAnywhere, Category = "Keys")
	struct FBlackboardKeySelector Index;


	UPROPERTY(EditAnywhere, Category = "Keys")
	struct FBlackboardKeySelector Waypoint;
	
};
