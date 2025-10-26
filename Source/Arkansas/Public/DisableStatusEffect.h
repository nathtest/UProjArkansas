#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "StatusEffect.h"
#include "DisableStatusEffect.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UDisableStatusEffect : public UStatusEffect {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DisableType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRotateToFace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHeadTrackToCaster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClearAwareness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowGroupBehaviorParticipation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceInterruptPriority;
    
public:
    UDisableStatusEffect();

};

