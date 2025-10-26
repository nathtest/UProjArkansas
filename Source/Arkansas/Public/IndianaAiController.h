#pragma once
#include "CoreMinimal.h"
#include "AIController.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=EEnvQueryRunMode -FallbackName=EEnvQueryRunMode
#include "GenericTeamAgentInterface.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "StageMarkUser.h"

#include "AIBehaviorClassUserInterface.h"
#include "AIMeleeActionSettings.h"
#include "AIMovementExtensionFlagsModifier.h"
#include "AIOrientationControl.h"
#include "AIThrowableSettings.h"
#include "CauseDamageInfo.h"
#include "CompareDetectedTargetsDelegateDelegate.h"
#include "DetectedTargetInfoReference.h"
#include "EAIMovementState.h"
#include "EAlertState.h"
#include "ECheckLineOfSightResult.h"
#include "ECoverActions.h"
#include "ECoverSide.h"
#include "ECoverTypes.h"
#include "ELocationType.h"
#include "EMeleeAction.h"
#include "EQSSelector.h"
#include "ESearchInterruptedResponse.h"
#include "ESearchRequestProcessedResponse.h"
#include "EStateOfBeing.h"
#include "EStimulusType.h"
#include "ETargetInfoRelativeLocation.h"
#include "ETargetRequestType.h"
#include "OnAsyncEQSActorResultDelegate.h"
#include "OnAsyncEQSResultDelegate.h"
#include "OnAsyncEQSVectorResultDelegate.h"
#include "OnGroupBehaviorStatusChangedDelegate.h"
#include "OnWeaponOutCombatEndTransitionFinishedDelegate.h"
#include "StimulusReference.h"
#include "Templates/SubclassOf.h"
#include "IndianaAiController.generated.h"

class AActor;
class ACoverNode;
class AEncounter;
class AHardPoint;
class AIndianaAiCharacter;
class AIndianaCharacter;
class APatrolNode;
class UAIAnimProxySupportComponent;
class UAIBehaviorClass;
class UAIDetectionComponent;
class UAIHazardAvoidanceComponent;
class UAIInterruptsManagerComponent;
class UAIOrientationComponent;
class UAIOutOfCombatLogicComponent;
class UAIPatrolSupportComponent;
class UAIPlayConversationComponent;
class UAIWeaponFiringComponent;
class UAnimMontage;
class UCurveFloat;
class UEnvQueryInstanceBlueprintWrapper;
class UEquipmentComponent;
class UFactionData;
class UIndianaAIPerceptionComponent;
class UIndianaPathFollowingComponent;
class UNavigationQueryFilter;
class UObject;
class UOwBehaviorTreeComponent;
class UOwBlackboardComponent;
class UPerk;
class UTargetInfoComponent;
class UWeapon;

