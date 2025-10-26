#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "ESkill.h"
#include "Templates/SubclassOf.h"
#include "SkillUnlockEffect.generated.h"

class USpell;

USTRUCT(BlueprintType)
struct FSkillUnlockEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkill EquippedWeaponSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpell> Spell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString UnlockTierString;
    
    ARKANSAS_API FSkillUnlockEffect();
};

