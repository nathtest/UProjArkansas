#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PostProcessSettings -FallbackName=PostProcessSettings
#include <GameplayTagContainer.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICommon -ObjectName=EBoolResult -FallbackName=EBoolResult
#include <LocString.h>
#include "ActorFogOfWarSettings.h"
#include "CauseDamageInfo.h"
#include "ECameraPerspective.h"
#include "EDodgeDirection.h"
#include "EForcedFirstPersonFlag.h"
#include "ESkillDifficultyTier.h"
#include "EStateOfBeing.h"
#include "EUnlockAbility.h"
#include "EndGameSessionDelegate.h"
#include "FineAimingEventDelegate.h"
#include "FreeLookState.h"
#include "IndianaCharacter.h"
#include "ItemStack.h"
#include "OnCameraPerspectiveDelegate.h"
#include "OnCinematicModeChangeDelegateDelegate.h"
#include "OnPOIStateChangedDelegate.h"
#include "OnPlayerPerspectiveChangedDelegate.h"
#include "OnShoulderSwapDelegate.h"
#include "OnVendorTransactionComplete_BlueprintDelegate.h"
#include "PlayerCharacterEventDelegate.h"
#include "PreLevelTransitionDelegate.h"
#include "ShipLocationChangedDelegate.h"
#include "StartGameSessionDelegate.h"
#include "Templates/SubclassOf.h"
#include "IndianaPlayerCharacter.generated.h"

class AActor;
class AAudioLogSpeaker;
class AHazard;
class AIndianaAiCharacter;
class AIndianaPlayerCharacter;
class APlayerHeadsetSpeaker;
class UActorComponent;
class UAimAssistComponent;
class UAkStateValue;
class UCapsuleComponent;
class UCompanionCommandComponent;
class UCompanionManagerComponent;
class UCompanionPositionComponent;
class UEquipmentComponent;
class UFPVCameraComponent;
class UForceFeedbackEffect;
class UGameInputComponent;
class UHitEffectIndicatorComponent;
class UIndianaCharMovementComponent;
class UIndianaInputComponent;
class UIndianaPlayerAudioComponent;
class UInventoryComponent;
class UItem;
class UMedKitComponent;
class UOEIWwiseEmitterComponent;
class UOwConversationInstance;
class UOwPlayerSpeakerInfoComponent;
class UPlayerEnvironmentInteractionComponent;
class UPlayerEquipmentComponent;
class UPlayerHealthComponent;
class UPlayerInfoComponent;
class UPlayerInteractionComponent;
class UPlayerInventoryComponent;
class UPlayerPresetData;
class UPlayerSneakAttackComponent;
class UPlayerStatTrackingComponent;
class UPlayerTargetingComponent;
class UPointOfInterestData;
class UPostProcessComponent;
class UPrimitiveComponent;
class URadioPlayerComponent;
class URadioStationDataAsset;
class URecoilManagerComponent;
class UReviveComponent;
class URpgStat;
class USceneComponent;
class UShipDestinationData;
class USkeletalMeshComponent;
class UStaminaComponent;
class UStatusEffect;
class UStealthComponent;
class UTPVCameraComponent;
class UTPVCrouchTunnelComponent;
class UTPVSpringArmComponent;
class UTPVWhiskerComponent;
class UTacticalTimeDilationComponent;
class UTelemetryComponent;
class UThrowable;
class UTimeDilationComponent;
class UTravelRegionData;
class UWeapon;

