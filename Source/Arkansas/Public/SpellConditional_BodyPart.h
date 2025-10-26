#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "SpellConditional.h"
#include "SpellConditional_BodyPart.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ARKANSAS_API USpellConditional_BodyPart : public USpellConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag BodyPartTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDamaged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDestroyed;
    
public:
    USpellConditional_BodyPart();

};

