#pragma once
#include "CoreMinimal.h"
#include "Perception\AISightTargetInterface.h"



//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include <GameplayTagContainer.h>
#include <MovieSceneObjectBindingID.h>
#include "AimAdhesionInterface.h"
#include "AnimationProxyOwnerInterface.h"
#include <AnimationProxyTask.h>



//CROSS-MODULE INCLUDE V2: -ModuleName=OEIAnimProxyRuntime -ObjectName=EProxyTaskInterruptType -FallbackName=EProxyTaskInterruptType
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIAnimProxyRuntime -ObjectName=EProxyTaskState -FallbackName=EProxyTaskState
#include "OEICinematicsActor.h"


#include "StageMarkUser.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICommon -ObjectName=EBoolResult -FallbackName=EBoolResult
#include <SpeakerReference.h>
#include <GlobalVariableReference.h>
#include <LocString.h>
#include "AimTargets.h"
#include "CauseDamageInfo.h"
#include "CharacterDeathDelegate.h"
#include "CharacterResurrectedDelegate.h"
#include "DisplayInterface.h"
#include "ECreatureXPType.h"
#include "EEmotion.h"
#include "EGameDifficulty.h"
#include "EInteractionType.h"
#include "ESpellCastResult.h"
#include "EStageMarkAssignmentType.h"
#include "ETogglableAction.h"
#include "EventFirer.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "InteractorInterface.h"
#include "ItemStack.h"
#include "ItemStackDelegateDelegate.h"
#include "LogicalGroupedExpression.h"
#include "MapFloorTrackedActor.h"
#include "OnAnimProxyUseEndDelegate.h"
#include "OnAnimProxyUseStartDelegate.h"
#include "OnCharacterForcedDeathExecutedDelegate.h"
#include "OnCombatStateChangeDelegateDelegate.h"
#include "OnCompanionOutlineDelegate.h"
#include "OnDamageEventDelegate.h"
#include "OnHazardOccupancyChangeDelegate.h"
#include "OnKillBPDelegate.h"
#include "OnPlayerConversationChangeDelegateDelegate.h"
#include "OnProjectileDirectHitDelegate.h"
#include "OwActorPoolInterface.h"
#include "OwSimpleCharacter.h"
#include "ParkourMove.h"
#include "StatusEffectTarget.h"
#include "Templates/SubclassOf.h"
#include "TrackedSpawn.h"

#include "IndianaCharacter.generated.h"

class AActor;
class AIndianaCharacter;
class AIndianaCharacterDummy;
class AOwStageMarkActor;
class UActorComponent;
class UAnimationProxyComponent;
class UAnimationProxyData;
class UAppearanceComponent;
class UArmorComponent;
class UArmorItem;
class UBlockComponent;
class UCharacterInfoComponent;
class UCharacterInventoryComponent;
class UChatterComponent;
class UDamageableComponent;
class UDeathComponent;
class UDifficultyRpgStatModifiers;
class UEnvironmentInteractionComponent;
class UEquipmentComponent;
class UHealthComponent;
class UIndianaAudioComponent;
class UInteractableComponent;
class UInventoryComponent;
class UItem;
class ULightingRigComponent;
class UMeleeSlotManagerComponent;
class UMeshComponent;
class UOwActorPool;
class UOwConversationInstance;
class UPrimitiveComponent;
class UReactionComponent;
class URpgStatComponent;
class USpecialIDComponent;
class USpell;
class USpellManagerComponent;
class USpreadManagerComponent;
class UStatusEffectManagerComponent;
class UTPVAnimInstance;
class UTargetableComponent;
class UTargetingComponent;
class UTeamComponent;
class UWeapon;

