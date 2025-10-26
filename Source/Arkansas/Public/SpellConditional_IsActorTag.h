#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "SpellConditional.h"
#include "SpellConditional_IsActorTag.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpellConditional_IsActorTag : public USpellConditional {
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
    USpellConditional_IsActorTag();

};

