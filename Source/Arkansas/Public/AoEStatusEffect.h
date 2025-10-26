#pragma once
#include "CoreMinimal.h"
#include <TransformedShape.h>
#include "StatusEffect.h"
#include "Templates/SubclassOf.h"
#include "AoEStatusEffect.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAoEStatusEffect : public UStatusEffect {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransformedShape CollisionShape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyFriendlyTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyHostileTargets;
    
public:
    UAoEStatusEffect();

};

