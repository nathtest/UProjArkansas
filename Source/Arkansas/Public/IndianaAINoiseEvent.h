#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=AINoiseEvent -FallbackName=AINoiseEvent
#include "Perception/AISense_Hearing.h"

#include "IndianaAINoiseEvent.generated.h"

USTRUCT(BlueprintType)
struct FIndianaAINoiseEvent : public FAINoiseEvent {
    GENERATED_BODY()
public:
    ARKANSAS_API FIndianaAINoiseEvent();
};

