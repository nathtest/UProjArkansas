#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "Templates/SubclassOf.h"
#include "SpellEffectApplyChance.generated.h"

class USpell;

USTRUCT(BlueprintType)
struct FSpellEffectApplyChance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer BodyParts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<USpell>, float> SpellApplyChances;
    
    ARKANSAS_API FSpellEffectApplyChance();
};

