// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlataformaDesdeCpp.generated.h"

UCLASS()
class MOVERYREPOSICIONAR_API APlataformaDesdeCpp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlataformaDesdeCpp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY() 
	class USceneComponent* RootOfBlueprint;//el blueprint root

	UPROPERTY(EditAnywhere);
	float cuandoLlegaHasta;//cuando llega a esta posicion tiene que seguir movimiendo o reiniciar

	UPROPERTY(EditAnywhere);
	FVector PosicionDeReinicio;//posicion de reinicio

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* plataforma;//plataforma nueva

	UPROPERTY(EditAnywhere);
	class ADatosGlobalesDesdeCpp* _DatosGlobales;//puntero al objeto datos globales de la escena
	

private:
	void MoverConOFfset();//para mover usando el metodo offset

	void MoverConSuma(float framePorSecond);// para mover usando suma de posicion

	float calcularMovimiento;
	


};
