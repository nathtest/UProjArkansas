#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "AttackFilterConditional.h"
#include "AttackFilterConditional_IsCreatureType.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAttackFilterConditional_IsCreatureType : public UAttackFilterConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CreatureTypes;
    
public:
    UAttackFilterConditional_IsCreatureType();

};

