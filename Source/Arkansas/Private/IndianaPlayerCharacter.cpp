#include "IndianaPlayerCharacter.h"
#include "Components\CapsuleComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
#include "AimAssistComponent.h"
#include "CompanionManagerComponent.h"
#include "CompanionPositionComponent.h"
#include "FPVCameraComponent.h"
#include "GameInputComponent.h"
#include "HitEffectIndicatorComponent.h"
#include "IndianaInputComponent.h"
#include "IndianaPlayerAudioComponent.h"
#include "OwPlayerSpeakerInfoComponent.h"
#include "OwPostProcessComponent.h"
#include "PlayerChatterComponent.h"
#include "PlayerEnvironmentInteractionComponent.h"
#include "PlayerInfoComponent.h"
#include "PlayerInteractionComponent.h"
#include "PlayerInventoryComponent.h"
#include "PlayerMovementComponent.h"
#include "PlayerSneakAttackComponent.h"
#include "PlayerSpreadManagerComponent.h"
#include "PlayerStatTrackingComponent.h"
#include "PlayerTargetingComponent.h"
#include "RadioPlayerComponent.h"
#include "RecoilManagerComponent.h"
#include "ReviveComponent.h"
#include "StaminaComponent.h"
#include "StealthComponent.h"
#include "TPVCameraComponent.h"
#include "TPVCrouchTunnelComponent.h"
#include "TPVSpringArmComponent.h"
#include "TPVWhiskerComponent.h"
#include "TelemetryComponent.h"

