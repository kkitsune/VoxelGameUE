// Fill out your copyright notice in the Description page of Project Settings.

#include "VoxelGameUE.h"
#include "../GenerateFace.h"
#include "CellV1.h"
#include "GridV1.h"

// Sets default values
AGridV1::AGridV1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGridV1::BeginPlay()
{
	Super::BeginPlay();

	int32 HalfX = GridSize.X / 2;
	int32 HalfY = GridSize.Y / 2;
	int32 HalfZ = GridSize.Z / 2;

	FActorSpawnParameters param;
	param.Owner = this;

	for (int32 x = -HalfX; x < HalfX; x++)
	{
		for (int32 y = -HalfY; y < HalfY; y++)
		{
			for (int32 z = -HalfZ; z < HalfZ; z++)
			{
				ACellV1* cell = GetWorld()->SpawnActor<ACellV1>(FVector(x, y, z) * VoxelSize * CellSize, FRotator(), param);
				cell->GridPosition = FInt3(x, y, z);
				cell->Grid = this;
				cell->FutureData = Async<TMap<FInt3, uint16>>(EAsyncExecution::ThreadPool, []()
				{
					TMap<FInt3, uint16> ret;
					for (int32 i = 0; i < 32; i++)
						for (int32 j = 0; j < 32; j++)
							for (int32 k = 0; k < 32; k++)
								ret.Add(FInt3(i, j, k), 1);
					return ret;
				});
				cell->OngoingLoading = true;

				cell->Mesh->SetMaterial(0, Material);
				Data.Add(FInt3(x, y, z), cell);
			}
		}
	}
}

// Called every frame
void AGridV1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
