// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/Pickup.h"
#include "BlasterTypes/WeaponTypes.h"
#include "AmmoPickup.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API AAmmoPickup : public APickup
{
	GENERATED_BODY()

protected:
	virtual void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:
	UPROPERTY(EditAnywhere)
	int32 AmmoAmount = 30;

	UPROPERTY(EditAnywhere)
	EWeaponType WeaponType;
	
};
