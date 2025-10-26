#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "StatusEffect.h"
#include "PerceptionRangeScalarStatusEffect.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPerceptionRangeScalarStatusEffect : public UStatusEffect {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CreatureType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionRangeScalar;
    
public:
    UPerceptionRangeScalarStatusEffect();

};

