#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "StatusEffect.h"
#include "Templates/SubclassOf.h"
#include "KillStatusEffect.generated.h"

class UIndianaDamageType;

UCLASS(Blueprintable, EditInlineNew)
class UKillStatusEffect : public UStatusEffect {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UIndianaDamageType> DamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowFriendlyFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSuicide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreventRevive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString DeathDescription;
    
public:
    UKillStatusEffect();

};

