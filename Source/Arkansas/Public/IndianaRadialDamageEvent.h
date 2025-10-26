#pragma once
#include "CoreMinimal.h"
#include "Engine\DamageEvents.h"

#include "IndianaRadialDamageEvent.generated.h"

USTRUCT(BlueprintType)
struct FIndianaRadialDamageEvent : public FRadialDamageEvent {
    GENERATED_BODY()
public:
    ARKANSAS_API FIndianaRadialDamageEvent();
};

