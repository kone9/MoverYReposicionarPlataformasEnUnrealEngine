// Fill out your copyright notice in the Description page of Project Settings.


#include "DatosGlobalesDesdeCpp.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"

// Sets default values
ADatosGlobalesDesdeCpp::ADatosGlobalesDesdeCpp()
{

}

// Called when the game starts or when spawned
void ADatosGlobalesDesdeCpp::BeginPlay()
{
	Super::BeginPlay();

	ActivarTeclas();

}

//para activar teclas
void ADatosGlobalesDesdeCpp::ActivarTeclas()
{
	EnableInput( GetWorld()->GetFirstPlayerController() );//habilito el player controller aca

	UInputComponent* myInputComp = this->InputComponent; //input variable desde actor.h

	if(myInputComp)//si hay un input mio
	{
		SetupMyPlayerInputComponent(myInputComp);//agrego input
	}
}

//La funcion para manejar inputs en todos los frames
void ADatosGlobalesDesdeCpp::SetupMyPlayerInputComponent(UInputComponent* myInputComponent)
{
	InputComponent->BindAction("W", IE_Pressed, this, &ADatosGlobalesDesdeCpp::PuedoAumentarDificultad);
	InputComponent->BindAction("W", IE_Released, this, &ADatosGlobalesDesdeCpp::NoPuedoAumentarDificultad);
}

void ADatosGlobalesDesdeCpp::PuedoAumentarDificultad()//para el input
{
	GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Red, FString::Printf(TEXT("PRESIONE Tecla para aumentar velocidad")));
	UE_LOG(LogTemp, Error, TEXT("PRESIONE Tecla para aumentar velocidad"));
	aumentarVelocidadAutomaticamente = true;
	GetWorld()->GetTimerManager().SetTimer(timerDificultad, this, &ADatosGlobalesDesdeCpp::AumentarDificultad, tiempoParaAumentarVelocidadMovimiento, true);
}

void ADatosGlobalesDesdeCpp::NoPuedoAumentarDificultad()//para el input
{
	GEngine->AddOnScreenDebugMessage(0, 3.0f, FColor::Green, FString::Printf(TEXT("SOLTE Tecla para aumentar velocidad")));
	UE_LOG(LogTemp, Warning, TEXT("SOLTE Tecla para aumentar velocidad"));
	aumentarVelocidadAutomaticamente = false;
	GetWorld()->GetTimerManager().ClearTimer(timerDificultad);
	velocidad = FVector(1500,0,0);
}


void ADatosGlobalesDesdeCpp::AumentarDificultad()//para el timer
{
	velocidad.X = velocidad.X + velocidadAumentada;
}