UCLASS(Blueprintable)
class ARKANSAS_API AIndianaPlayerCharacter : public AIndianaCharacter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimOffsetRotateInPlaceThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimInPlaceRotationAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimInPlaceRotationInterpSpeed;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FStartGameSession OnStartGameSession;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEndGameSession OnEndGameSession;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCinematicModeChangeDelegate OnCinematicModeChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnVendorTransactionComplete_Blueprint VendorTransactionComplete_Blueprint;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* FPVMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFPVCameraComponent* FPVCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTPVCameraComponent* TPVCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTPVSpringArmComponent* TPVCameraBoom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTPVWhiskerComponent* TPVWhiskerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTPVCrouchTunnelComponent* TPVCrouchTunnelComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerInfoComponent* PlayerInfoComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerTargetingComponent* PlayerTargetingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaminaComponent* StaminaComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URecoilManagerComponent* RecoilManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAimAssistComponent* AimAssistComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStealthComponent* StealthComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerSneakAttackComponent* PlayerSneakAttackComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTelemetryComponent* TelemetryComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FPVCameraSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ThrowableOriginSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameInputComponent* GameInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UIndianaPlayerAudioComponent* PlayerAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPlayerInventoryComponent* PlayerInventoryComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPlayerEquipmentComponent* PlayerEquipmentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPlayerHealthComponent* PlayerHealthComponent;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<AAudioLogSpeaker*, TWeakObjectPtr<UOwConversationInstance>> AudioLogSpeakers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<URadioStationDataAsset*, UOEIWwiseEmitterComponent*> RadioStationEmitters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APlayerHeadsetSpeaker> HeadsetSpeakerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HeadsetSpeakerAttachSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerHeadsetSpeaker* HeadsetSpeaker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UIndianaInputComponent* InteractionInputComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitEffectIndicatorComponent* HitEffectIndicatorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPostProcessComponent* PostProcessEffectsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessSettings Default_PP_Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerInteractionComponent* InteractionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerEnvironmentInteractionComponent* PlayerEnvironmentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCompanionManagerComponent* CompanionManagerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCompanionPositionComponent* CompanionPositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCompanionCommandComponent* CompanionCommandComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInventoryComponent* PlayerInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTimeDilationComponent* TimeDilationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTacticalTimeDilationComponent* TacticalTimeDilationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMedKitComponent* MedKitComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwPlayerSpeakerInfoComponent* PlayerSpeakerInfoComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CollisionDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* HeadTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* ChestTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTimeDilationComponent> TimeDilationClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerfectDodgeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeleeHitStopDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HolsterTimeSinceInteract;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorFogOfWarSettings PlayerFogOfWarRevealSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerStatTrackingComponent* PlayerStatTrackingComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UActorComponent> PlayerDebugComponentClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSoftClassPtr<UItem>> UniqueExaminablesLooted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FLocString> UniqueExaminablesNameLocStrings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FLocString> UniqueExaminablesDescriptionLocStrings;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPreLevelTransition PreLevelTransition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGuid> LoadingImagesSeen;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPOIStateChanged OnPOIStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FShipLocationChanged OnShipLocationChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UShipDestinationData* CurrentShipLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayerPresetData* PresetData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URpgStat* PickPocketStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URpgStat* HackStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> HackStatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> PowerShutdownStatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> ScramblerCoilStatusEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URpgStat* ExplosivesStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaitCameraFadeDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaitCameraBufferFadeDuration;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UForceFeedbackEffect* MultiJumpSuccessForceFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UForceFeedbackEffect* MultiJumpFailForceFeedback;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* SoftCoverEnterState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* SoftCoverExitState;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeBetweenGroinHits;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FFreeLookState FreeLookState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RotateBodyToCameraInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultFreeLookPitchMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultFreeLookPitchMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultFreeLookYawMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultFreeLookYawMax;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConversationFadeMaskedOpacityInner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConversationFadeMaskedOpacityOuter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReviveComponent* ReviveComponent;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFineAimingEvent FineAimStartedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFineAimingEvent FullyFineAimedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFineAimingEvent FineAimEndedDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URadioPlayerComponent* RadioPlayerComponent;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCameraPerspective OnCameraPerspectiveChangedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerPerspectiveChanged OnPlayerPerspectiveChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnShoulderSwap OnShoulderSwap;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BrakingDecelerationWalkingThirdPerson;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BrakingFrictionThirdPerson;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BrakingDecelerationWalkingFirstPerson;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerCharacterEvent OnP1PForcedStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerCharacterEvent OnP1PForcedEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerCharacterEvent OnInteractionStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerCharacterEvent OnInteractionEnd;
    
public:
    AIndianaPlayerCharacter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Exec)
    void WeaponFOV(float FOV, bool bOffset);
    
    UFUNCTION(BlueprintCallable, Exec)
    void VendorTriggerTrap();
    
    UFUNCTION(BlueprintCallable, Exec)
    void VendorSetTrap(bool bTrapped);
    
