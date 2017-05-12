// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrollingComponent.generated.h"

/**
* Route for AI
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINALROCKSTAR_API UPatrollingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrollingComponent();

	TArray<AActor*> GetPatrolPoints() const;

private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*>PatrolPoints;
		
	
};
