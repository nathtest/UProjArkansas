#pragma once
#include "CoreMinimal.h"
#include "NavMesh/NavMeshRenderingComponent.h"

#include "OwNavMeshRenderingComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOwNavMeshRenderingComponent : public UNavMeshRenderingComponent {
    GENERATED_BODY()
public:
    UOwNavMeshRenderingComponent(const FObjectInitializer& ObjectInitializer);

};

