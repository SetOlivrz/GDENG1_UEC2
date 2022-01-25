// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DropParentReference.h"
#include "SampleDrop.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GDENG1_UEC2_API USampleDrop : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USampleDrop();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable) void SpawnDrop();
	FVector initialSize;
	FVector initialOrigin;

	FVector newSize;
	FVector newOrigin;

	bool destroyed = false;
	bool dropped = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) AActor* CapsuleActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AActor* SquareActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AActor* ConeActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AActor* CylinderActor;

	AActor* actorCopy;

};
