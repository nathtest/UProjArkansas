#pragma once
#include "CoreMinimal.h"
#include "Engine\StaticMeshActor.h"

#include "HLODStaticMeshActor.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API AHLODStaticMeshActor : public AStaticMeshActor {
    GENERATED_BODY()
public:
    AHLODStaticMeshActor(const FObjectInitializer& ObjectInitializer);

};

