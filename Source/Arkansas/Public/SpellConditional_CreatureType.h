#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "SpellConditional.h"
#include "SpellConditional_CreatureType.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpellConditional_CreatureType : public USpellConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CreatureTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNegateCheck;
    
public:
    USpellConditional_CreatureType();

};

