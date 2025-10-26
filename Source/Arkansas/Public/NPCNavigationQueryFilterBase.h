#pragma once
#include "CoreMinimal.h"
#include "NavFilters/NavigationQueryFilter.h"
#include "NPCNavigationQueryFilterBase.generated.h"

UCLASS(Abstract, Blueprintable)
class UNPCNavigationQueryFilterBase : public UNavigationQueryFilter {
    GENERATED_BODY()
public:
    UNPCNavigationQueryFilterBase();

};

