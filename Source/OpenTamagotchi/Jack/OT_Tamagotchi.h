// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OT_Tamagotchi.generated.h"

UCLASS()
class OPENTAMAGOTCHI_API AOT_Tamagotchi : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOT_Tamagotchi();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* TamagotchiMesh;

	UPROPERTY(EditAnywhere);
	int m_speed;

	UPROPERTY(EditAnywhere);
	float m_movementSpeed;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAcess = "True"))
		int m_ticker;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAcess = "True"))
		int m_happiness;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAcess = "True"))
		int m_hunger;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAcess = "True"))
		int m_tired;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAcess = "True"))
		int m_toilet;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAcess = "True"))
		int m_fun;

	char m_direction;

	void StatsTick();

	void Movement(float DeltaTime);
	void Direction();


};
