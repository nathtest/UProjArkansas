#pragma once
#include "CoreMinimal.h"
#include "NavFilters/NavigationQueryFilter.h"
#include "AutoplayerVisitedNavigationQueryFilter.generated.h"

UCLASS(Blueprintable)
class UAutoplayerVisitedNavigationQueryFilter : public UNavigationQueryFilter {
    GENERATED_BODY()
public:
    UAutoplayerVisitedNavigationQueryFilter();

};

