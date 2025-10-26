#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "EStatusEffectCheckType.h"
#include "EventListener.h"
#include "Templates/SubclassOf.h"
#include "OnStatusEffect.generated.h"

class UStatusEffect;

UCLASS(Blueprintable, EditInlineNew)
class UOnStatusEffect : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStatusEffectCheckType EventType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StackCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UStatusEffect>> StatusEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator HostileComparisonOperator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumHostileStatusEffects;
    
public:
    UOnStatusEffect();

};

