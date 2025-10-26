#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "SpellConditional.h"
#include "SpellConditional_IsImmune.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpellConditional_IsImmune : public USpellConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ImmuneTag;
    
public:
    USpellConditional_IsImmune();

};

