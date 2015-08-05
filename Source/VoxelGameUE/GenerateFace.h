// Copyright © All Rights Reserved to Daniel 'Numsgil' Grondin

#pragma once

#include "ProceduralMeshComponent.h"
#include "IntVector.h"

const float VoxelSize = 50.f;
const float VoxelHalfSize = VoxelSize / 2;

extern void GenerateFaceUp(const FInt3&, TArray<FVector>&, TArray<int32>&, TArray<FVector>&, TArray<FVector2D>&, TArray<FColor>&, TArray<FProcMeshTangent>&);
extern void GenerateFaceDown(const FInt3&, TArray<FVector>&, TArray<int32>&, TArray<FVector>&, TArray<FVector2D>&, TArray<FColor>&, TArray<FProcMeshTangent>&);
extern void GenerateFaceNorth(const FInt3&, TArray<FVector>&, TArray<int32>&, TArray<FVector>&, TArray<FVector2D>&, TArray<FColor>&, TArray<FProcMeshTangent>&);
extern void GenerateFaceSouth(const FInt3&, TArray<FVector>&, TArray<int32>&, TArray<FVector>&, TArray<FVector2D>&, TArray<FColor>&, TArray<FProcMeshTangent>&);
extern void GenerateFaceEast(const FInt3&, TArray<FVector>&, TArray<int32>&, TArray<FVector>&, TArray<FVector2D>&, TArray<FColor>&, TArray<FProcMeshTangent>&);
extern void GenerateFaceWest(const FInt3&, TArray<FVector>&, TArray<int32>&, TArray<FVector>&, TArray<FVector2D>&, TArray<FColor>&, TArray<FProcMeshTangent>&);
