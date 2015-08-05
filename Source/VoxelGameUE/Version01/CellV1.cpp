// Copyright © All Rights Reserved to Daniel 'Numsgil' Grondin

#include "VoxelGameUE.h"
#include "GridV1.h"
#include "../GenerateFace.h"
#include "CellV1.h"

// Sets default values
ACellV1::ACellV1() : Lock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("CellMesh"));
	RootComponent = Mesh;

	OngoingRefresh = false;
}

// Called when the game starts or when spawned
void ACellV1::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACellV1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (OngoingLoading)
	{
		if (FutureData.WaitFor(FTimespan(ETimespan::TicksPerMillisecond * 100)))
		{
			Data = FutureData.Get();
			Dirty = true;
			OngoingLoading = false;
		}
	}

	if (Dirty)
	{
		if (!OngoingRefresh)
		{
			FutureMesh = Async<MeshData>(EAsyncExecution::ThreadPool, [this]()
			{
				MeshData ret;

				for (auto& voxel : Data)
				{
					if (voxel.Value != 0)
					{
						if (GetAt(voxel.Key + FInt3(0, 0, 1)) == 0)
							GenerateFaceUp(voxel.Key, ret.Vertices, ret.Triangles, ret.Normals, ret.UVs, ret.VertexColors, ret.Tangents);
						if (GetAt(voxel.Key - FInt3(0, 0, 1)) == 0)
							GenerateFaceDown(voxel.Key, ret.Vertices, ret.Triangles, ret.Normals, ret.UVs, ret.VertexColors, ret.Tangents);
						if (GetAt(voxel.Key - FInt3(0, 1, 0)) == 0)
							GenerateFaceNorth(voxel.Key, ret.Vertices, ret.Triangles, ret.Normals, ret.UVs, ret.VertexColors, ret.Tangents);
						if (GetAt(voxel.Key + FInt3(0, 1, 0)) == 0)
							GenerateFaceSouth(voxel.Key, ret.Vertices, ret.Triangles, ret.Normals, ret.UVs, ret.VertexColors, ret.Tangents);
						if (GetAt(voxel.Key + FInt3(1, 0, 0)) == 0)
							GenerateFaceEast(voxel.Key, ret.Vertices, ret.Triangles, ret.Normals, ret.UVs, ret.VertexColors, ret.Tangents);
						if (GetAt(voxel.Key - FInt3(1, 0, 0)) == 0)
							GenerateFaceWest(voxel.Key, ret.Vertices, ret.Triangles, ret.Normals, ret.UVs, ret.VertexColors, ret.Tangents);
					}
				}

				return ret;
			});
			OngoingRefresh = true;
		}
		else
		{
			if (FutureMesh.WaitFor(FTimespan(ETimespan::TicksPerMillisecond * 100)))
			{
				MeshData meshdata = FutureMesh.Get();
				Mesh->ClearAllMeshSections();
				Mesh->CreateMeshSection(0, meshdata.Vertices, meshdata.Triangles, meshdata.Normals, meshdata.UVs, meshdata.VertexColors, meshdata.Tangents, true);

				OngoingRefresh = false;
				Dirty = false;
			}
		}
	}
}

void ACellV1::SetAt(const FInt3& position, int32 value)
{
	FScopeLock WriteLock(&Lock);
	if (value == 0)
	{
		if (Data.Find(position) != nullptr)
		{
			Data.Remove(position);
			Dirty = true;
		}
		return;
	}
	if (Data.Find(position) == nullptr)
		Data.Add(position);
	Data[position] = (uint16)value;
	Dirty = true;
}

int32 ACellV1::GetAt(const FInt3& position)
{
	FScopeLock ReadLock(&Lock);
	uint16* value = Data.Find(position);
	return value == nullptr ? 0 : (int32)*value;
}
