#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "SpellConditional.h"
#include "SpellConditional_IsCreatureType.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpellConditional_IsCreatureType : public USpellConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CreatureTypes;
    
public:
    USpellConditional_IsCreatureType();

};

