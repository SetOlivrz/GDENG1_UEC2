// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GDENG1_UEC2Character.h"
#include "GDENG1_UEC2Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

// enum types for projectiles
UENUM(Blueprintable)
enum ProjectileType
{
	DefaultProjectile UMETA(Displayname, "DefaultProjectile"),
	SmallProjectile UMETA(Displayname, "SmallProjectile"),
	BigProjectile UMETA(Displayname, "BigProjectile"),
	GiantProjectile UMETA(Displayname, "GiantProjectile")
};

UCLASS(config=Game)
class AGDENG1_UEC2Projectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

public:
	AGDENG1_UEC2Projectile();

	virtual void BeginPlay();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

public:
	ProjectileType projectileType = ProjectileType::DefaultProjectile;

	FVector scale;
	FVector newScale;

	float initialRad = 16.0f;
	int counter = 0;
	float normal_spd = 3500.0f; //3.5k
	float increased_spd = 10000.0f; //6k

	UFUNCTION(BlueprintCallable)
		void SetBulletType();

	UFUNCTION(BlueprintCallable)
		void UpdateBulletType();
};

