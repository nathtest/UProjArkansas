#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include <GameplayTagContainer.h>
#include "AISettings_Block.h"
#include "AISettings_CoverFire.h"
#include "AISettings_Dodge.h"
#include "AISettings_FiringPattern.h"
#include "AISettings_FleeDanger.h"
#include "AISettings_Melee.h"
#include "AISettings_Positioning.h"
#include "AISettings_RangedBehavior.h"
#include "EDefaultFiringPatternType.h"
#include "EWeaponFireType.h"
#include "AISettings_Weapon.generated.h"

UCLASS(Blueprintable)
class UAISettings_Weapon : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeaponFireType WeaponFireType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAISettings_Melee Melee;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDefaultFiringPatternType DefaultFiringPatternType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAISettings_FiringPattern DefaultFiringPattern;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangedStartWaitTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangedDesiredTimeBetweenTriggerPulls;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangedMaxMissedTargetCollisionDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FAISettings_FiringPattern> SupportedFiringPatternPresets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAISettings_CoverFire CoverFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAISettings_RangedBehavior RangeBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAISettings_Positioning Positioning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAISettings_Block Block;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAISettings_Dodge Dodge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAISettings_FleeDanger Flee;
    
    UAISettings_Weapon();

};

