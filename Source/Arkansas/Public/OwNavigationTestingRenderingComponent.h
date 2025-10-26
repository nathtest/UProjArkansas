#pragma once
#include "CoreMinimal.h"
#include <NavMesh/NavTestRenderingComponent.h>
#include "OwNavigationTestingRenderingComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOwNavigationTestingRenderingComponent : public UDebugDrawComponent /*NavTestRenderingComponent*/ {
    GENERATED_BODY()
public:
    UOwNavigationTestingRenderingComponent(const FObjectInitializer& ObjectInitializer);
};

