#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <AnimationProxyRuntime.h>
#include <BodyIdle.h>
#include <FacialIdle.h>
#include "OEIAnimInstance.h"
#include <RelativeIKConfig.h>
#include "RelativeIKConfigProviderInterface.h"
#include <BreakBoneInfo.h>
#include <AnimationProxyRuntime.h>
#include "OEICCAnimInterface.h"
#include "AnimatedIKData.h"
#include "BreakBoneInfo_Legacy.h"
#include "EFootID.h"

#include "LocomotionAnimInstanceRuntimeData.h"
#include "LocomotionAnimationState.h"
#include "OwAnimInstance.generated.h"


class UAnimMontage;
class ULocomotionAnimationData;
class ULocomotionLogicComponent;

UCLASS(Blueprintable, NonTransient)
class UOwAnimInstance : public UOEIAnimInstance, public IRelativeIKConfigProviderInterface, public IOEICCAnimInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSpeedIsRun;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBreakBoneInfo_Legacy> BreakBoneConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBreakBoneInfo> NewBreakBoneConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float IKLeftHandAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float IKRightHandAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float AltHandIKLeftAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float AltHandIKRightAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float IKBlendTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float UnscaledIKLeftHandAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float UnscaledIKRightHandAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentIKStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float DisableIKBlendTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimatedIKData LeftWristData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimatedIKData RightWristData;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FootDownDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FootUpDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, EFootID> GameplayTagToFootID;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFootIKEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bFootIKState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IKInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LegIKStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRelativeIKConfig> RelativeIKConfigs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationProxyRuntime AnimProxyRuntime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFacialIdle FacialIdle0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFacialIdle FacialIdle1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBodyIdle BodyIdle0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBodyIdle BodyIdle1;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLocomotionAnimationState LocoAnimState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToLookAheadForLeansForWalk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeToLookAheadForLeansForRun;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeanScaling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocomotionAnimationData* DefaultLocomotionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULocomotionAnimationData* DefaultCombatLocomotionAnimData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBlendLocomotionStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULocomotionAnimationData* CombatLocomotionAnimData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULocomotionAnimationData* NonCombatLocomotionAnimData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    ULocomotionLogicComponent* LocomotionController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLocomotionAnimInstanceRuntimeData CombatLocomotionRuntime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLocomotionAnimInstanceRuntimeData NonCombatLocomotionRuntime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsLocomotionActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float SlopeAdditiveAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlopeAdditiveAlphaInterpSpeed;
    
    UOwAnimInstance();

    UFUNCTION(BlueprintCallable)
    float Montage_SkipToEnd(UAnimMontage* MontageToPlay);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnyRootMotionMontagePlaying() const;
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_ToggleFootIK();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_EnableFootIK();
    
    UFUNCTION(BlueprintCallable)
    void AnimNotify_DisableFootIK();
    

    // Fix for true pure virtual functions not being implemented
};

