#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "AttackFilterConditional.h"
#include "AttackFilterConditional_IsDamageDescriptionGameplayTag.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAttackFilterConditional_IsDamageDescriptionGameplayTag : public UAttackFilterConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredTagsAll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredTagsAny;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RestrictedTagsAny;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RestrictedTagsAll;
    
public:
    UAttackFilterConditional_IsDamageDescriptionGameplayTag();

};

