#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Quat -FallbackName=Quat
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include <GameplayTagContainer.h>
#include "AnimationProxyResponderInterface.h"
#include "AIBehaviorClassUserReferenceInterface.h"
#include "AICinematicModeParams.h"
#include "AISettingsWander.h"
#include "BodyPartDestruction.h"
#include "CauseDamageInfo.h"
#include "CoverActionAnim.h"
#include "EAIMovementState.h"
#include "EAlertState.h"
#include "EAnimTreeState.h"
#include "ECautiousBehaviorType.h"
#include "ECoverActions.h"
#include "ECoverSide.h"
#include "EEmotion.h"
#include "EInteractionType.h"
#include "ELocomotionStateEnum.h"
#include "ELostTargetSearchMode.h"
#include "EPatrolType.h"
#include "ETrackingRegion.h"
#include "ETraverseType.h"
#include "IndianaCharacter.h"
#include "OnCanUseCoverChangedDelegate.h"
#include "OnCompanionDismissedDelegate.h"
#include "OnDespawnedDelegate.h"
#include "OnDormancyChangedDelegate.h"
#include "OnMeleeNavPathFindDelegate.h"
#include "OnReceivedFriendlyFireDelegate.h"
#include "OnTeleportCharacterCompletedDelegate.h"
#include "StatusEffectInstanceHandle.h"
#include "Templates/SubclassOf.h"
#include "GameplayTask.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Controller.h"
#include "IndianaAiCharacter.generated.h"

class AActor;
class AAnimationProxyActor;
class ACoverNode;
class AEncounter;
class AHardPoint;
class AHazard;
class AIndianaAiController;
class ALadder;
class APatrolNode;
class AReservableNavLink;
class AStageMarkActor;
class AStagePrefabActor;
class UAIDefensiveActionsComponent;
class UAIInteractionComponent;
class UAIPatrolSupportComponent;
class UAIProjectileLogic;
class UAISettingsComponent;
class UAiTargetingComponent;
class UAnimMontage;
class UAnimationProxyData;
class UCompanionComponent;
class UEmotionData;
class UEquipmentComponent;
class UGameplayTasksComponent;
class UHeadAndBodyTrackingComponent;
class UHealthComponent;
class UInteractableComponent;
class UOEICineConversationInstance;
class UOEIWwiseEmitterComponent;
class UObject;
class UOwBlackboardData;
class UPersonalSpaceComponent;
class UPoseAsset;
class UStatusTagStaticMeshComponent;
class UTPVAnimInstance;
class UTPVPersonalityCollection;
class UWeapon;
class UWeaponAnimationsCreature;
class UWeaponAnimationsTPV;

