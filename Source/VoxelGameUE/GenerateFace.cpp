// Copyright © All Rights Reserved to Daniel 'Numsgil' Grondin

#include "VoxelGameUE.h"
#include "GenerateFace.h"

// Z+
void GenerateFaceUp(const FInt3& Position, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UV, TArray<FColor>& VertexColors, TArray<FProcMeshTangent>& Tangents)
{
	auto last = Vertices.Num();

	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));

	Normals.Add(FVector(0, 0, 1));
	Normals.Add(FVector(0, 0, 1));
	Normals.Add(FVector(0, 0, 1));
	Normals.Add(FVector(0, 0, 1));

	Tangents.Add(FProcMeshTangent(1, 0, 0));
	Tangents.Add(FProcMeshTangent(1, 0, 0));
	Tangents.Add(FProcMeshTangent(1, 0, 0));
	Tangents.Add(FProcMeshTangent(1, 0, 0));

	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));

	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));

	Triangles.Add(last + 0);
	Triangles.Add(last + 3);
	Triangles.Add(last + 1);

	Triangles.Add(last + 0);
	Triangles.Add(last + 2);
	Triangles.Add(last + 3);
}

// Z-
void GenerateFaceDown(const FInt3& Position, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UV, TArray<FColor>& VertexColors, TArray<FProcMeshTangent>& Tangents)
{
	auto last = Vertices.Num();

	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));

	Normals.Add(FVector(0, 0, -1));
	Normals.Add(FVector(0, 0, -1));
	Normals.Add(FVector(0, 0, -1));
	Normals.Add(FVector(0, 0, -1));

	Tangents.Add(FProcMeshTangent(-1, 0, 0));
	Tangents.Add(FProcMeshTangent(-1, 0, 0));
	Tangents.Add(FProcMeshTangent(-1, 0, 0));
	Tangents.Add(FProcMeshTangent(-1, 0, 0));

	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));

	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));

	Triangles.Add(last + 0);
	Triangles.Add(last + 1);
	Triangles.Add(last + 3);

	Triangles.Add(last + 0);
	Triangles.Add(last + 3);
	Triangles.Add(last + 2);
}

// Y-
void GenerateFaceNorth(const FInt3& Position, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UV, TArray<FColor>& VertexColors, TArray<FProcMeshTangent>& Tangents)
{
	auto last = Vertices.Num();

	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));

	Normals.Add(FVector(0, -1, 0));
	Normals.Add(FVector(0, -1, 0));
	Normals.Add(FVector(0, -1, 0));
	Normals.Add(FVector(0, -1, 0));

	Tangents.Add(FProcMeshTangent(0, 0, -1));
	Tangents.Add(FProcMeshTangent(0, 0, -1));
	Tangents.Add(FProcMeshTangent(0, 0, -1));
	Tangents.Add(FProcMeshTangent(0, 0, -1));

	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));

	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));

	Triangles.Add(last + 0);
	Triangles.Add(last + 3);
	Triangles.Add(last + 1);

	Triangles.Add(last + 0);
	Triangles.Add(last + 2);
	Triangles.Add(last + 3);
}

// Y+
void GenerateFaceSouth(const FInt3& Position, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UV, TArray<FColor>& VertexColors, TArray<FProcMeshTangent>& Tangents)
{
	auto last = Vertices.Num();

	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));

	Normals.Add(FVector(0, 1, 0));
	Normals.Add(FVector(0, 1, 0));
	Normals.Add(FVector(0, 1, 0));
	Normals.Add(FVector(0, 1, 0));

	Tangents.Add(FProcMeshTangent(0, 0, 1));
	Tangents.Add(FProcMeshTangent(0, 0, 1));
	Tangents.Add(FProcMeshTangent(0, 0, 1));
	Tangents.Add(FProcMeshTangent(0, 0, 1));

	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));

	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));

	Triangles.Add(last + 0);
	Triangles.Add(last + 1);
	Triangles.Add(last + 3);

	Triangles.Add(last + 0);
	Triangles.Add(last + 3);
	Triangles.Add(last + 2);
}

// X+
void GenerateFaceEast(const FInt3& Position, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UV, TArray<FColor>& VertexColors, TArray<FProcMeshTangent>& Tangents)
{
	auto last = Vertices.Num();

	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));

	Normals.Add(FVector(1, 0, 0));
	Normals.Add(FVector(1, 0, 0));
	Normals.Add(FVector(1, 0, 0));
	Normals.Add(FVector(1, 0, 0));

	Tangents.Add(FProcMeshTangent(0, 1, 0));
	Tangents.Add(FProcMeshTangent(0, 1, 0));
	Tangents.Add(FProcMeshTangent(0, 1, 0));
	Tangents.Add(FProcMeshTangent(0, 1, 0));

	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));

	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));

	Triangles.Add(last + 0);
	Triangles.Add(last + 3);
	Triangles.Add(last + 1);

	Triangles.Add(last + 0);
	Triangles.Add(last + 2);
	Triangles.Add(last + 3);
}

// X-
void GenerateFaceWest(const FInt3& Position, TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector>& Normals, TArray<FVector2D>& UV, TArray<FColor>& VertexColors, TArray<FProcMeshTangent>& Tangents)
{
	auto last = Vertices.Num();

	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));
	Vertices.Add(FVector(-VoxelHalfSize + Position.X * VoxelSize, -VoxelHalfSize + Position.Y * VoxelSize, -VoxelHalfSize + Position.Z * VoxelSize));

	Normals.Add(FVector(-1, 0, 0));
	Normals.Add(FVector(-1, 0, 0));
	Normals.Add(FVector(-1, 0, 0));
	Normals.Add(FVector(-1, 0, 0));

	Tangents.Add(FProcMeshTangent(0, -1, 0));
	Tangents.Add(FProcMeshTangent(0, -1, 0));
	Tangents.Add(FProcMeshTangent(0, -1, 0));
	Tangents.Add(FProcMeshTangent(0, -1, 0));

	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));
	VertexColors.Add(FColor(0, 0, 255));

	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));
	UV.Add(FVector2D(0, 0));

	Triangles.Add(last + 0);
	Triangles.Add(last + 1);
	Triangles.Add(last + 3);

	Triangles.Add(last + 0);
	Triangles.Add(last + 3);
	Triangles.Add(last + 2);
}
