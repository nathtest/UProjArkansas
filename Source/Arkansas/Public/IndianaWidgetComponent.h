#pragma once
#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "RelevanceOptimizationInterface.h"
#include "IndianaWidgetComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UIndianaWidgetComponent : public UWidgetComponent, public IRelevanceOptimizationInterface {
    GENERATED_BODY()
public:
    UIndianaWidgetComponent(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

