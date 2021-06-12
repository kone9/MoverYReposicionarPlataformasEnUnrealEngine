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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector velocidad = FVector(10,0,0);

	UPROPERTY(EditAnywhere)
	FVector posicionReinicio = FVector(-2000,0,0);

	UPROPERTY(EditAnywhere)
	FVector cuandoLlegaHasta = FVector(2000,0,0);

	
	UPROPERTY(EditAnywhere);
	bool puedoMoverConOffset = false;//PARA CAMBIAR lA FORMA DE MOVER


};
