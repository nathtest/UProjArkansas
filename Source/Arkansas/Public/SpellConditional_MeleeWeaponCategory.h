#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "SpellConditional.h"
#include "SpellConditional_MeleeWeaponCategory.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpellConditional_MeleeWeaponCategory : public USpellConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag WeaponCategory;
    
public:
    USpellConditional_MeleeWeaponCategory();

};

