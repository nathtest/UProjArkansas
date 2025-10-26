#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "CauseDamageInfo.h"
#include "EDamageFlags.h"
#include "ESkill.h"
#include "FactionListener.h"
#include "Templates/SubclassOf.h"
#include "OnCausedDamage.generated.h"

class UIndianaDamageType;

UCLASS(Blueprintable, EditInlineNew)
class UOnCausedDamage : public UFactionListener {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, NoClear, meta=(AllowPrivateAccess=true))
    TArray<EDamageFlags> CheckDamageFlags;
    
    UPROPERTY(EditAnywhere, NoClear, meta=(AllowPrivateAccess=true))
    TArray<EDamageFlags> CheckNotDamageFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTriggerOnZeroDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPassThroughDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOneCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsTargetWeak;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PassThroughDamageScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDesiredDamageAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UIndianaDamageType> DamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkill Skill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
public:
    UOnCausedDamage();

protected:
    UFUNCTION(BlueprintCallable)
    void OnCauseDamage(const FCauseDamageInfo& CauseDamageInfo);
    
};

