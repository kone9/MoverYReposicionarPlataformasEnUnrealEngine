// Fill out your copyright notice in the Description page of Project Settings.


#include "ReiniciarPosicion.h"
#include "DatosGlobalesDesdeCpp.h"
#include "Actor.h"

// Sets default values for this component's properties
UReiniciarPosicion::UReiniciarPosicion()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UReiniciarPosicion::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UReiniciarPosicion::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if(plataforma->GetActorLocation().X >= _DatosGlobales->cuandoLlegaHasta.X)
	{
		FVector reiniciarPlataforma = FVector(
			_DatosGlobales->posicionReinicio.X,
			plataforma->GetActorLocation().Y,
			plataforma->GetActorLocation().Z
		);
		
		plataforma->SetActorLocation(reiniciarPlataforma);
		UE_LOG(LogTemp, Warning, TEXT("reinicia posicion"));
	}
}

