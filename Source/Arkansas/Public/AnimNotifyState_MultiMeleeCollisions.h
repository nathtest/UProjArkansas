#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include <GameplayTagContainer.h>
#include "Templates/SubclassOf.h"
#include "AnimNotifyState_MultiMeleeCollisions.generated.h"

class UStatusEffect;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_MultiMeleeCollisions : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTag> MeleeCollisionTriggers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStatusEffect>> StatusEffectsToApplyIfMeleeCausesDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStatusEffect>> StatusEffectsToAlwaysApply;
    
    UAnimNotifyState_MultiMeleeCollisions();

};

