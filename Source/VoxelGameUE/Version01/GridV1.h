// Copyright © All Rights Reserved to Daniel 'Numsgil' Grondin

#pragma once

#include "GameFramework/Actor.h"
#include "../IntVector.h"
#include "GridV1.generated.h"

UCLASS()
class VOXELGAMEUE_API AGridV1 : public AActor
{
	GENERATED_BODY()
	
public:
	TMap<FInt3, class ACellV1*> Data;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Grid)
	class UMaterialInterface* Material;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cell Grid")
	FInt3 GridSize = FInt3(4, 4, 4);

	// Sets default values for this actor's properties
	AGridV1();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
};