AIndianaPlayerCharacter::AIndianaPlayerCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UPlayerMovementComponent>(TEXT("CharMoveComp")).SetDefaultSubobjectClass<UPlayerInventoryComponent>(TEXT("Inventory")).SetDefaultSubobjectClass<UPlayerEnvironmentInteractionComponent>(TEXT("EnvironmentComponent")).SetDefaultSubobjectClass<UPlayerInfoComponent>(TEXT("CharacterInfo")).SetDefaultSubobjectClass<UPlayerTargetingComponent>(TEXT("TargetingComponent")).SetDefaultSubobjectClass<UPlayerChatterComponent>(TEXT("ChatterComponent"))) {
    FProperty* p_CharacterMovement_Prior = GetClass()->FindPropertyByName("CharacterMovement");
    this->IndianaCharacterMovementComponent = (UIndianaCharMovementComponent*)*p_CharacterMovement_Prior->ContainerPtrToValuePtr<UPlayerMovementComponent*>(this);
    this->SpeakerInfoComponent = CreateDefaultSubobject<UOwPlayerSpeakerInfoComponent>(TEXT("PlayerSpeakerInfoComponent"));
    this->SpreadManagerComponent = CreateDefaultSubobject<UPlayerSpreadManagerComponent>(TEXT("SpreadManager"));
    this->AudioComponentClass = UIndianaPlayerAudioComponent::StaticClass();
    this->EyeSocketName = TEXT("CameraFocus");
    this->AimOffsetRotateInPlaceThreshold = 70.00f;
    this->AimInPlaceRotationAmount = 40.00f;
    this->AimInPlaceRotationInterpSpeed = 5.00f;
    this->FPVMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPVMesh"));
    this->FPVCamera = CreateDefaultSubobject<UFPVCameraComponent>(TEXT("FPVCamera"));
    this->TPVCamera = CreateDefaultSubobject<UTPVCameraComponent>(TEXT("TPVCamera"));
    this->TPVCameraBoom = CreateDefaultSubobject<UTPVSpringArmComponent>(TEXT("TPVCameraBoom"));
    this->TPVWhiskerComponent = CreateDefaultSubobject<UTPVWhiskerComponent>(TEXT("TPVWhiskerComponent"));
    this->TPVCrouchTunnelComponent = CreateDefaultSubobject<UTPVCrouchTunnelComponent>(TEXT("TPVCrouchTunnelComponent"));
    this->PlayerInfoComponent = (UPlayerInfoComponent*)CharacterInfoComponent;
    this->PlayerTargetingComponent = (UPlayerTargetingComponent*)BaseTargetingComponent;
    this->StaminaComponent = CreateDefaultSubobject<UStaminaComponent>(TEXT("Stamina"));
    this->RecoilManager = CreateDefaultSubobject<URecoilManagerComponent>(TEXT("RecoilManager"));
    this->AimAssistComponent = CreateDefaultSubobject<UAimAssistComponent>(TEXT("AimAssist"));
    this->StealthComponent = CreateDefaultSubobject<UStealthComponent>(TEXT("StealthComponent"));
    this->PlayerSneakAttackComponent = CreateDefaultSubobject<UPlayerSneakAttackComponent>(TEXT("PlayerSneakAttackComponent"));
    this->TelemetryComponent = CreateDefaultSubobject<UTelemetryComponent>(TEXT("TelemetryComponent"));
    this->FPVCameraSocket = TEXT("Camera_BoneSocket");
    this->ThrowableOriginSocket = TEXT("ThrowableOriginSocket");
    this->GameInputComponent = CreateDefaultSubobject<UGameInputComponent>(TEXT("GameInput"));
    this->PlayerAudioComponent = NULL;
    this->PlayerInventoryComponent = NULL;
    this->PlayerEquipmentComponent = NULL;
    this->PlayerHealthComponent = NULL;
    this->HeadsetSpeakerClass = NULL;
    this->HeadsetSpeaker = NULL;
    this->InteractionInputComponent = CreateDefaultSubobject<UIndianaInputComponent>(TEXT("InteractionInput"));
    this->HitEffectIndicatorComponent = CreateDefaultSubobject<UHitEffectIndicatorComponent>(TEXT("HitEffectIndicator"));
    //this->PostProcessEffectsComponent = CreateDefaultSubobject<UOwPostProcessComponent>(TEXT("PlayerPostProcessEffectsComponent"));
    this->PostProcessEffectsComponent = nullptr;
    this->InteractionComponent = CreateDefaultSubobject<UPlayerInteractionComponent>(TEXT("InteractionComponent"));
    this->PlayerEnvironmentComponent = (UPlayerEnvironmentInteractionComponent*)EnvironmentComponent;
    this->CompanionManagerComponent = CreateDefaultSubobject<UCompanionManagerComponent>(TEXT("CompanionManager"));
    this->CompanionPositionComponent = CreateDefaultSubobject<UCompanionPositionComponent>(TEXT("CompanionPositioning"));
    this->CompanionCommandComponent = NULL;
    this->PlayerInventory = NULL;
    this->TimeDilationComponent = NULL;
    this->TacticalTimeDilationComponent = NULL;
    this->MedKitComponent = NULL;
    this->PlayerSpeakerInfoComponent = (UOwPlayerSpeakerInfoComponent*)SpeakerInfoComponent;
    this->CollisionDamage = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionDamage"));
    this->HeadTarget = CreateDefaultSubobject<USceneComponent>(TEXT("HeadTarget_Standing"));
    this->ChestTarget = CreateDefaultSubobject<USceneComponent>(TEXT("ChestTarget_Standing"));
    this->TimeDilationClass = NULL;
    this->PerfectDodgeTime = 1.00f;
    this->MeleeHitStopDuration = 0.10f;
    this->HolsterTimeSinceInteract = 0.50f;
    this->PlayerStatTrackingComponent = CreateDefaultSubobject<UPlayerStatTrackingComponent>(TEXT("PlayerStatTrackingComponent"));
    this->CurrentShipLocation = NULL;
    this->PresetData = NULL;
    this->PickPocketStat = NULL;
    this->HackStat = NULL;
    this->HackStatusEffect = NULL;
    this->PowerShutdownStatusEffect = NULL;
    this->ScramblerCoilStatusEffect = NULL;
    this->ExplosivesStat = NULL;
    this->WaitCameraFadeDuration = 2.00f;
    this->WaitCameraBufferFadeDuration = 1.00f;
    this->MultiJumpSuccessForceFeedback = NULL;
    this->MultiJumpFailForceFeedback = NULL;
    this->SoftCoverEnterState = NULL;
    this->SoftCoverExitState = NULL;
    this->TimeBetweenGroinHits = 0.10f;
    this->RotateBodyToCameraInterpSpeed = 200.00f;
    this->DefaultFreeLookPitchMin = -90.00f;
    this->DefaultFreeLookPitchMax = 90.00f;
    this->DefaultFreeLookYawMin = -110.00f;
    this->DefaultFreeLookYawMax = 110.00f;
    this->ConversationFadeMaskedOpacityInner = 0.00f;
    this->ConversationFadeMaskedOpacityOuter = 0.00f;
    this->ReviveComponent = CreateDefaultSubobject<UReviveComponent>(TEXT("ReviveComponent"));
    this->RadioPlayerComponent = CreateDefaultSubobject<URadioPlayerComponent>(TEXT("RadioPlayerComponent"));
    this->BrakingDecelerationWalkingThirdPerson = 1024.00f;
    this->BrakingFrictionThirdPerson = 0.50f;
    this->BrakingDecelerationWalkingFirstPerson = 2048.00f;
    //this->ChestTarget->SetupAttachment(CollisionDamage);
    //this->CollisionDamage->SetupAttachment(GroundOffsetComponent);
    //this->FPVCamera->SetupAttachment(FPVMesh);
    //this->FPVMesh->SetupAttachment(GroundOffsetComponent);
    //this->HeadTarget->SetupAttachment(CollisionDamage);
    //this->PostProcessEffectsComponent->SetupAttachment(RootComponent);
    //this->TPVCamera->SetupAttachment(TPVCameraBoom);
    //this->TPVCameraBoom->SetupAttachment(GroundOffsetComponent);
    //this->TPVCrouchTunnelComponent->SetupAttachment(GroundOffsetComponent);
    //this->TPVWhiskerComponent->SetupAttachment(TPVCameraBoom);
}

