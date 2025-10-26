#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include <GameplayTagContainer.h>
#include "Templates/SubclassOf.h"
#include "AnimNotifyState_MeleeDamage.generated.h"

class UStatusEffect;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_MeleeDamage : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag MeleeCollisionTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpellAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStatusEffect>> StatusEffectsToApplyIfMeleeCausesDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStatusEffect>> StatusEffectsToAlwaysApply;
    
    UAnimNotifyState_MeleeDamage();

};

