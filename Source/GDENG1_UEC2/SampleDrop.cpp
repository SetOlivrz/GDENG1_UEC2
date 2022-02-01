// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleDrop.h"
#include "DrawDebugHelpers.h"
#include "DestructibleComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
USampleDrop::USampleDrop()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void USampleDrop::BeginPlay()
{
	Super::BeginPlay();
	this->GetOwner()->GetActorBounds(true, initialOrigin, initialSize, false);
	
	
}


// Called every frame
void USampleDrop::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Get new bounds
	this->GetOwner()->GetActorBounds(true, newOrigin, newSize, false);
	//DrawDebugBox(this->GetWorld(), newOrigin, newSize, FColor::Red, false);

	//Check if old bounds x >= new bounds x
	/*if (initialSize.X < newSize.X && !dropped) {
		destroyed = true; dropped = true;
		UE_LOG(LogTemp, Display, TEXT("dropped"));
	}*/

	/*UE_LOG(LogTemp, Display, TEXT("Old: %f"), initialSize.X);
	UE_LOG(LogTemp, Display, TEXT("New: %f"), newSize.X);*/

	//SPAWN PROJECTILE
	//SpawnDrop();
}

void USampleDrop::SpawnDrop()
{
	destroyed = true; dropped = true;
	UE_LOG(LogTemp, Display, TEXT("dropped"));

	switch (FMath::RandRange(0, 3))
	{
	case 0: actorCopy = CapsuleActor; break;
	case 1: actorCopy = SquareActor; break;
	case 2: actorCopy = ConeActor; break;
	case 3: actorCopy = CylinderActor; break;
	}

	if (this->actorCopy != nullptr && destroyed)
	{
		if (actorCopy->FindComponentByClass<UDropParentReference>() != nullptr)
			actorCopy->FindComponentByClass<UDropParentReference>()->dropParent = this->GetOwner();
		FActorSpawnParameters spawnParams;
		spawnParams.Template = this->actorCopy;
		spawnParams.Owner = this->GetOwner();

		FVector spawnLocation = this->GetOwner()->GetActorLocation();

		AActor* myActor = this->GetWorld()->SpawnActor<AActor>(this->actorCopy->GetClass(), spawnParams);

		//Activate
		myActor->AttachToActor(this->GetOwner(), FAttachmentTransformRules::KeepWorldTransform);
		myActor->SetActorHiddenInGame(false);
		myActor->SetActorLocation(spawnLocation);
		
		destroyed = false;
	}
}

void USampleDrop::SetDrops(AActor* caps, AActor* sqr, AActor* cone, AActor* cylinder)
{
	if(caps != nullptr)
	{
		this->CapsuleActor = caps;
	}

	if (sqr != nullptr)
	{
		this->SquareActor = sqr;
	}
	if (cone != nullptr)
	{
		this->ConeActor = cone;
	}
	if (cylinder != nullptr)
	{
		this->CylinderActor = cylinder;
	}

}