void AIndianaPlayerCharacter::WeaponFOV(float FOV, bool bOffset) {
}

void AIndianaPlayerCharacter::VendorTriggerTrap() {
}

void AIndianaPlayerCharacter::VendorSetTrap(bool bTrapped) {
}

void AIndianaPlayerCharacter::UpdatePerspectiveMovementValues() {
}

void AIndianaPlayerCharacter::UnlockCameraPerspective_Interaction() {
}

void AIndianaPlayerCharacter::UnlockCameraPerspective_FirstPersonForced() {
}

void AIndianaPlayerCharacter::UnlockAbility(EUnlockAbility Ability) {
}

void AIndianaPlayerCharacter::TravelToDestination_BP(UPointOfInterestData* Destination, bool bTriggerAutosave) {
}

void AIndianaPlayerCharacter::ToggleUnlockTravelPoints() {
}

void AIndianaPlayerCharacter::ToggleShoulder() {
}

void AIndianaPlayerCharacter::TogglePlayerShadows() {
}

void AIndianaPlayerCharacter::TogglePerspective() {
}

void AIndianaPlayerCharacter::ToggleDisplayAimingRayMuzzle() {
}

void AIndianaPlayerCharacter::TinkerAdvanceWeapon(bool bIgnoreCost) {
}

void AIndianaPlayerCharacter::StopLockedLook() {
}

void AIndianaPlayerCharacter::StopFreeLook(bool bRotateBodyToCamera) {
}

void AIndianaPlayerCharacter::StartLockedLook(float ViewPitchMin, float ViewPitchMax, float ViewYawMin, float ViewYawMax) {
}

void AIndianaPlayerCharacter::StartFreeLookWithDefaultParams(bool bArmsFollowPitch) {
}

void AIndianaPlayerCharacter::StartFreeLookFrom(FRotator Rotation, bool bArmsFollowPitch, float ViewPitchMin, float ViewPitchMax, float ViewYawMin, float ViewYawMax) {
}