UCLASS(Blueprintable)
class ARKANSAS_API AIndianaCharacter : public AOwSimpleCharacter, public IStatusEffectTarget, public IAISightTargetInterface, public IInteractorInterface, public IDisplayInterface, public IMapFloorTrackedActor, public ITrackedSpawn, public IEventFirer, public IAimAdhesionInterface, public IAnimationProxyOwnerInterface, public IOEICinematicsActor, public IStageMarkUser, public IOwActorPoolInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDamageEvent OnCauseDamage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnProjectileDirectHit OnProjectileDirectHit;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCharacterForcedDeathExecuted OnCharacterForcedDeathExecuted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnKillBP OnKillBPDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCombatStateChangeDelegate OnCombatStateChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterDeath OnCharacterDowned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterDeath OnCharacterDeath;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterResurrected OnCharacterResurrected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStackDelegate OnItemAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStackDelegate OnItemRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerConversationChangeDelegate OnPlayerConversationChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAnimProxyUseStart OnAnimProxyUseStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAnimProxyUseEnd OnAnimProxyUseEnd;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AIndianaCharacterDummy> OverrideDummyClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UActorComponent>> ImmutableBlueprintComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatEffectApplyMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicalGroupedExpression AutoStasisConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpreadManagerComponent* SpreadManagerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageableComponent* DamageableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArmorComponent* ArmorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatusEffectManagerComponent* StatusEffectManagerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTeamComponent* TeamComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCharacterInventoryComponent* InventoryComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBlockComponent* BlockComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReactionComponent* ReactionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpecialIDComponent* SpecialIDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnvironmentInteractionComponent* EnvironmentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UIndianaAudioComponent> AudioComponentClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpellManagerComponent* SpellManagerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAimTargets> AimTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FGameplayTag> ComponentNameToBodyPartTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHealthComponent* HealthComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDeathComponent* DeathComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEquipmentComponent* EquipmentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URpgStatComponent* RpgStatComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCharacterInfoComponent* CharacterInfoComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeleeSlotManagerComponent* SlotManagerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTargetableComponent* TargetableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAppearanceComponent* AppearanceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIndianaAudioComponent* IndianaAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULightingRigComponent* ConversationLightingRigComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTargetingComponent* BaseTargetingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBeInvestigated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreForProtestKill;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDifficultyRpgStatModifiers* DifficultyRpgStatModifiers;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OutOfCombatCylinderRadiusScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConversationCylinderRadiusScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInterruptAnimationProxyOnMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimationProxyTask AnimationProxyTask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CharacterScaleModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForceMinLODThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OnScaleForceMinLOD;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCompanionOutline OnCompanionOutline;
    
protected:
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CreatureType;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CreatureRole;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UChatterComponent* ChatterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EyeSocketName;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsMeleeAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MeleeAttackCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreservationTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AOwStageMarkActor* ConversationStageMark;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnHazardOccupancyChange OnHazardOccupancyChange;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Lifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReaquiredFromPoolHideTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldInstantGetupFromPool;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOwActorPool* OwningPool;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TrackedSocketOnRagdoll;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CharacterTeleportDistanceThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RagdollSettleTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RagdollTurnOffMotorsTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RagdollFreezeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RagdollMaxZSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverrideLinearDampingIfExceedsMaxSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference OnPetGlobalVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OnPetGlobalVariableValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CameraFocusSocket;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMeshComponent*> CachedAppearanceMeshes;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRiftedCharacter;
    