UCLASS(Blueprintable)
class ARKANSAS_API AIndianaAiCharacter : public AIndianaCharacter, public IAIBehaviorClassUserReferenceInterface, public IAnimationProxyResponderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnReceivedFriendlyFire OnReceivedFriendlyFireDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCanUseCoverChanged OnCanUseCoverChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsingCoverMontages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCoverIdlesAndDisableLocomotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AcceptableErrorAngleForCoverEntry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DisableParkourCount;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDespawned OnDespawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCompanionDismissed OnCompanionDismissed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector OverrideAnchorPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStatusTagSuppressed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCompanionComponent* CompanionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAISettingsComponent* AISettingsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIInteractionComponent* InteractionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAiTargetingComponent* AiTargetingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHeadAndBodyTrackingComponent* HeadAndBodyTrackingComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIPatrolSupportComponent* PatrolSupportComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPersonalSpaceComponent* PersonalSpaceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIDefensiveActionsComponent* DefensiveActionsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameplayTasksComponent* GameplayTasksComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOEIWwiseEmitterComponent* EmitterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTPVAnimInstance* AnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTPVPersonalityCollection* Personality;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasWeaponInNonCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AimOriginSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAimOriginLowerToFeet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimOriginVerticalOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimOriginForwardOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CarryingCapacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsolated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldIgnorePlayerDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnorePlayerPlacedTraps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeapon* WeaponHeldBeforeConversationStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOwBlackboardData* CustomBlackboardData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EInteractionType> InteractionOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EInteractionType> InteractionAdditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DistanceToAlwaysEvaluateAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartCombatAnimationStateDelay;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPoseAsset* DefaultMaleEyePoseAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPoseAsset* DefaultFemaleEyePoseAsset;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTeleportCharacterCompleted OnTeleportCharacterCompleted;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEmotionData* EmotionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasDefaultEmotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEmotion DefaultEmotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseFactionReactionEmotions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEmotion GoodReaction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEmotion NeutralReaction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEmotion BadReaction;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationProxyData* AnimationProxyData;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDowned;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAIProjectileLogic* AIProjectileLogic;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShroudDelayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FBodyPartDestruction> BodyPartDestructionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FBodyPartDestruction> BodyPartRuntimeData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BodyPartDespawnTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> DestructibleHardReferences;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLeftCannisterIntact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRightCannisterIntact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLeftCannisterDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRightCannisterDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AHardPoint* HardPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStayOnHardPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableAutomaticHardPointAssignment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanJoinAnyHardPoint;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatusTagStaticMeshComponent* StatusTagSMComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStatusEffectInstanceHandle> ActiveDisableStatusEffects;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDormancyChanged OnDormancyChangedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JumpAnticTimer;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseTightRadialDamageBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag LockOnBodyPartTargetOverride;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMeleePositionEnable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMeleePositionActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector MeleePosition;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeleeCheckBodyOrientationForgivenessAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeleeCheckCapsuleRadiusMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinMeleeAttackCapsuleDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinMeleeBurrowAttackCapsuleDistance;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsCaged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BurrowTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWantsToBurrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAnimBurrowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BurrowAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBurrowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBurrowingDownOrUp;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldOrientBeforeMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CurrentPersonalityTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAdditionalPersonalityOverridesWeapon;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugTrap;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AHazard> HazardToSpawnOnDeath;
    
public:
    AIndianaAiCharacter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool ValidateProjectileFiringLocation(FVector Location, FVector Direction);
    
    UFUNCTION(BlueprintCallable)
    void TurretEngageActor(AActor* ActorToEngage);
    
    UFUNCTION(BlueprintCallable)
    void SwitchPersonality(const FGameplayTag& PersonalityTag, bool bOverrideWeaponPersonality);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldOrientBeforeMoving();
    
    UFUNCTION(BlueprintCallable)
    bool SetThrowGrenadeTimer(FName Channel, float Chance, bool bPerformCheck);
    
    UFUNCTION(BlueprintCallable)
    void SetStatusTagSuppressed(bool bSuppressed);
    
    UFUNCTION(BlueprintCallable)
    void SetOrigin(const FTransform& NewTransform);
    
    UFUNCTION(BlueprintCallable)
    void SetOccupyLocation(FVector Location, float Time);
    
    UFUNCTION(BlueprintCallable)
    void SetNamedCooldown(const FName& Name, float Time);
    
    UFUNCTION(BlueprintCallable)
    void SetMinMeleeBurrowAttackCapsuleDistance(float InCapsuleDistance);
    
    UFUNCTION(BlueprintCallable)
    void SetMinMeleeAttackCapsuleDistance(float InCapsuleDistance);
    
    UFUNCTION(BlueprintCallable)
    void SetIgnorePlayerPlacedTraps(bool bShouldIgnorePlayerPlacedTraps);
    
    UFUNCTION(BlueprintCallable)
    void SetIgnoreDistractionDevices(bool bShouldIgnoreDistractionDevices);
    
    UFUNCTION(BlueprintCallable)
    void SetHardPoint(AHardPoint* InHardPoint);
    
    UFUNCTION(BlueprintCallable)
    void SetCinematicModeEnabled(bool bEnable, const FAICinematicModeParams& Params);
    
    UFUNCTION(BlueprintCallable)
    void SetCanUseCover(bool bNewCanUseCover);
    
    UFUNCTION(BlueprintCallable)
    void SetCanUnequipWeapon(bool bCanUnequip);
    
    UFUNCTION(BlueprintCallable)
    void SetCanTether(bool bInCanTether);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetAnchorOverrideLocation(FVector OverrideLocation);
    
    UFUNCTION(BlueprintCallable)
    void SetAnchoredToPlayer(bool bAnchored);
    