protected:
    UFUNCTION(BlueprintCallable)
    void UpdatePerspectiveMovementValues();
    
    UFUNCTION(BlueprintCallable)
    void UnlockCameraPerspective_Interaction();
    
    UFUNCTION(BlueprintCallable)
    void UnlockCameraPerspective_FirstPersonForced();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void UnlockAbility(EUnlockAbility Ability);
    
    UFUNCTION(BlueprintCallable)
    static void TravelToDestination_BP(UPointOfInterestData* Destination, bool bTriggerAutosave);
    
    UFUNCTION(BlueprintCallable, Exec)
    static void ToggleUnlockTravelPoints();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleShoulder();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TogglePlayerShadows();
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void TogglePerspective();
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleDisplayAimingRayMuzzle();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TinkerAdvanceWeapon(bool bIgnoreCost);
    
    UFUNCTION(BlueprintCallable)
    void StopLockedLook();
    
    UFUNCTION(BlueprintCallable)
    void StopFreeLook(bool bRotateBodyToCamera);
    
    UFUNCTION(BlueprintCallable)
    void StartLockedLook(float ViewPitchMin, float ViewPitchMax, float ViewYawMin, float ViewYawMax);
    
    UFUNCTION(BlueprintCallable)
    void StartFreeLookWithDefaultParams(bool bArmsFollowPitch);
    
    UFUNCTION(BlueprintCallable)
    void StartFreeLookFrom(FRotator Rotation, bool bArmsFollowPitch, float ViewPitchMin, float ViewPitchMax, float ViewYawMin, float ViewYawMax);
    
    UFUNCTION(BlueprintCallable)
    void StartFreeLook(bool bArmsFollowPitch, float ViewPitchMin, float ViewPitchMax, float ViewYawMin, float ViewYawMax);
    
    UFUNCTION(BlueprintCallable)
    void SkipInteractionAnimProxy();
    
    UFUNCTION(BlueprintCallable)
    static void SetVisitedTravelDestination_BP(const UPointOfInterestData* TravelDest);
    
    UFUNCTION(BlueprintCallable)
    static void SetVisitedRegion_BP(const UTravelRegionData* Region);
    
    UFUNCTION(BlueprintCallable)
    void SetUseAlternateShoulder(bool bEnable);
    
    UFUNCTION(BlueprintCallable, Exec)
    static void SetUnlockTravelPoints(int32 InIndex);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetTutorialsEnabled(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    static void SetTravelDestinationLocked_BP(const UPointOfInterestData* TravelDest, bool bLocked);
    
    UFUNCTION(BlueprintCallable)
    static void SetTravelDestinationHidden_BP(const UPointOfInterestData* TravelDest, bool bSetHidden);
    
    UFUNCTION(BlueprintCallable)
    static void SetShipLocation_BP(const UShipDestinationData* ShipDest);
    
    UFUNCTION(BlueprintCallable)
    void SetInputPreferenceCrouch(int32 InputPreference);
    
    UFUNCTION(BlueprintCallable)
    void SetEmergencyLoadingEnabled(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    static void SetAwareOfTravelDestination_BP(const UPointOfInterestData* TravelDest);
    
    UFUNCTION(BlueprintCallable)
    static void SetAwareOfRegion_BP(const UTravelRegionData* Region);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetAllLevels(int32 Level);
    
    UFUNCTION(BlueprintCallable)
    void RequestScriptedWeaponFirstRaise(int32 EquipmentSlotIndex);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnWeaponStopFineAim(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponStartUnequip(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponStartReload(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponStartFineAim(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponStartEquip(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponEndUnequip(UEquipmentComponent* Component, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponEndReload(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponEndEquip(UEquipmentComponent* Component, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnUndetected(AActor* Detectee);
    
    UFUNCTION(BlueprintCallable)
    void OnThrowableUnequipped(UThrowable* Throwable);
    
    UFUNCTION(BlueprintCallable)
    void OnThrowableEquipped(UThrowable* Throwable);
    
    UFUNCTION(BlueprintCallable)
    void OnStopCrouch(UIndianaCharMovementComponent* InMovementComponent, bool bPlayerToggled);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateOfBeingChanged(EStateOfBeing NewState, EStateOfBeing OldState);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnStartThrowable(const UThrowable* Throwable);
    
    UFUNCTION(BlueprintCallable)
    void OnSoftCoverExited();
    
    UFUNCTION(BlueprintCallable)
    void OnSoftCoverEntered();
    
    UFUNCTION(BlueprintCallable)
    void OnSneakAttackStart();
    
    UFUNCTION(BlueprintCallable)
    void OnSneakAttackEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerStealthExitedBP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerStealthEnteredBP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerSoftCoverExitedBP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerSoftCoverEnteredBP();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPlayerInventoryItemAdded(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnPerspectiveSettingChanged(int32 NewPerspectiveSetting);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPauseStateChanged(bool bIsPaused);
    
    UFUNCTION(BlueprintCallable)
    void OnPartyCombatDamageTaken(const FCauseDamageInfo& DamageInfo);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnNRayAnimationStarted();
    
    UFUNCTION(BlueprintCallable)
    void OnNRayAnimationEnded();
    
    UFUNCTION(BlueprintCallable)
    void OnJumpLanded(UIndianaCharMovementComponent* InMovementComponent, float FallDistance);
    
    UFUNCTION(BlueprintCallable)
    void OnHolsterToSimpleMotionWarpComplete(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnHolsterCompleteToAnimProxy(UWeapon* HolsteredWeapon);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnGadgetDeactivate(FGameplayTag GadgetTag);
    
    UFUNCTION(BlueprintCallable)
    void OnGadgetActivate(FGameplayTag GadgetTag);
    
    UFUNCTION(BlueprintCallable)
    void OnEndThrowable(UThrowable* Throwable);
    
    UFUNCTION(BlueprintCallable)
    void OnDodged(UIndianaCharMovementComponent* InMovementComponent, EDodgeDirection EDodgeDirection);
    
    UFUNCTION(BlueprintCallable)
    void OnDetected(AActor* Detectee, AActor* Detector, float InvestigationTime);
    
    UFUNCTION(BlueprintCallable)
    void OnCrouchComplete();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnAllMontageInstancesEnded();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OffsetReticleChanged(bool bUseOffsetReticle);
    
public:
    UFUNCTION(BlueprintCallable)
    void MentionPointOfInterest(const UPointOfInterestData* POIData);
    
    UFUNCTION(BlueprintCallable)
    void MakePointOfInterestDiscoverable(const UPointOfInterestData* POIData, bool bStillHidden);
    
protected:
    UFUNCTION(BlueprintCallable)
    void LockCameraPerspective_Interaction();
    
    UFUNCTION(BlueprintCallable)
    void LockCameraPerspective_FirstPersonForced();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWeaponDown() const;
    
    UFUNCTION(BlueprintCallable)
    static bool IsTravelDestinationLocked_BP(const UPointOfInterestData* TravelDest, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsTravelDestinationHidden_BP(const UPointOfInterestData* TravelDest, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsShoulderSwapped() const;
    
    UFUNCTION(BlueprintCallable)
    static bool IsShipCurrentlyAt_BP(const UPointOfInterestData* ShipDest, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static AHazard* IsPlayerInActiveHazard(EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInThirdPersonPerspective() const;
    
    UFUNCTION(BlueprintCallable)
    static bool IsInRegion_BP(const UTravelRegionData* Region);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInFirstPersonPerspective() const;
    
    UFUNCTION(BlueprintCallable)
    static bool IsAwareOfTravelDestination_BP(const UPointOfInterestData* TravelDest, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsAwareOfRegion_BP(const UTravelRegionData* Region, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    bool IsAwareOfPointOfInterest(const UPointOfInterestData* POIData, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    void InitiateTravelToShipLocation();
    
    UFUNCTION(BlueprintCallable)
    void HideServicePointOfInterest(const AActor* ServicePOI);
    
    UFUNCTION(BlueprintCallable)
    void HidePointOfInterest(const UPointOfInterestData* POIData);
    
protected:
    UFUNCTION(BlueprintCallable)
    void HeadbobbingChanged(bool bHeadbobbing);
    
public:
    UFUNCTION(BlueprintCallable)
    static bool HasVisitedTravelDestination_BP(const UPointOfInterestData* TravelDest, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool HasVisitedRegion_BP(const UTravelRegionData* Region, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasRequestedRevive() const;
    
    UFUNCTION(BlueprintCallable)
    bool HasOnlyHeardAboutPointOfInterest(const UPointOfInterestData* POIData, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    bool HasDiscoveredPointOfInterest(const UPointOfInterestData* POIData, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, Exec)
    bool HasAbilityUnlocked(EUnlockAbility Ability) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AIndianaPlayerCharacter* GetIndianaPC();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayerHeadsetSpeaker* GetHeadsetSpeaker() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AIndianaAiCharacter*> GetCurrentEnemiesInCombat() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECameraPerspective GetCameraPerspective() const;
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void ForceOCLOpen();
    
public:
    UFUNCTION(BlueprintCallable)
    void ForceFirstPersonPerspective(EForcedFirstPersonFlag ForceType, bool bFPVForced);
    
protected:
    UFUNCTION(BlueprintCallable)
    void EquippedWeaponChanged(UWeapon* NewlyEquippedWeapon);
    
public:
    UFUNCTION(BlueprintCallable)
    void DiscoverPointOfInterest(const UPointOfInterestData* POIData, bool bCanAwardXP, ESkillDifficultyTier SkillDifficultyTier, bool bForceProvideXP);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTravel_TravelToDestination(const FName& TravelDestination);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTravel_SetVisitedRegion(const FName& Region, bool bNewVisited);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTravel_SetVisitedDestination(const FName& TravelDestination, bool bNewVisited);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTravel_SetShipLocation(const FName& ShipLocation);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTravel_SetDestinationLocked(const FName& TravelDestination, bool bNewLocked);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTravel_SetDestinationHidden(const FName& TravelDestination, bool bNewHidden);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTravel_SetAwareRegion(const FName& Region, bool bNewAware);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTravel_SetAwareDestination(const FName& TravelDestination, bool bNewAware);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugSoftCoverExited();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugSoftCoverEntered();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugQueueFirstRaise();
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    AActor* DebugGetTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanHover();
    
public:
    UFUNCTION(BlueprintCallable)
    bool CanDiscoverPointOfInterest(const UPointOfInterestData* POIData, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool CanAccessTravelDestination_BP(const UPointOfInterestData* TravelDest, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AdjustWeaponHealth(float Amount);
    
};

