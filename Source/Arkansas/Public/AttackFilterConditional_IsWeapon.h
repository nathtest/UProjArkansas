#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <EComparisonOperator.h>
#include "AttackFilterConditional.h"
#include "ESkill.h"
#include "AttackFilterConditional_IsWeapon.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAttackFilterConditional_IsWeapon : public UAttackFilterConditional {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag WeaponCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator HasMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ModCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCompareMagPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MagPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator MagPercentOperator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkill Skill;
    
public:
    UAttackFilterConditional_IsWeapon();

};

