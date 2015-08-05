// Copyright © All Rights Reserved to Daniel 'Numsgil' Grondin

#pragma once

#include "GameFramework/Actor.h"
#include "Async.h"
#include "ProceduralMeshComponent.h"
#include "../IntVector.h"
#include "CellV1.generated.h"

const float CellSize = 32.0f;

struct MeshData
{
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> VertexColors;
};

UCLASS()
class VOXELGAMEUE_API ACellV1 : public AActor
{
	GENERATED_BODY()

	FCriticalSection Lock;

	TFuture<MeshData> FutureMesh;
	bool OngoingRefresh;
	
public:
	TFuture<TMap<FInt3, uint16>> FutureData;
	bool OngoingLoading;

	TMap<FInt3, uint16> Data;

	UPROPERTY(BlueprintReadOnly, Category = Cell)
	FInt3 GridPosition = FInt3();

	UPROPERTY(BlueprintReadOnly, Category = Cell)
	class AGridV1* Grid = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Cell)
	bool Dirty = true;

	UPROPERTY(VisibleAnywhere, Category = Cell)
	class UProceduralMeshComponent* Mesh;

	// Sets default values for this actor's properties
	ACellV1();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = Cell)
	void ClearVoxels()
	{
		Data.Empty();
	}

	UFUNCTION(BlueprintCallable, Category = Voxel)
	void SetAt(FInt3 const& position, int32 value);

	UFUNCTION(BlueprintCallable, Category = Voxel)
	int32 GetAt(FInt3 const& position);
};