void AIndianaPlayerCharacter::StartFreeLook(bool bArmsFollowPitch, float ViewPitchMin, float ViewPitchMax, float ViewYawMin, float ViewYawMax) {
}

void AIndianaPlayerCharacter::SkipInteractionAnimProxy() {
}

void AIndianaPlayerCharacter::SetVisitedTravelDestination_BP(const UPointOfInterestData* TravelDest) {
}

void AIndianaPlayerCharacter::SetVisitedRegion_BP(const UTravelRegionData* Region) {
}

void AIndianaPlayerCharacter::SetUseAlternateShoulder(bool bEnable) {
}

void AIndianaPlayerCharacter::SetUnlockTravelPoints(int32 InIndex) {
}

void AIndianaPlayerCharacter::SetTutorialsEnabled(bool bEnabled) {
}

void AIndianaPlayerCharacter::SetTravelDestinationLocked_BP(const UPointOfInterestData* TravelDest, bool bLocked) {
}

void AIndianaPlayerCharacter::SetTravelDestinationHidden_BP(const UPointOfInterestData* TravelDest, bool bSetHidden) {
}

void AIndianaPlayerCharacter::SetShipLocation_BP(const UShipDestinationData* ShipDest) {
}

void AIndianaPlayerCharacter::SetInputPreferenceCrouch(int32 InputPreference) {
}

void AIndianaPlayerCharacter::SetEmergencyLoadingEnabled(bool bEnabled) {
}

void AIndianaPlayerCharacter::SetAwareOfTravelDestination_BP(const UPointOfInterestData* TravelDest) {
}

void AIndianaPlayerCharacter::SetAwareOfRegion_BP(const UTravelRegionData* Region) {
}

void AIndianaPlayerCharacter::SetAllLevels(int32 Level) {
}

void AIndianaPlayerCharacter::RequestScriptedWeaponFirstRaise(int32 EquipmentSlotIndex) {
}

void AIndianaPlayerCharacter::OnWeaponStopFineAim(UWeapon* Weapon) {
}

void AIndianaPlayerCharacter::OnWeaponStartUnequip(UWeapon* Weapon) {
}

void AIndianaPlayerCharacter::OnWeaponStartReload(UWeapon* Weapon) {
}

void AIndianaPlayerCharacter::OnWeaponStartFineAim(UWeapon* Weapon) {
}

void AIndianaPlayerCharacter::OnWeaponStartEquip(UWeapon* Weapon) {
}

void AIndianaPlayerCharacter::OnWeaponEndUnequip(UEquipmentComponent* Component, UWeapon* Weapon) {
}

void AIndianaPlayerCharacter::OnWeaponEndReload(UWeapon* Weapon) {
}

void AIndianaPlayerCharacter::OnWeaponEndEquip(UEquipmentComponent* Component, UWeapon* Weapon) {
}

void AIndianaPlayerCharacter::OnUndetected(AActor* Detectee) {
}

void AIndianaPlayerCharacter::OnThrowableUnequipped(UThrowable* Throwable) {
}

void AIndianaPlayerCharacter::OnThrowableEquipped(UThrowable* Throwable) {
}

void AIndianaPlayerCharacter::OnStopCrouch(UIndianaCharMovementComponent* InMovementComponent, bool bPlayerToggled) {
}


void AIndianaPlayerCharacter::OnStartThrowable(const UThrowable* Throwable) {
}

void AIndianaPlayerCharacter::OnSoftCoverExited() {
}

void AIndianaPlayerCharacter::OnSoftCoverEntered() {
}

void AIndianaPlayerCharacter::OnSneakAttackStart() {
}

void AIndianaPlayerCharacter::OnSneakAttackEnd() {
}





void AIndianaPlayerCharacter::OnPlayerInventoryItemAdded(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack) {
}

void AIndianaPlayerCharacter::OnPerspectiveSettingChanged(int32 NewPerspectiveSetting) {
}

void AIndianaPlayerCharacter::OnPauseStateChanged(bool bIsPaused) {
}

void AIndianaPlayerCharacter::OnPartyCombatDamageTaken(const FCauseDamageInfo& DamageInfo) {
}

