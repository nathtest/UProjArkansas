#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "StatusEffect.h"
#include "AITargetWeakSpotsStatusEffect.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ARKANSAS_API UAITargetWeakSpotsStatusEffect : public UStatusEffect {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ValidCreatureTypes;
    
public:
    UAITargetWeakSpotsStatusEffect();

};

