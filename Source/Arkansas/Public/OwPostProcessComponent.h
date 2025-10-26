#pragma once
#include "CoreMinimal.h"
#include "Components\PostProcessComponent.h"

#include "OwPostProcessComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOwPostProcessComponent : public UActorComponent /*UPostProcessComponent*/ {
    GENERATED_BODY()
public:
    UOwPostProcessComponent(const FObjectInitializer& ObjectInitializer);
};

