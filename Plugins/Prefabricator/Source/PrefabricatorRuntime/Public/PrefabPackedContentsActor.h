#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "PrefabPackedContentsActor.generated.h"

UCLASS(Blueprintable)
class PREFABRICATORRUNTIME_API APrefabPackedContentsActor : public AActor {
    GENERATED_BODY()
public:
    APrefabPackedContentsActor(const FObjectInitializer& ObjectInitializer);

};