UCLASS(Blueprintable, MinimalAPI)
class AIndianaAiController : public AAIController, public IAIBehaviorClassUserInterface, public IStageMarkUser {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwBehaviorTreeComponent* OwBehaviorTreeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwBlackboardComponent* OwBlackboardComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTargetInfoComponent* TargetInfoComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIDetectionComponent* AIDetectionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIndianaAIPerceptionComponent* IndianaPerceptionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIndianaPathFollowingComponent* IndianaPathFollowingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIInterruptsManagerComponent* AIInterruptsManagerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIWeaponFiringComponent* WeaponFiringComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIOrientationComponent* OrientationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIOutOfCombatLogicComponent* OutOfCombatLogicComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIAnimProxySupportComponent* AnimProxySupportComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIHazardAvoidanceComponent* HazardAvoidanceComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIPatrolSupportComponent* PatrolSupportComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIPlayConversationComponent* PlayConversationComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoverNodeSearchCooldown;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGroupBehaviorStatusChanged OnCharacterStartedGroupBehavior;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGroupBehaviorStatusChanged OnCharacterStoppedGroupBehavior;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInCover;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBehaviorEnableCrouch;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UNavigationQueryFilter> DefaultNavigationBehaviorFilterClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UNavigationQueryFilter> DefaultNavigationEQSFilterClass;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float SightAwarenessDecreaseRates[6];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* SneakAwarenessCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UPerk> NilesSpotterPerk;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AIDebugLevelOverride;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnWeaponOutCombatEndTransitionFinished OnWeaponOutCombatEndTransitionFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseSAIR;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UnawarePeripheralSAIR;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UnawareNonPeripheralSAIR;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CautiousSAIR;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlertedPeripheralSAIR;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlertedNonPeripheralSAIR;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StealthSAIR;
    
public:
    AIndianaAiController(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UnlockTargeting();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldFindDynamicCover();
    
    UFUNCTION(BlueprintCallable)
    void SetHardPoint(AHardPoint* InHardPoint);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowDisableStatusEffectInterrupt(bool bInAllow);
    
protected:
    UFUNCTION(BlueprintCallable)
    static FAIMovementExtensionFlagsModifier RemoveNavigationFlag(const FAIMovementExtensionFlagsModifier& NavigationFlagModifier, int32 NavigationFlags);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponEndEquip(UEquipmentComponent* InEquipmentComponent, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnTakeDamage(const FCauseDamageInfo& CauseDamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void OnSwitchedTarget(AActor* OldTarget, AActor* NewTarget, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void OnMeleeActionEnd(AActor* Attacker, EMeleeAction ActionEnded);
    
    UFUNCTION(BlueprintCallable)
    void OnCombatStateChange(AIndianaCharacter* InCharacter, bool bInCombat, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void OnAlertStateChange(AActor* TargetActor, EAlertState PreviousAlertState, EAlertState TargetAlertState, bool bRestoring);
    
public:
    UFUNCTION(BlueprintCallable)
    void LockTargeting();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool LineOfSightToTargetPoint(const AActor* Other, FVector ViewPoint, FVector TargetLocation) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_WantsAvoidHazards() const;
    
    UFUNCTION(BlueprintCallable)
    void K2_TurretReloadWeapon();
    
    UFUNCTION(BlueprintCallable)
    bool K2_TriggerThrowable(const FAIThrowableSettings& AIThrowableSettings);
    
    UFUNCTION(BlueprintCallable)
    bool K2_TriggerMeleeAction(const FAIMeleeActionSettings AIMeleeActionSettings);
    
    UFUNCTION(BlueprintCallable)
    void K2_SuspendWeaponAutoReload(const bool bSuspend);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetWantCrouch(const bool bCrouch);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetWaitingForCrimeResponseGroupBehavior(bool bWaiting);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetTargetIsLost();
    
    UFUNCTION(BlueprintCallable)
    void K2_SetTargetAllowDecrementAlertState(AActor* Target, bool bAllow);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetTargetAlertStateMinDuration(const float MinDuration);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetStartled(bool bInValue);
    
private:
    UFUNCTION(BlueprintCallable)
    void K2_SetSearchPointBehaviorWantsToExit(bool bWantsToExit);
    
protected:
    UFUNCTION(BlueprintCallable)
    void K2_SetPlayerTargetIsLost();
    
    UFUNCTION(BlueprintCallable)
    void K2_SetOccupyLocation(const FVector Location);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetMovementState(const EAIMovementState AIMovementState, const float DynamicSpeed);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetIsRespondingToCrime(const FGuid& CrimeID, bool bResponding);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetIsCrimeResponseGroupBehaviorParticipant(bool bParticipant);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetCoverTypeSide(const ECoverTypes CoverType, const ECoverSide CoverSide);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetCoverType(const ECoverTypes CoverType);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetCoverSide(const ECoverSide CoverSide);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetCoverNode(ACoverNode* CoverNode);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetCoverActionSide(const ECoverActions CoverAction, const ECoverSide CoverSide);
    
    UFUNCTION(BlueprintCallable)
    void K2_SetCoverAction(const ECoverActions CoverAction);
    
private:
    UFUNCTION(BlueprintCallable)
    void K2_SetCanExecuteSearchPointBehaviors(bool bValue);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool K2_RunAsyncEQSVectorQuery(const FEQSSelector EQSSelector, TEnumAsByte<EEnvQueryRunMode::Type> RunMode, const FOnAsyncEQSVectorResult& Delegate);
    
    UFUNCTION(BlueprintCallable)
    UEnvQueryInstanceBlueprintWrapper* K2_RunAsyncEQSQuery(const FEQSSelector EQSSelector, TEnumAsByte<EEnvQueryRunMode::Type> RunMode, const FOnAsyncEQSResult& Delegate);
    
    UFUNCTION(BlueprintCallable)
    bool K2_RunAsyncEQSActorQuery(const FEQSSelector EQSSelector, TEnumAsByte<EEnvQueryRunMode::Type> RunMode, const FOnAsyncEQSActorResult& Delegate);
    
    UFUNCTION(BlueprintCallable)
    void K2_ResumeCurrentMove();
    
    UFUNCTION(BlueprintCallable)
    void K2_ResolveCrime(const FGuid& CrimeID);
    
    UFUNCTION(BlueprintCallable)
    void K2_ResolveAllCrimesForFactionByID(const FGuid& CrimeID);
    
    UFUNCTION(BlueprintCallable)
    void K2_ResolveAllCrimesForFaction(TSubclassOf<UFactionData> Faction);
    
    UFUNCTION(BlueprintCallable)
    void K2_RequestNewTarget(const ETargetRequestType TargetRequestType);
    
    UFUNCTION(BlueprintCallable)
    void K2_RequestCrimeResponseIndividualBehavior(const FGuid& InCrimeID);
    
    UFUNCTION(BlueprintCallable)
    void K2_ReloadWeapon();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_ProjectPointToNavigation(const FVector& Point, FVector& ProjectedLocation, const FVector QueryExtent, bool bUseEQSNavigationFilter) const;
    
    UFUNCTION(BlueprintCallable)
    void K2_PauseCurrentMove();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void K2_OnCrimeWitnessed(const FGuid& CrimeID);
    
    UFUNCTION(BlueprintCallable)
    void K2_NotifyRagdoll(bool bStarted);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsWeaponReloading() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsWeaponOutOfAmmo() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsWeaponAutoReloadSuspended() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsWaitingForCrimeResponseGroupBehavior() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsThrowInProgress() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsTargetSeen(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsTargetEncroachingHardPoint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsTargetAimingPossibleDepthTime(bool& bValid, float MaxDepth, float MaxCloseTime, float MaxFarTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsTargetAimingPossible(bool& bValid) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool K2_IsStimulusSearchable(const FStimulusReference& StimulusReference, EAlertState PreviousAlertState, EAlertState CurrentAlertState, float PreviousAwareness, float CurrentAwareness);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsStartled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsRequestingCrimeResponseIndividualBehavior() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsOrientationControlActive();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsMoving() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsMeleeAttacking() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsMeleeActionRecovering() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsMeleeActionExecuting() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsLocationInCoverNodeFiringArc(FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsLocationEncroachingHardPoint(FVector Location) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsInsideHardPoint(const bool bCheckForTargetEncroachment) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsInInterrupt() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsInGroupBehavior() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsInCover() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsFiringWeapon();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsFireWeaponActive();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsCompanion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsActorSeen(bool& bValid, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsActorInCoverNodeFiringArc(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsActorAimingPossible(bool& bValid, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_HasQueuedCompanionTeleport() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_HasHardPoint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_HasCurrentTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetWeaponMaxPreferredRange(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 K2_GetWeaponFireShotCount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TEnumAsByte<ETeamAttitude::Type> K2_GetTeamAttitudeTowards(AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetTargetTimeSinceLastSeen(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetTargetTimeContinuousSeen(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector K2_GetTargetSubLocation(bool& bValid, const ETargetInfoRelativeLocation TargetLocation, const ELocationType SubLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EStimulusType K2_GetTargetStimulusType(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector K2_GetTargetStimulusLocation(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetTargetStimulusAge(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetTargetRecentDamage(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector K2_GetTargetLocation(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetTargetBlockingDepth(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetTargetAwarenessRemainingTime(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetTargetAwarenessMeter(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EStimulusType K2_GetTargetAlertStateChangeStimulusType(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAlertState K2_GetTargetAlertState(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EStateOfBeing K2_GetStateOfBeing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimMontage* K2_GetStartledAnimation() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    ESearchRequestProcessedResponse K2_GetSearchRequestProcessedResponse(const FStimulusReference& StimulusReference);
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_GetSearchPointBehaviorWantsToExit() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    ESearchInterruptedResponse K2_GetSearchInterruptedResponse(const FStimulusReference& StimulusReference);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetRunSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetRecentDamageFromTarget(bool& bValid) const;
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 K2_GetObjectSearchCount(UObject* Object) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAIMovementState K2_GetMovementState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 K2_GetMeleeActionIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGuid K2_GetLastWitnessedCrimeID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector K2_GetLastInvestigatedDeadBodyLocation(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_GetIsRespondingToCrime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_GetIsCrimeResponseGroupBehaviorParticipant() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_GetIsCrimeResolved(const FGuid& CrimeID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AHardPoint* K2_GetHardPoint() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEncounter* K2_GetEncounter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void K2_GetDownedState(bool& bOutIsActive, bool& bOutIsComplete) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void K2_GetDeathState(bool& bOutIsActive, bool& bOutIsComplete) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* K2_GetCurrentTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECoverTypes K2_GetCurrentCoverType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECoverSide K2_GetCurrentCoverSide() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECoverActions K2_GetCurrentCoverAction() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGuid K2_GetCrimeResponseIndividualBehaviorCrimeID() const;
    
    UFUNCTION(BlueprintCallable)
    void K2_GetCoverTypeSide(ECoverTypes& CoverType, ECoverSide& CoverSide);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACoverNode* K2_GetCoverNode();
    
    UFUNCTION(BlueprintCallable)
    void K2_GetCoverActionSide(ECoverActions& CoverAction, ECoverSide& CoverSide);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 K2_GetCompanionIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimMontage* K2_GetCautiousToUnawareAnimation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* K2_GetBestDetectedTarget(const FCompareDetectedTargetsDelegate& DetectedTargetComparisonFunction) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimMontage* K2_GetAlertedToCautiousAnimation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AIndianaAiCharacter* K2_GetAICharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 K2_GetActorTransitionToUnawareCount(bool& bValid, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetActorTimeSinceLastSeen(bool& bValid, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector K2_GetActorSubLocation(bool& bValid, AActor* Actor, const ETargetInfoRelativeLocation TargetLocation, const ELocationType SubLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetActorStimulusAge(bool& bValid, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector K2_GetActorLocationAtTargetLastSeen(bool& bValid) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetActorAwarenessMeter(bool& bValid, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAlertState K2_GetActorAlertState(bool& bValid, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAIBehaviorClass* K2_GetActiveBehaviorClassInstance(TSubclassOf<UAIBehaviorClass> OptionalClassFilter) const;
    
    UFUNCTION(BlueprintCallable)
    void K2_ForgetTarget(AActor* Target);
    
    UFUNCTION(BlueprintCallable)
    void K2_ForgetPlayerTarget();
    
    UFUNCTION(BlueprintCallable)
    bool K2_ForceExitActiveGroupBehavior();
    
    UFUNCTION(BlueprintCallable)
    void K2_ForceCrimeDetection(const FGuid& CrimeID);
    
    UFUNCTION(BlueprintCallable)
    void K2_ForceClearMeleeRecovery();
    
    UFUNCTION(BlueprintCallable)
    void K2_ExecuteCompanionTeleport(const bool bClearTargetDetection, const float ClearTargetRange);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool K2_CompareDetectedTargets(const FDetectedTargetInfoReference& TargetA, const FDetectedTargetInfoReference& TargetB);
    
    UFUNCTION(BlueprintCallable)
    void K2_ClearOccupyLocations();
    
    UFUNCTION(BlueprintCallable)
    void K2_ClearMovementState();
    
    UFUNCTION(BlueprintCallable)
    void K2_ClearCrimeResponseIndividualBehaviorRequest();
    
    UFUNCTION(BlueprintCallable)
    void K2_ClearCoverNode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECheckLineOfSightResult K2_CheckLineOfSightToTargetLocations(const ETargetInfoRelativeLocation TargetLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECheckLineOfSightResult K2_CheckLineOfSightToActorLocations(AActor* Actor, const ETargetInfoRelativeLocation TargetLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool K2_CanTrackTargetAtLocation(const FStimulusReference& Stimulus) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_CanTargetActor(bool& bValid, AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_CanEngageTarget(bool& bValid, float MaxRange) const;
    
    UFUNCTION(BlueprintCallable)
    void K2_CancelWeaponReload(bool bRefillAmmo);
    
    UFUNCTION(BlueprintCallable)
    void K2_CancelMeleeAction();
    
    UFUNCTION(BlueprintCallable)
    void K2_CancelAllMovement();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FAIMovementExtensionFlagsModifier K2_ApplyDefaultExtensionFlags(FAIMovementExtensionFlagsModifier NavigationFlagModifier);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetingLocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOnCrouchNav();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocationInsideHardPoint(FVector Location) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasClearPath(FVector Destination, bool bCheckNavigation, bool bCheckObjects) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasActiveFindPathAsyncQuery() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HACK_ShouldPreventInterrupts() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    float GetSightAwarenessIncreaseRate(bool bIsStealthed, int32 OwnerPerceptionSkill, int32 TargetSneakSkill, EAlertState InAlertState, float Distance, float NormalizedDistance, float FurthestDistanceAwarenessFillRateScalar, bool bInPeripheral, bool bTargetActivelyPerformingTakedown, bool bTargetRecentlyPerformedTakedown) const;
    
    UFUNCTION(BlueprintCallable)
    float GetSightAwarenessDecreaseRate(bool bIsStealthed, int32 OwnerPerceptionSkill, int32 TargetSneakSkill, EAlertState InAlertState, bool bLost, bool bDeadBodyKiller) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetFootstepAwarenessIncrease(bool bIsStealthed, int32 OwnerPerceptionSkill, int32 TargetSneakSkill, EAlertState InAlertState, float BaseFootstepAwareness, float Distance, float SoundRadius) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDamageByPlayer();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentTargetFacing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentTargetDistance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAIDebugLevel();
    
    UFUNCTION(BlueprintCallable)
    bool GenerateLocationInsideHardPoint(FVector& Location);
    
protected:
    UFUNCTION(BlueprintCallable)
    FAIOrientationControl CrimeTrackPlayerControlPoll();
    
public:
    UFUNCTION(BlueprintCallable)
    void ClearShouldFindDynamicCover();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanSeeActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanEnterCombat() const;
    
    UFUNCTION(BlueprintCallable)
    void CancelMoveCompletedCallback();
    
    UFUNCTION(BlueprintCallable)
    static void AIScriptWander(AIndianaAiCharacter* InCharacter);
    
    UFUNCTION(BlueprintCallable)
    static void AIScriptStopAttack(AIndianaAiCharacter* InCharacter);
    
    UFUNCTION(BlueprintCallable)
    static void AIScriptPatrolInterruptible(AIndianaAiCharacter* InCharacter, APatrolNode* InPatrolNode);
    
    UFUNCTION(BlueprintCallable)
    static void AIScriptPatrol(AIndianaAiCharacter* InCharacter, APatrolNode* InPatrolNode);
    
    UFUNCTION(BlueprintCallable)
    static void AIScriptIdle(AIndianaAiCharacter* InCharacter);
    
    UFUNCTION(BlueprintCallable)
    static void AIScriptEncounterAttackEncounter(AEncounter* InEncounter, AEncounter* InTargetEncounter);
    
    UFUNCTION(BlueprintCallable)
    static void AIScriptEncounterAttack(AIndianaAiCharacter* InCharacter, AEncounter* InTargetEncounter);
    
    UFUNCTION(BlueprintCallable)
    static void AIScriptCharactersAttackCharacters(TArray<AIndianaAiCharacter*> InCharacters, TArray<AIndianaAiCharacter*> InTargetCharacters);
    
    UFUNCTION(BlueprintCallable)
    static void AIScriptAttackEncounter(AEncounter* InEncounter, AIndianaCharacter* InTargetCharacter);
    
    UFUNCTION(BlueprintCallable)
    static void AIScriptAttack(AIndianaAiCharacter* InCharacter, AIndianaCharacter* InTargetCharacter);
    
    UFUNCTION(BlueprintCallable)
    void AIDebugPrintTime(const FText Text, int32 Level, float Time);
    
    UFUNCTION(BlueprintCallable)
    void AIDebugPrint(const FText Text, int32 Level);
    
protected:
    UFUNCTION(BlueprintCallable)
    static FAIMovementExtensionFlagsModifier AddNavigationFlag(const FAIMovementExtensionFlagsModifier& NavigationFlagModifier, int32 NavigationFlags);
    
public:
    UFUNCTION(BlueprintCallable)
    void AbortAndResetFindPathAsyncQuery();
    

    // Fix for true pure virtual functions not being implemented
};

