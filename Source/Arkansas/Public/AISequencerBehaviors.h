#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=SoftClassPath -FallbackName=SoftClassPath
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include <GameplayTagContainer.h>
#include <MovieSceneObjectBindingID.h>
#include "AIOrientationControl.h"
#include "AIWeaponFiringSettings.h"
#include "CauseDamageInfo.h"
#include "EArmorSlot.h"
#include "EStageMarkAssignmentType.h"
#include "ETrackingRegion.h"
#include "ForceBodyTrackingAngleParams.h"
#include "ItemDefinitionVariant.h"
#include "AISequencerBehaviors.generated.h"

class AIndianaAiCharacter;
class UAnimMontage;
class UOwConversationInstance;
class UWeapon;

UCLASS(Blueprintable, Const, DefaultConfig, Config=Game)
class ARKANSAS_API UAISequencerBehaviors : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftClassPath AISequencerBehaviorsClassName;
    
public:
    UAISequencerBehaviors();

    UFUNCTION(BlueprintCallable)
    static void VaultToLocation(AIndianaAiCharacter* Character, FVector LocalLandingLocation, FVector LocalLedgeFrontLocation, FVector LocalLedgeBackLocation);
    
    UFUNCTION(BlueprintCallable)
    static void UsePreviousAnimProxy(AIndianaAiCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void UseAnimProxy(AIndianaAiCharacter* Character, FMovieSceneObjectBindingID AnimProxyInteractableBinding, const FGameplayTag SlotKey, const bool bTeleport, const bool bTeleportOnMoveFail, const bool bInterruptOnMove, const bool bInfiniteDuration, const bool bAutoDeactivate);
    
    UFUNCTION(BlueprintCallable)
    static void UnequipArmorInSlot(AIndianaAiCharacter* Character, EArmorSlot ArmorSlot);
    
    UFUNCTION(BlueprintCallable)
    static void TriggerQuickMelee(AIndianaAiCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void Suicide(AIndianaAiCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void StopUsingAnimProxy(AIndianaAiCharacter* Character, bool bSkipProxyExit, bool bExitImmediatelyOnNodeSkip);
    
protected:
    //UFUNCTION(BlueprintCallable)
    void ShootTarget_SwitchToNeutralAnimState(TWeakObjectPtr<AIndianaAiCharacter> InCharacter, bool bInstantBlend) const;
    
    //UFUNCTION(BlueprintCallable)
    void ShootTarget_StopShooting(TWeakObjectPtr<AIndianaAiCharacter> InCharacter) const;
    
    UFUNCTION(BlueprintCallable)
    void ShootTarget_OnWeaponAttack(UWeapon* Weapon) const;
    
    UFUNCTION(BlueprintCallable)
    void ShootTarget_OnTargetTakenDamage(const FCauseDamageInfo& CauseDamageInfo) const;
    
    UFUNCTION(BlueprintCallable)
    void ShootTarget_OnPlayerSkippedNode(UOwConversationInstance* InConversationInstance) const;
    
    //UFUNCTION(BlueprintCallable)
    void ShootTarget_CombatStateFullyBlended(TWeakObjectPtr<AIndianaAiCharacter> InCharacter) const;
    
public:
    UFUNCTION(BlueprintCallable)
    static void ShootTarget(AIndianaAiCharacter* Character, const FMovieSceneObjectBindingID& Target, int32 NumOfShots, int32 InstantKillShotIndex, FName SocketOnTarget, bool bShouldDismemberOnKill, bool bBlendAnimationState);
    
    UFUNCTION(BlueprintCallable)
    static void SetOrientation(AIndianaAiCharacter* Character, TEnumAsByte<ETrackingRegion> TrackingRegion, FAIOrientationControl AIOrientationControl);
    
    UFUNCTION(BlueprintCallable)
    static void SetHeadTrackingLockState(AIndianaAiCharacter* Character, bool bLocked, bool bMaintainCurrentOrientation);
    
    UFUNCTION(BlueprintCallable)
    static void SetConversationLookAtTarget(AIndianaAiCharacter* Character, const FMovieSceneObjectBindingID& Binding, bool bPersist, bool bTurnBody, bool bSnapToLookAtOnNodeSkipped, const FForceBodyTrackingAngleParams& ExactAngleParams);
    
    UFUNCTION(BlueprintCallable)
    static void SetConversationBodyRotationComfortAngle(AIndianaAiCharacter* Character, float Angle, bool bReevaluateBodyAngle);
    
    UFUNCTION(BlueprintCallable)
    static void SetCanUnequipWeapon(AIndianaAiCharacter* Character, bool bCanUnequip);
    
    UFUNCTION(BlueprintCallable)
    static void SetBodyTrackingLockState(AIndianaAiCharacter* Character, bool bLocked, bool bMaintainCurrentOrientation);
    
    UFUNCTION(BlueprintCallable)
    static void SetBodyTrackingIgnoreState(AIndianaAiCharacter* Character, TEnumAsByte<ETrackingRegion> TrackingRegion, bool bIgnoreBodyTracking);
    
    UFUNCTION(BlueprintCallable)
    static void ResetConversationBodyRotationComfortAngle(AIndianaAiCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveForcedBodyAngleRelativeToTarget(AIndianaAiCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveCurrentStageMarkLock(AIndianaAiCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterConversationParticipant(AIndianaAiCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void PlayMotionWarpingAnimMontage(AIndianaAiCharacter* Character, UAnimMontage* MontageToPlay, TArray<FTransform> LocalSyncTransforms);
    
    UFUNCTION(BlueprintCallable)
    static void PlayAnimMontage(AIndianaAiCharacter* Character, UAnimMontage* MontageToPlay);
    
    UFUNCTION(BlueprintCallable)
    static void MantleToLocation(AIndianaAiCharacter* Character, FVector LocalLandingLocation, FVector LocalLedgeLocation);
    
    UFUNCTION(BlueprintCallable)
    static void JumpAcrossToLocation(AIndianaAiCharacter* Character, FVector LocalLandingLocation, float HeightOverride);
    
    UFUNCTION(BlueprintCallable)
    static void HolsterWeapon(AIndianaAiCharacter* Character, bool bInstant);
    
    UFUNCTION(BlueprintCallable)
    static void FireWeaponStop(AIndianaAiCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void FireWeaponStart(AIndianaAiCharacter* Character, const FAIWeaponFiringSettings& AIWeaponFiringSettings);
    
    UFUNCTION(BlueprintCallable)
    static void ExitSequencer(AIndianaAiCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void EquipWeaponByTag(AIndianaAiCharacter* Character, const FGameplayTag Tag, bool bInstant);
    
    UFUNCTION(BlueprintCallable)
    static void EquipWeaponBySlot(AIndianaAiCharacter* Character, int32 SlotIndex, bool bInstant);
    
    UFUNCTION(BlueprintCallable)
    static void EquipWeaponByInstance(AIndianaAiCharacter* Character, const UWeapon* Weapon, bool bInstant);
    
    UFUNCTION(BlueprintCallable)
    static void EquipItem(AIndianaAiCharacter* Character, const FItemDefinitionVariant& ItemDefinition);
    
    UFUNCTION(BlueprintCallable)
    static void DropDownToLocation(AIndianaAiCharacter* Character, FVector LocalLandingLocation, FVector LocalLedgeLocation);
    
    UFUNCTION(BlueprintCallable)
    static void ClearPersistentLookAtTarget(AIndianaAiCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void ClearOrientation(AIndianaAiCharacter* Character, TEnumAsByte<ETrackingRegion> TrackingRegion);
    
    UFUNCTION(BlueprintCallable)
    static void ClearAllOrientation(AIndianaAiCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void CallGroupBehaviorEvent(AIndianaAiCharacter* Character, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    static void AssignStageMark(AIndianaAiCharacter* Character, FMovieSceneObjectBindingID StageMarkActorBinding, EStageMarkAssignmentType StageMarkAssignmentType, bool bApplyStageMarkLock, bool bTeleportOnNodeSkipped);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyForcedBodyAngleRelativeToTarget(AIndianaAiCharacter* Character, float InAngle);
    
};