public:
    AIndianaCharacter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UseAnimProxyDuringSequenceWithKey(FMovieSceneObjectBindingID ActorUsingAnimProxyBinding, FMovieSceneObjectBindingID AnimProxyInteractableBinding, FGameplayTag AnimProxyKey);
    
    UFUNCTION(BlueprintCallable)
    void UseAnimationProxyAtPoint(FGameplayTag Key, FTransform FinalTransform, UAnimationProxyData* Data);
    
    UFUNCTION(BlueprintCallable)
    void UseAnimationProxy(UAnimationProxyComponent* AnimationProxy, bool bIsInfiniteTime);
    
    UFUNCTION(BlueprintCallable)
    void UpdateOutlines();
    
    UFUNCTION(BlueprintCallable)
    UOwConversationInstance* StartInterrogationConversation();
    
    UFUNCTION(BlueprintCallable)
    void SetRagdoll(bool bInIsRagdoll, bool bInstantFreeze, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void SetInteractTarget(bool bIsTarget, UInteractableComponent* Interactable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetEmotion(EEmotion NewEmotion);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetConversationLighting(bool bTurnOn);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCanPlayLocomotionStops(bool bCanPlay);
    
    UFUNCTION(BlueprintCallable)
    void SetCanPlayLocomotionOneShots(bool bCanPlay);
    
    UFUNCTION(BlueprintCallable)
    void SetCanBeInvestigated(bool bInCanBeInvestigated);
    
    UFUNCTION(BlueprintCallable)
    void ResetPreservationTimer();
    
    UFUNCTION(BlueprintCallable)
    void RemoveSpell(TSubclassOf<USpell> SpellType);
    
    UFUNCTION(BlueprintCallable)
    void RemoveCurrentStageMarkLock();
    
    UFUNCTION(BlueprintCallable, Exec)
    void PlayWeaponEvent(const FString& WeaponEvent);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTeleportedToStageMark(bool bTeleported);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpawnedFromPoolBP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReaquiredFromPoolBP();
    
    UFUNCTION(BlueprintCallable)
    void OnRagdollImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnParkourCompleted(const FParkourMove& ParkourMove);
    
    UFUNCTION(BlueprintCallable)
    void OnParkourBegin(const FParkourMove& ParkourMove);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnLevelChanged(UCharacterInfoComponent* InCharacterInfoComponent, int32 Level);
    
    UFUNCTION(BlueprintCallable)
    void OnGetupDelegate(UTPVAnimInstance* InAnimInstance, bool bInStarted);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFreedToPoolBP();
    
    UFUNCTION(BlueprintCallable)
    void OnDifficultyChanged(EGameDifficulty NewDifficulty);
    
    UFUNCTION(BlueprintCallable)
    void OnAppearanceApplied();
    
public:
    UFUNCTION(BlueprintCallable)
    void ManuallyAssignCharacterToStageMark(FSpeakerReference SpeakerReference, AOwStageMarkActor* StageMarkActor, EStageMarkAssignmentType StageMarkAssignmentType, bool bApplyStageMarkLock, bool bTeleportOnNodeSkipped);
    
protected:
    UFUNCTION(BlueprintCallable)
    void K2_ToggleAction(ETogglableAction Action, bool bToggleOn);
    
    UFUNCTION(BlueprintCallable)
    void K2_LockAnimationProxyTaskWaitState(bool Block, FName LockedWaitStateSource);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_IsUsingAnimationProxy() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetTimeSinceCombat() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float K2_GetTimeInCombat() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    ESpellCastResult K2_CastSpellOnTargets(TSubclassOf<USpell> SpellType, const TArray<AActor*>& Targets);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool K2_CanCastSpell(TSubclassOf<USpell> SpellType) const;
    
    UFUNCTION(BlueprintCallable)
    void ItemRemoved(UInventoryComponent* InInventoryComponent, const FItemStack& Item);
    
    UFUNCTION(BlueprintCallable)
    void ItemAdded(UInventoryComponent* InInventoryComponent, const FItemStack& Item);
    
    UFUNCTION(BlueprintCallable)
    bool IsWeaponEquippedBranching(TSubclassOf<UWeapon> WeaponClass, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWeaponEquipped(TSubclassOf<UWeapon> WeaponClass) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWeakCreatureType(ECreatureXPType CreatureXPType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWeak() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPet() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInCombatWithPlayer(bool bIncludeCompanions) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsInCombatBranching(EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHigherTierThanPlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDoingParkourVault() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDoingParkourMantle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDoingParkour() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsArmorEquippedBranching(TSubclassOf<UArmorItem> ArmorClass, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsArmorEquipped(TSubclassOf<UArmorItem> ArmorClass) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnyWeaponEquipped() const;
    
    UFUNCTION(BlueprintCallable)
    void InterruptAnimationProxyTask(EProxyTaskInterruptType InterruptReason);
    
    UFUNCTION(BlueprintCallable)
    bool HasItemBranching(TSubclassOf<UItem> Item, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasItem(TSubclassOf<UItem> Item) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasInterrogationConversation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasActiveMotionWarpRootMotionSource() const;
    
    UFUNCTION(BlueprintCallable)
    void HandleLanded(float FallDistance, const FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    void GrippingIKClearTargets();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeSinceLastAttackedByPlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStatusEffectManagerComponent* GetStatusEffectManager() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetPassesConditionals(EInteractionType InteractionType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetItemQuantity(TSubclassOf<UItem> Item) const;
    
    UFUNCTION(BlueprintCallable)
    FLocString GetInteractName() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<EInteractionType> GetInteractions(const FInteractionDescription& Description) const;
    
    UFUNCTION(BlueprintCallable)
    float GetInteractHoldTime(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetInActorPool();
    
    UFUNCTION(BlueprintCallable)
    FGameplayTag GetGameplayTag() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetCachedCollisionCylinder(float& OutCollisionRadius, float& OutCollisionHalfHeight) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UMeshComponent*> GetCachedAppearanceMeshes() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EProxyTaskState GetAnimationProxyState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetActorFeetLocation() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void FreeToPoolBP();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExecuteDowned(bool bFromReload);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExecuteDeath(bool bFromReload);
    
protected:
    UFUNCTION(BlueprintCallable)
    void DamageCaused(const FCauseDamageInfo& CauseDamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void ConversationRefreshFPVFramingTargets(AActor* LookTargetOverride);
    
    UFUNCTION(BlueprintCallable)
    void ConversationLookAtTarget(FVector TargetLocation, bool TurnBody, bool MaintainBetweenNodes);
    
    UFUNCTION(BlueprintCallable)
    void ConversationLookAtSpeaker(FSpeakerReference TargetSpeaker, bool TurnBody, bool MaintainBetweenNodes);
    
    UFUNCTION(BlueprintCallable)
    void ConversationLookAtActor(AActor* TargetActor, bool TurnBody, bool MaintainBetweenNodes);
    
public:
    UFUNCTION(BlueprintCallable)
    void CompleteInteract(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CastSpellDebugTargetFromSelf(const FString& SpellName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CastSpellDebugTarget(const FString& SpellName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CastSpellDebug(const FString& SpellName);
    
protected:
    UFUNCTION(BlueprintCallable)
    ESpellCastResult CastSpell(TSubclassOf<USpell> SpellType);
    
public:
    UFUNCTION(BlueprintCallable)
    bool CanPlayLocomotionStops();
    
    UFUNCTION(BlueprintCallable)
    bool CanPlayLocomotionOneShots();
    
    UFUNCTION(BlueprintCallable)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBeSeenBy(AIndianaCharacter* Observer, FVector& OutSeenLocation, bool bDebug) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnAppearanceApplied();
    

    // Fix for true pure virtual functions not being implemented
};

