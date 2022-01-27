// Fill out your copyright notice in the Description page of Project Settings.


#include "OT_Tamagotchi.h"
// Sets default values
AOT_Tamagotchi::AOT_Tamagotchi()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	TamagotchiMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TamagotchiMesh"));
	m_speed = 100;
	m_movementSpeed = 100.f;
	m_ticker = 0;
	m_happiness = 100;
	m_hunger = 100;
	m_tired = 100;
	m_toilet = 100;
	m_fun = 100;

	m_direction = 1;

	//m_ticker = 0;
}

// Called when the game starts or when spawned
void AOT_Tamagotchi::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AOT_Tamagotchi::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Movement(DeltaTime);

	if (m_ticker > m_speed)
	{
		StatsTick();
		Direction();
		UE_LOG(LogTemp, Warning, TEXT("Speed = %d"), m_speed);
		UE_LOG(LogTemp, Warning, TEXT("Fun = %d"), m_fun);
		UE_LOG(LogTemp, Warning, TEXT("Happiness = %d"), m_happiness);
		UE_LOG(LogTemp, Warning, TEXT("Hunger = %d"), m_hunger);
		UE_LOG(LogTemp, Warning, TEXT("Tired = %d"), m_tired);
		UE_LOG(LogTemp, Warning, TEXT("Toilet = %d"), m_toilet);

		m_ticker = 0;
	}
	m_ticker++;
}

void AOT_Tamagotchi::StatsTick()
{
	m_happiness--;
	m_hunger--;
	m_tired--;
	m_toilet--;
	m_fun--;
}
void AOT_Tamagotchi::Movement(float DeltaTime)
{
	FVector location = GetActorLocation();

	if (m_direction == 0) // North
	{
		location.X += m_movementSpeed * DeltaTime;
	}
	else if (m_direction == 1) // East
	{
		location.Y += m_movementSpeed * DeltaTime;
	}
	else if (m_direction == 2) // South
	{
		location.X += -m_movementSpeed * DeltaTime;
	}
	else if (m_direction == 3) // West
	{
		location.Y += -m_movementSpeed * DeltaTime;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Direction Error"));
	}
	SetActorLocation(location);

}

void AOT_Tamagotchi::Direction()
{
	m_direction = FMath::RandRange(0, 3);
	if (GetActorLocation().X > 700)
	{
		UE_LOG(LogTemp, Warning, TEXT("Reached Edge"));
		m_direction = 2;
	}
	else if (GetActorLocation().X < -700)
	{
		UE_LOG(LogTemp, Warning, TEXT("Reached Edge"));
		m_direction = 0;
	}
	if (GetActorLocation().Y > 570)
	{
		UE_LOG(LogTemp, Warning, TEXT("Reached Edge"));
		m_direction = 3;
	}
	else if (GetActorLocation().Y < -570)
	{
		UE_LOG(LogTemp, Warning, TEXT("Reached Edge"));
		m_direction = 1;
	}
}