void AIndianaPlayerCharacter::OnNRayAnimationStarted() {
}

void AIndianaPlayerCharacter::OnNRayAnimationEnded() {
}

void AIndianaPlayerCharacter::OnJumpLanded(UIndianaCharMovementComponent* InMovementComponent, float FallDistance) {
}

void AIndianaPlayerCharacter::OnHolsterToSimpleMotionWarpComplete(UWeapon* Weapon) {
}

void AIndianaPlayerCharacter::OnHolsterCompleteToAnimProxy(UWeapon* HolsteredWeapon) {
}

void AIndianaPlayerCharacter::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void AIndianaPlayerCharacter::OnGadgetDeactivate(FGameplayTag GadgetTag) {
}

void AIndianaPlayerCharacter::OnGadgetActivate(FGameplayTag GadgetTag) {
}

void AIndianaPlayerCharacter::OnEndThrowable(UThrowable* Throwable) {
}

void AIndianaPlayerCharacter::OnDodged(UIndianaCharMovementComponent* InMovementComponent, EDodgeDirection EDodgeDirection) {
}

void AIndianaPlayerCharacter::OnDetected(AActor* Detectee, AActor* Detector, float InvestigationTime) {
}

void AIndianaPlayerCharacter::OnCrouchComplete() {
}

void AIndianaPlayerCharacter::OnAllMontageInstancesEnded() {
}

void AIndianaPlayerCharacter::OffsetReticleChanged(bool bUseOffsetReticle) {
}

void AIndianaPlayerCharacter::MentionPointOfInterest(const UPointOfInterestData* POIData) {
}

void AIndianaPlayerCharacter::MakePointOfInterestDiscoverable(const UPointOfInterestData* POIData, bool bStillHidden) {
}

void AIndianaPlayerCharacter::LockCameraPerspective_Interaction() {
}

void AIndianaPlayerCharacter::LockCameraPerspective_FirstPersonForced() {
}

bool AIndianaPlayerCharacter::IsWeaponDown() const {
    return false;
}

bool AIndianaPlayerCharacter::IsTravelDestinationLocked_BP(const UPointOfInterestData* TravelDest, EBoolResult& OutResult) {
    return false;
}

bool AIndianaPlayerCharacter::IsTravelDestinationHidden_BP(const UPointOfInterestData* TravelDest, EBoolResult& OutResult) {
    return false;
}

bool AIndianaPlayerCharacter::IsShoulderSwapped() const {
    return false;
}

bool AIndianaPlayerCharacter::IsShipCurrentlyAt_BP(const UPointOfInterestData* ShipDest, EBoolResult& OutResult) {
    return false;
}

AHazard* AIndianaPlayerCharacter::IsPlayerInActiveHazard(EBoolResult& OutResult) {
    return NULL;
}

bool AIndianaPlayerCharacter::IsInThirdPersonPerspective() const {
    return false;
}

bool AIndianaPlayerCharacter::IsInRegion_BP(const UTravelRegionData* Region) {
    return false;
}

bool AIndianaPlayerCharacter::IsInFirstPersonPerspective() const {
    return false;
}

bool AIndianaPlayerCharacter::IsAwareOfTravelDestination_BP(const UPointOfInterestData* TravelDest, EBoolResult& OutResult) {
    return false;
}

bool AIndianaPlayerCharacter::IsAwareOfRegion_BP(const UTravelRegionData* Region, EBoolResult& OutResult) {
    return false;
}

bool AIndianaPlayerCharacter::IsAwareOfPointOfInterest(const UPointOfInterestData* POIData, EBoolResult& OutResult) {
    return false;
}

void AIndianaPlayerCharacter::InitiateTravelToShipLocation() {
}

void AIndianaPlayerCharacter::HideServicePointOfInterest(const AActor* ServicePOI) {
}

void AIndianaPlayerCharacter::HidePointOfInterest(const UPointOfInterestData* POIData) {
}

