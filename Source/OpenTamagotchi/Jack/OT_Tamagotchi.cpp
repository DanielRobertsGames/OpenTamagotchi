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

	m_direction = 0;

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
		StateCheck();
		Direction();
		Behaviour();
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
	m_happiness = m_happiness - 5;
	m_hunger = m_hunger - 10;
	m_tired = m_tired - 15;
	m_toilet = m_toilet - 20;
	m_fun = m_fun - 25;
}

void AOT_Tamagotchi::StateCheck()
{
	if (m_fun < 20)
	{
	    m_fun = 90;
	} //hungry
    if (m_hunger < 20)
	{
		m_hunger = 80;
	} //hungry

	if (m_happiness < 20)
	{
		m_happiness = 70;
	} //happiness

	if (m_tired < 20)
	{
		m_tired = 60;
	} //tired

	if (m_toilet < 20)
	{
		m_toilet = 50;
	} //toilet
}

void AOT_Tamagotchi::Movement(float DeltaTime)
{
	FVector location = GetActorLocation();

	if (m_direction == 0) // North
	{
		location.X += m_movementSpeed * DeltaTime;
		UE_LOG(LogTemp, Warning, TEXT("UP"));
	}
	else if (m_direction == 1) // East
	{
		location.Y += m_movementSpeed * DeltaTime;
		UE_LOG(LogTemp, Warning, TEXT("Right"));
	}
	else if (m_direction == 2) // South
	{
		location.X += -m_movementSpeed * DeltaTime;
		UE_LOG(LogTemp, Warning, TEXT("Down"));
	}
	else if (m_direction == 3) // West
	{
		location.Y += -m_movementSpeed * DeltaTime;
		UE_LOG(LogTemp, Warning, TEXT("Left"));
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
	if (GetActorLocation().Y > 100)
	{
		UE_LOG(LogTemp, Warning, TEXT("Reached Edge"));
		m_direction = 3;
	}
	else if (GetActorLocation().Y < -100)
	{
		UE_LOG(LogTemp, Warning, TEXT("Reached Edge"));
		m_direction = 1;
	}
}

void AOT_Tamagotchi::Behaviour()
{
        if (m_fun > 25)
        {
            UE_LOG(LogTemp, Warning, TEXT("I am having fun"));
        }
        else
        {
        	UE_LOG(LogTemp, Warning, TEXT("I am bored"));
        }//fun
    
        if (m_hunger > 25)
        {
            UE_LOG(LogTemp, Warning, TEXT("I am not hunger"));
        }
        else
        {
        	UE_LOG(LogTemp, Warning, TEXT("I am hunger"));
        }//hunger
        if (m_happiness > 25)
        {
            UE_LOG(LogTemp, Warning, TEXT("I am happy"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("I am sad"));
        }//happy    
        if (m_toilet > 25)
        {
            UE_LOG(LogTemp, Warning, TEXT("I don't need toilet"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("I need toilet"));
        }//toilet    

}
