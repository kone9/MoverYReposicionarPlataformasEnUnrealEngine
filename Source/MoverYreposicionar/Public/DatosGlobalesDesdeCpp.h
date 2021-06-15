// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DatosGlobalesDesdeCpp.generated.h"

UCLASS()
class MOVERYREPOSICIONAR_API ADatosGlobalesDesdeCpp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADatosGlobalesDesdeCpp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void SetupMyPlayerInputComponent(UInputComponent* myInputComponent);//para manejar el input

public:	

	UPROPERTY(EditAnywhere)
	FVector velocidad = FVector(10,0,0);

	UPROPERTY(EditAnywhere)
	FVector velocidadConOFfset = FVector(10,0,0);//velocidad usada solo para mover con offset

	UPROPERTY(EditAnywhere)
	FVector posicionReinicio = FVector(-2000,0,0);

	UPROPERTY(EditAnywhere)
	FVector cuandoLlegaHasta = FVector(2000,0,0);

	//para mover más rápido cada cierto tiempo
	UPROPERTY(EditAnywhere);
	float tiempoParaAumentarVelocidadMovimiento = 10;
	
	UPROPERTY(EditAnywhere);
	float velocidadAumentada = 10;//la velicidad que sera aumentada en cada tiempo

	UPROPERTY(VisibleAnywhere)
	bool aumentarVelocidadAutomaticamente = false;//PARA CAMBIAR lA FORMA DE MOVER
	
	UPROPERTY(EditAnywhere);
	bool puedoMoverConOffset = false;//PARA CAMBIAR lA FORMA DE MOVER

private:
	void AumentarDificultad();//para usar con el timer manager

	FTimerHandle timerDificultad;//timer manager aumentar velocidad

	void PuedoAumentarDificultad();//para usar con el input

	void NoPuedoAumentarDificultad();//para usar con el input

	void ActivarTeclas();//para activar las teclas

};
