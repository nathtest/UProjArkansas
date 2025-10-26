#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "PrefabGroupComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PREFABRICATORRUNTIME_API UPrefabGroupComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPrefabGroupComponent(const FObjectInitializer& ObjectInitializer);

};

