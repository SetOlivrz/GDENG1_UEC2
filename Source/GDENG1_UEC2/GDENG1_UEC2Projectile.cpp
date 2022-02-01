// Copyright Epic Games, Inc. All Rights Reserved.

#include "GDENG1_UEC2Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
//#include "DestructibleComponent.h"

void AGDENG1_UEC2Projectile::BeginPlay()
{
	Super::BeginPlay();

	SetBulletType();
	UpdateBulletType();
}

AGDENG1_UEC2Projectile::AGDENG1_UEC2Projectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AGDENG1_UEC2Projectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;

	SetBulletType();
	UpdateBulletType();

	// Die after 3 seconds by default
	InitialLifeSpan = 9999999999999999.0f;
}

void AGDENG1_UEC2Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 10000.0f, GetActorLocation());
		Destroy();
	}
}

void AGDENG1_UEC2Projectile::SetBulletType()
{
	//counter = FMath::RandRange(1, 4); // temp basis for projectile type

	counter = AGDENG1_UEC2Character::bulletType;

	switch (counter)
	{
		case 1: projectileType = DefaultProjectile; break;
		case 2: projectileType = SmallProjectile; break;
		case 3: projectileType = BigProjectile; break;
		case 4: projectileType = GiantProjectile; break;
	}

	UE_LOG(LogTemp, Error, TEXT("counter: %d"), counter);
}

void AGDENG1_UEC2Projectile::UpdateBulletType()
{

	switch (projectileType)
	{
		case DefaultProjectile: ProjectileMovement->InitialSpeed = normal_spd;
			ProjectileMovement->MaxSpeed = normal_spd;
			newScale = FVector(1.0f, 1.0f, 1.0f);
			break;

		case SmallProjectile: ProjectileMovement->InitialSpeed = increased_spd;
			ProjectileMovement->MaxSpeed = increased_spd;
			newScale = FVector(0.5f, 0.5f, 0.5f);
			break;

		case BigProjectile: ProjectileMovement->InitialSpeed = normal_spd;
			ProjectileMovement->MaxSpeed = normal_spd;
			newScale = FVector(6.5f, 6.5f, 6.5f);
			break;

		case GiantProjectile: ProjectileMovement->InitialSpeed = increased_spd;;
			ProjectileMovement->MaxSpeed = increased_spd;
			newScale = FVector(14.5f, 14.5f, 14.5f);
			break;

	}

	UE_LOG(LogTemp, Error, TEXT("Speed: %f"), ProjectileMovement->GetMaxSpeed());

	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	//updates scale
	CollisionComp->SetRelativeScale3D(newScale);

	scale = CollisionComp->GetRelativeScale3D();
	UE_LOG(LogTemp, Warning, TEXT("x: %f  y: %f z: %f  RADIUS: %f  SPEED: %f"), scale.X, scale.Y, scale.Z, CollisionComp->GetScaledSphereRadius(), ProjectileMovement->InitialSpeed);
}
