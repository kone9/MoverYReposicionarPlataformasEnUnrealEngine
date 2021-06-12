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
	if(GetActorLocation().X < _DatosGlobales->cuandoLlegaHasta.X - _DatosGlobales->velocidad.X)
	{
		AddActorWorldOffset(_DatosGlobales->velocidad);
	}
	else
	{
		FVector ReiniciarPlataforma = FVector(0,0,0);
		ReiniciarPlataforma.X = _DatosGlobales->posicionReinicio.X;
		ReiniciarPlataforma.Y = GetActorLocation().Y;
		ReiniciarPlataforma.Z = GetActorLocation().Z;
		SetActorLocation(ReiniciarPlataforma);
	}
}

//para mover haciendo el calculo de la suma
void APlataformaDesdeCpp::MoverConSuma(float framePorSecond)
{
	if(GetActorLocation().X < _DatosGlobales->cuandoLlegaHasta.X)
	{
		calcularMovimiento = GetActorLocation().X + _DatosGlobales->velocidad.X * framePorSecond;
		SetActorLocation(FVector(calcularMovimiento,0,0));
	}
	else
	{
		FVector ReiniciarPlataforma = FVector(0,0,0);
		ReiniciarPlataforma.X = _DatosGlobales->posicionReinicio.X;
		ReiniciarPlataforma.Y = GetActorLocation().Y;
		ReiniciarPlataforma.Z = GetActorLocation().Z;
		SetActorLocation(ReiniciarPlataforma);
	}
}


