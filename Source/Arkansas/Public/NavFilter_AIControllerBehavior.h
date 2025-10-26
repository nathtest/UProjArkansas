#pragma once
#include "CoreMinimal.h"
#include "NavFilters/NavigationQueryFilter.h"
#include "NavFilter_AIControllerBehavior.generated.h"

UCLASS(Blueprintable)
class UNavFilter_AIControllerBehavior : public UNavigationQueryFilter {
    GENERATED_BODY()
public:
    UNavFilter_AIControllerBehavior();

};

