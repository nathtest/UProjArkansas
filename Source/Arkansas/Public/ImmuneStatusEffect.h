#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "StatusEffect.h"
#include "Templates/SubclassOf.h"
#include "ImmuneStatusEffect.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class UImmuneStatusEffect : public UStatusEffect {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer DisableTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> OriginActorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ImmuneGameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsHostileEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClearExistingEffects;
    
public:
    UImmuneStatusEffect();

};