void AIndianaPlayerCharacter::HeadbobbingChanged(bool bHeadbobbing) {
}

bool AIndianaPlayerCharacter::HasVisitedTravelDestination_BP(const UPointOfInterestData* TravelDest, EBoolResult& OutResult) {
    return false;
}

bool AIndianaPlayerCharacter::HasVisitedRegion_BP(const UTravelRegionData* Region, EBoolResult& OutResult) {
    return false;
}

bool AIndianaPlayerCharacter::HasRequestedRevive() const {
    return false;
}

bool AIndianaPlayerCharacter::HasOnlyHeardAboutPointOfInterest(const UPointOfInterestData* POIData, EBoolResult& OutResult) {
    return false;
}

bool AIndianaPlayerCharacter::HasDiscoveredPointOfInterest(const UPointOfInterestData* POIData, EBoolResult& OutResult) {
    return false;
}

bool AIndianaPlayerCharacter::HasAbilityUnlocked(EUnlockAbility Ability) const {
    return false;
}

AIndianaPlayerCharacter* AIndianaPlayerCharacter::GetIndianaPC() {
    return NULL;
}

APlayerHeadsetSpeaker* AIndianaPlayerCharacter::GetHeadsetSpeaker() const {
    return NULL;
}

TArray<AIndianaAiCharacter*> AIndianaPlayerCharacter::GetCurrentEnemiesInCombat() const {
    return TArray<AIndianaAiCharacter*>();
}

ECameraPerspective AIndianaPlayerCharacter::GetCameraPerspective() const {
    return ECameraPerspective::FirstPerson;
}

void AIndianaPlayerCharacter::ForceOCLOpen() {
}

void AIndianaPlayerCharacter::ForceFirstPersonPerspective(EForcedFirstPersonFlag ForceType, bool bFPVForced) {
}

void AIndianaPlayerCharacter::EquippedWeaponChanged(UWeapon* NewlyEquippedWeapon) {
}

void AIndianaPlayerCharacter::DiscoverPointOfInterest(const UPointOfInterestData* POIData, bool bCanAwardXP, ESkillDifficultyTier SkillDifficultyTier, bool bForceProvideXP) {
}

void AIndianaPlayerCharacter::DebugTravel_TravelToDestination(const FName& TravelDestination) {
}

void AIndianaPlayerCharacter::DebugTravel_SetVisitedRegion(const FName& Region, bool bNewVisited) {
}

void AIndianaPlayerCharacter::DebugTravel_SetVisitedDestination(const FName& TravelDestination, bool bNewVisited) {
}

void AIndianaPlayerCharacter::DebugTravel_SetShipLocation(const FName& ShipLocation) {
}

void AIndianaPlayerCharacter::DebugTravel_SetDestinationLocked(const FName& TravelDestination, bool bNewLocked) {
}

void AIndianaPlayerCharacter::DebugTravel_SetDestinationHidden(const FName& TravelDestination, bool bNewHidden) {
}

void AIndianaPlayerCharacter::DebugTravel_SetAwareRegion(const FName& Region, bool bNewAware) {
}

void AIndianaPlayerCharacter::DebugTravel_SetAwareDestination(const FName& TravelDestination, bool bNewAware) {
}

void AIndianaPlayerCharacter::DebugSoftCoverExited() {
}

void AIndianaPlayerCharacter::DebugSoftCoverEntered() {
}

void AIndianaPlayerCharacter::DebugQueueFirstRaise() {
}

AActor* AIndianaPlayerCharacter::DebugGetTarget() const {
    return NULL;
}

bool AIndianaPlayerCharacter::CanHover() {
    return false;
}

bool AIndianaPlayerCharacter::CanDiscoverPointOfInterest(const UPointOfInterestData* POIData, EBoolResult& OutResult) {
    return false;
}

bool AIndianaPlayerCharacter::CanAccessTravelDestination_BP(const UPointOfInterestData* TravelDest, EBoolResult& OutResult) {
    return false;
}

void AIndianaPlayerCharacter::AdjustWeaponHealth(float Amount) {
}


