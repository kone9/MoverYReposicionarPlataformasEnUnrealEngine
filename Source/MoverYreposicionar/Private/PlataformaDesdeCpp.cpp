// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaDesdeCpp.h"
#include "DatosGlobalesDesdeCpp.h"
// #include "Components/StaticMeshComponent.h"

// Sets default values
APlataformaDesdeCpp::APlataformaDesdeCpp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//creo el root ojo es un puntero declarado en .h como visible 
	RootOfBlueprint = CreateDefaultSubobject<USceneComponent>(TEXT("RootOfBlueprint"));
	RootComponent = RootOfBlueprint;
	
	plataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("plataforma"));
	plataforma->AttachTo(RootOfBlueprint);


}

// Called when the game starts or when spawned
void APlataformaDesdeCpp::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void APlataformaDesdeCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(_DatosGlobales->puedoMoverConOffset)
	{
		MoverConOFfset();//para mover con el nodo offset
	}
	else
	{
		MoverConSuma(DeltaTime);//para mover con suma
	}	

}

//para mover con el metodo offset
void APlataformaDesdeCpp::MoverConOFfset()
{
	
	AddActorWorldOffset(_DatosGlobales->velocidadConOFfset); //muevo con el offset segun la velocidad el offset mueve con el delta frame
	
	if(GetActorLocation().X >= _DatosGlobales->cuandoLlegaHasta.X - calcularMovimiento)
	{
		FVector reiniciarPlataforma = FVector(0,0,0);
		reiniciarPlataforma.X = _DatosGlobales->posicionReinicio.X;
		
		reiniciarPlataforma.Y = GetActorLocation().Y;
		reiniciarPlataforma.Z = GetActorLocation().Z;
		
		SetActorLocation(reiniciarPlataforma);
	}
}

//para mover haciendo el calculo de la suma
void APlataformaDesdeCpp::MoverConSuma(float framePorSecond)
{
	
	calcularMovimiento = _DatosGlobales->velocidad.X * framePorSecond; //el movimiento es igual a la velocidad en X por el frame
	//vector de movimiento
	FVector posicionNueva = FVector(
		GetActorLocation().X + calcularMovimiento, //aumenta la posición actual
		GetActorLocation().Y, //posicion en Y
		GetActorLocation().Z //posicion en z
	);

	SetActorLocation(posicionNueva);//muevo el actor
	
	//reposicionar
	if(GetActorLocation().X >= _DatosGlobales->cuandoLlegaHasta.X - calcularMovimiento)
	{
		//vector de reinicio
		FVector reiniciarPlataforma = FVector( 
				_DatosGlobales->posicionReinicio.X + calcularMovimiento, //obtengo la posicion de reinicio desde datos globales mas el movimiento
				GetActorLocation().Y, //posicion en Y
				GetActorLocation().Z //posicion en z
			);

		SetActorLocation(reiniciarPlataforma);//cambio la posición del actor
	}

}