public:
    UFUNCTION(BlueprintCallable)
    void ResetOriginTransform();
    
    UFUNCTION(BlueprintCallable)
    void RefreshAI();
    
    UFUNCTION(BlueprintCallable)
    float RangedCheckFromLocation(FVector FeetLocation);
    
    UFUNCTION(BlueprintCallable)
    float RangedCheck();
    
    UFUNCTION(BlueprintCallable)
    bool PlayCoverMontageWithWarp(ACoverNode* CoverNode, UAnimMontage* AnimMontage, FVector DestLocation, FVector DestAngle, bool bUseMontageDelta, bool bAdjustForTarget, bool bAdjustAngleForTarget, bool bReturnToNode);
    
    UFUNCTION(BlueprintCallable)
    UAnimMontage* PickCoverDestroyedReaction(ACoverNode* CoverNode, ECoverSide& OutCurrentCoverSide);
    
    UFUNCTION(BlueprintCallable)
    bool PickCoverAction(ACoverNode* CoverNode, ECoverActions ActionFilter, ECoverActions& OutCoverAction, FCoverActionAnim& OutCoverActionAnim, ECoverActions PreferredAction);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnWeaponEndUnequip(UEquipmentComponent* InEquipmentComponent, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponEndEquip(UEquipmentComponent* InEquipmentComponent, UWeapon* Weapon);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnMontageEndDelegate(UAnimMontage* Montage, bool bInterrupted);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnLootGenerated();
    
    UFUNCTION(BlueprintCallable)
    void OnLocomotionStateUpdated(ELocomotionStateEnum NewState);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnDeferredMovementFinished(bool bSuccess);
    
    UFUNCTION(BlueprintCallable)
    void OnDamageEvent(const FCauseDamageInfo& CauseDamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCoverRetractStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCoverDeployStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCoverDeployAntic();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnAlertStateChange(AActor* TargetActor, EAlertState PreviousAlertState, EAlertState TargetAlertState, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void OnAIStartTraverse(ETraverseType TraverseType, int32 NavLinkDirection, AReservableNavLink* ReservableNavLink, ALadder* ClimbLadder);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActorHiddenChange(bool bIsHidden);
    
    UFUNCTION(BlueprintCallable)
    void OccupyNearbyCoverOnDowned(float CoverNodeOccupationPadding);
    
    UFUNCTION(BlueprintCallable)
    bool MeleeReachable(bool bDebug);
    
    UFUNCTION(BlueprintCallable)
    bool MeleeNavWalk(FVector Start, FVector Target, FVector& End);
    
    UFUNCTION(BlueprintCallable)
    void MeleeNavPathFindCancel();
    
    UFUNCTION(BlueprintCallable)
    void MeleeNavPathFind(const FOnMeleeNavPathFind& Delegate, FVector Destination);
    
    UFUNCTION(BlueprintCallable)
    bool MeleeCheckFromLocation(FVector GroundLocation, float CapsuleDistance, float WidthRadius, bool bNavTrace, bool bDebug, const FName CooldownName, bool bRunExtraGeometryAvoidanceTests, float GeoAvoidanceWidthPadding, bool bIgnoreOtherCharacters);
    
    UFUNCTION(BlueprintCallable)
    bool MeleeCheck(float CapsuleDistance, float WidthRadius, bool bFacingTarget, bool bNavTrace, bool bDebug, bool bUseBurrowCheck, const FName CooldownName, bool bRunExtraGeometryAvoidanceTests, float GeoAvoidanceWidthPadding);
    
protected:
    UFUNCTION(BlueprintCallable)
    void K2_SetUseSearchingAnimLayer(const bool bSet);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetInteractionTarget(UInteractableComponent* InInteractionTarget);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetInteractionOverrides(TArray<EInteractionType> Interactions);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetInteractionAdditions(TArray<EInteractionType> Interactions);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetAnimationState(const EAnimTreeState AnimationState);
    
    UFUNCTION(BlueprintCallable)
    void K2_RemoveInteractionOverride(EInteractionType Interaction);
    
    UFUNCTION(BlueprintCallable)
    void K2_RemoveInteractionAddition(EInteractionType Interaction);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsTrackingRegionFacingTarget(TEnumAsByte<ETrackingRegion> TrackingRegion, float Tolerance) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsRegionNearGoal(TEnumAsByte<ETrackingRegion> Region, float DeltaDegrees) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsPacifist() const;
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsEndangered() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_GetShouldIgnoreDistractionDevices() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator K2_GetRegionGoalRotation(TEnumAsByte<ETrackingRegion> Region) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator K2_GetRegionGoalRemainingRotation(TEnumAsByte<ETrackingRegion> Region) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetRegionGoalRemainingDegrees(TEnumAsByte<ETrackingRegion> Region) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector K2_GetRegionCurrentTargetLocation(TEnumAsByte<ETrackingRegion> Region, bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator K2_GetRegionCurrentRotation(TEnumAsByte<ETrackingRegion> Region) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FQuat K2_GetOriginRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector K2_GetOriginLocation() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator K2_GetHeadRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector K2_GetHeadLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UWeaponAnimationsTPV* K2_GetCurrentWeaponAnimations() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UWeaponAnimationsCreature* K2_GetCurrentCreatureWeaponAnimations() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_GetCompanionFollowTargetLocation(FVector& OutFollowTargetLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAnimTreeState K2_GetAnimationState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator K2_GetAimRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector K2_GetAimOriginLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void K2_GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const;
    
    UFUNCTION(BlueprintCallable)
    void K2_ClearInteractionOverrides();
    
    UFUNCTION(BlueprintCallable)
    void K2_ClearInteractionAdditions();
    
    UFUNCTION(BlueprintCallable)
    void K2_AddInteractionOverride(EInteractionType Interaction);
    
    UFUNCTION(BlueprintCallable)
    void K2_AddInteractionAddition(EInteractionType Interaction);
    
public:
    UFUNCTION(BlueprintCallable)
    bool JumpTo(FVector Destination);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsingAnimationProxy(AAnimationProxyActor* AnimationProxyActor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetClearWorld();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetClearOfGrenadeFriendlyFireFromLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetClearOfGrenadeFriendlyFire();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetClearOfFriendlyFireFromLocation(FVector Location, bool bForMelee);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetClearOfFriendlyFire();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStatusTagSuppressed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNavLoadedAtFeetLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNamedCooldownRunning(const FName& Name);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsJumping();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsElongated() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDormant() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCompanion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnimationProxyTaskInProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnimationProxyTaskComplete() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnchoredToPlayer() const;
    
    UFUNCTION(BlueprintCallable)
    void HazardSpawned(AActor* Hazard, bool bSuccess);
    
public:
    UFUNCTION(BlueprintCallable)
    bool GetWanderSettingsFromSpawnModifiers(FAISettingsWander& OutWanderSettings, const bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTargetsSimpleCapsuleRadiusForMelee() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStationaryTime() const;
    
    UFUNCTION(BlueprintCallable)
    APatrolNode* GetPatrolNodeFromSpawnModifiers(EPatrolType& OutPatrolType, bool& OutWantTeleport, const bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable)
    bool GetPatrolNavigationFlagsFromSpawnModifiers(int32& OutNavigationFlags, bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AIndianaAiController* GetOwningController() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetOverrideOriginFromSpawnModifiers(FVector& OutOrigin, const bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable)
    float GetOutOfCombatStartDelay(const bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetOccupyScore(FVector Location, float Radius, bool bLineOfSight, bool bIgnoreFurther, bool bIgnoreCorpses);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetOccupyLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumAIBuffZones();
    
    UFUNCTION(BlueprintCallable)
    TArray<AIndianaCharacter*> GetNearbyCharacters();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMinMeleeBurrowAttackCapsuleDistance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMinMeleeAttackCapsuleDistance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ELostTargetSearchMode GetLostTargetSearchMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsAiMeleeStallDebugEnabled() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetIdleMovementState(EAIMovementState& OutMovementState, const bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable)
    bool GetFollowPlayerFromSpawnModifiers(bool& OutCanCrouch, const bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable)
    AActor* GetFollowBehaviorFromSpawnModifiers(float& OutMinRange, float& OutMaxRange, float& OutRunRange, const bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEncounter* GetEncounter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetElongatedCenter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDefaultMoveToLocationAcceptanceRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDamageMemory(FVector Location) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimMontage* GetCoverActionMontage();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCompanionComponent* GetCompanionComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECautiousBehaviorType GetCautiousBehaviorType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCapsuleDistanceToActor(const AActor* InTargetActor) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetAnimationProxyTeleportBehaviorFromSpawnModifiers(const bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable)
    bool GetAnimationProxyNavigationFlagsFromSpawnModifiers(int32& OutNavigationFlags, const bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable)
    bool GetAnimationProxyMovementStateFromSpawnModifiers(EAIMovementState& OutMovementState, const bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable)
    AAnimationProxyActor* GetAnimationProxyActorFromSpawnModifiers(const bool bIncludeDefaultBehavior);
    
    UFUNCTION(BlueprintCallable)
    void EnableParkour();
    
    UFUNCTION(BlueprintCallable)
    void DisableParkour();
    
    UFUNCTION(BlueprintCallable)
    bool CombatShouldHide(bool bDebug);
    
    UFUNCTION(BlueprintCallable)
    bool CombatShouldFallback(bool bDebug);
    
    UFUNCTION(BlueprintCallable)
    bool CombatReachable(bool bDebug);
    
    UFUNCTION(BlueprintCallable)
    void ClearNamedCooldown(const FName& Name);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CheckThrowGrenadeTimer(FName Channel);
    
    UFUNCTION(BlueprintCallable)
    bool CheckJumpClearance(FVector Destination, FVector& ProjectedDestination, float Radius, float MinHeight, float MaxHeight, AActor* IgnoreActor, bool bDebug);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanUseCover() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanTether() const;
    
    UFUNCTION(BlueprintCallable)
    bool CanParkour();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanFireProjectileAtTarget(float SustainTime);
    
protected:
    UFUNCTION(BlueprintCallable)
    void BodyPartStateChanged(UHealthComponent* Health, FCauseDamageInfo CDI, bool bHealthy, bool bFromRestore);
    
    UFUNCTION(BlueprintCallable)
    void BodyPartHealthChanged(UHealthComponent* Health, FGameplayTag BodyPart, float OldHealthNormalized, float NewHealthNormalized);
    
public:
    UFUNCTION(BlueprintCallable)
    void AwakenFromDormantUnaware();
    
    UFUNCTION(BlueprintCallable)
    void AwakenFromDormantAndAttackPlayer();
    
    UFUNCTION(BlueprintCallable)
    void AwakenFromDormant(AActor* ActorToEngage);
    
    UFUNCTION(BlueprintCallable)
    void AssignStageMarkAfterTick(AStageMarkActor* StageMark, const UOEICineConversationInstance* Instance, const AStagePrefabActor* Stage, int32 AssignmentType);
    
    UFUNCTION(BlueprintCallable)
    void AIDebugPrintTime(const FText Text, int32 Level, float Time, bool bEvent);
    
    UFUNCTION(BlueprintCallable)
    void AIDebugPrintStringTime(const FString& Text, int32 Level, float Time, bool bEvent);
    
    UFUNCTION(BlueprintCallable)
    void AIDebugPrintString(const FString& Text, int32 Level);
    
    UFUNCTION(BlueprintCallable)
    void AIDebugPrint(const FText Text, int32 Level);
    
    UFUNCTION(BlueprintCallable)
    int32 AIDebugLevel();
    
    UFUNCTION(BlueprintCallable)
    void AddDamageMemory(FVector Center, float Damage);
    

    // Fix for true pure virtual functions not being implemented
};

