#pragma once
#include "CoreMinimal.h"
#include "Engine\DamageEvents.h"

#include "IndianaGenericDamageEvent.generated.h"

USTRUCT(BlueprintType)
struct FIndianaGenericDamageEvent : public FDamageEvent {
    GENERATED_BODY()
public:
    ARKANSAS_API FIndianaGenericDamageEvent();
};

