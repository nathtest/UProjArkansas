#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "StatusEffect.h"
#include "DamageByGameTagStatusEffect.generated.h"

class URpgStat;

UCLASS(Blueprintable, EditInlineNew)
class UDamageByGameTagStatusEffect : public UStatusEffect {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URpgStat* RpgStat;
    
public:
    UDamageByGameTagStatusEffect();

};

