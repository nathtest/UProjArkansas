#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "PrefabContainerInterface.h"
#include "PrefabGroup.generated.h"

UCLASS(Blueprintable)
class PREFABRICATORRUNTIME_API APrefabGroup : public AActor, public IPrefabContainerInterface {
    GENERATED_BODY()
public:
    APrefabGroup(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

