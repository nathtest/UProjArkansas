#pragma once
#include "CoreMinimal.h"
#include "Engine\DamageEvents.h"

#include "IndianaPointDamageEvent.generated.h"

USTRUCT(BlueprintType)
struct FIndianaPointDamageEvent : public FPointDamageEvent {
    GENERATED_BODY()
public:
    ARKANSAS_API FIndianaPointDamageEvent();
};

