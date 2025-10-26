#include "IndianaAiCharacter.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=GameplayTasks -ObjectName=GameplayTasksComponent -FallbackName=GameplayTasksComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICharacterCustomization -ObjectName=OEICCSkeletalMeshComponent -FallbackName=OEICCSkeletalMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIWwise -ObjectName=OEIWwiseEmitterComponent -FallbackName=OEIWwiseEmitterComponent
#include "AIChatterComponent.h"
#include "AIDefensiveActionsComponent.h"
#include "AIInteractionComponent.h"
#include "AIMovementComponent.h"
#include "AIPatrolSupportComponent.h"
#include "AISettingsComponent.h"
#include "AiTargetingComponent.h"
#include "HeadAndBodyTrackingComponent.h"
#include "PersonalSpaceComponent.h"
#include "SpreadManagerComponent.h"
#include "StatusTagStaticMeshComponent.h"
#include <OEICCSkeletalMeshComponent.h>
#include "OEIWwiseEmitterComponent.h"
#include "GameplayTask.h"


AIndianaAiCharacter::AIndianaAiCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UAIMovementComponent>(TEXT("CharMoveComp")).SetDefaultSubobjectClass<UAiTargetingComponent>(TEXT("TargetingComponent")).SetDefaultSubobjectClass<UAIChatterComponent>(TEXT("ChatterComponent"))) {
    FProperty* p_CharacterMovement_Prior = GetClass()->FindPropertyByName("CharacterMovement");
    this->IndianaCharacterMovementComponent = (UIndianaCharMovementComponent*)*p_CharacterMovement_Prior->ContainerPtrToValuePtr<UAIMovementComponent*>(this);
    this->AIMovementComponent = (UAIMovementComponent*)*p_CharacterMovement_Prior->ContainerPtrToValuePtr<UAIMovementComponent*>(this);
    this->SpreadManagerComponent = CreateDefaultSubobject<USpreadManagerComponent>(TEXT("SpreadManager"));
    this->bInterruptAnimationProxyOnMove = true;
    this->EyeSocketName = TEXT("CameraFocus");
    this->bUsingCoverMontages = false;
    this->bUseCoverIdlesAndDisableLocomotion = false;
    this->AcceptableErrorAngleForCoverEntry = 30.00f;
    this->DisableParkourCount = 0;
    this->bStatusTagSuppressed = false;
    this->CompanionComponent = NULL;
    this->AISettingsComponent = CreateDefaultSubobject<UAISettingsComponent>(TEXT("AISettings"));
    this->InteractionComponent = CreateDefaultSubobject<UAIInteractionComponent>(TEXT("Interaction"));
    this->AiTargetingComponent = (UAiTargetingComponent*)BaseTargetingComponent;
    this->HeadAndBodyTrackingComponent = CreateDefaultSubobject<UHeadAndBodyTrackingComponent>(TEXT("HeadAndBodyTracking"));
    this->PatrolSupportComponent = CreateDefaultSubobject<UAIPatrolSupportComponent>(TEXT("AIPatrolSupportComponent"));
    this->PersonalSpaceComponent = CreateDefaultSubobject<UPersonalSpaceComponent>(TEXT("PersonalSpace"));
    this->DefensiveActionsComponent = CreateDefaultSubobject<UAIDefensiveActionsComponent>(TEXT("DefensiveActions"));
    //this->GameplayTasksComponent = CreateDefaultSubobject<UGameplayTasksComponent>(TEXT("GameplayTasks"));
    this->EmitterComponent = CreateDefaultSubobject<UOEIWwiseEmitterComponent>(TEXT("CharacterEmitterComponent"));
    const FProperty* p_Mesh_Parent = GetClass()->FindPropertyByName("Mesh");
    this->AnimInstance = NULL;
    this->Personality = NULL;
    this->bHasWeaponInNonCombat = false;
    this->AimOriginSocketName = TEXT("ChestAimOrigin");
    this->bAimOriginLowerToFeet = false;
    this->AimOriginVerticalOffset = 0.00f;
    this->AimOriginForwardOffset = 0.00f;
    this->CarryingCapacity = 10.00f;
    this->bIsolated = false;
    this->bShouldIgnorePlayerDamage = false;
    this->bIgnorePlayerPlacedTraps = false;
    this->WeaponHeldBeforeConversationStart = NULL;
    this->CustomBlackboardData = NULL;
    this->DistanceToAlwaysEvaluateAnimations = 1000.00f;
    this->StartCombatAnimationStateDelay = 0.25f;
    this->DefaultMaleEyePoseAsset = NULL;
    this->DefaultFemaleEyePoseAsset = NULL;
    this->EmotionData = NULL;
    this->bHasDefaultEmotion = false;
    this->DefaultEmotion = EEmotion::Neutral;
    this->bUseFactionReactionEmotions = true;
    this->GoodReaction = EEmotion::SlightlyHappy;
    this->NeutralReaction = EEmotion::Neutral;
    this->BadReaction = EEmotion::SlightlyAngry;
    this->AnimationProxyData = NULL;
    this->bIsDowned = false;
    this->AIProjectileLogic = NULL;
    this->ShroudDelayTime = 15.00f;
    this->BodyPartDespawnTime = 4.00f;
    this->bLeftCannisterIntact = true;
    this->bRightCannisterIntact = true;
    this->bLeftCannisterDestroyed = false;
    this->bRightCannisterDestroyed = false;
    this->HardPoint = NULL;
    this->bStayOnHardPoint = false;
    this->bEnableAutomaticHardPointAssignment = true;
    this->bCanJoinAnyHardPoint = false;
    this->StatusTagSMComponent = CreateDefaultSubobject<UStatusTagStaticMeshComponent>(TEXT("StatusTagStaticMesh"));
    this->JumpAnticTimer = 0.00f;
    this->bUseTightRadialDamageBounds = false;
    this->bMeleePositionEnable = false;
    this->bMeleePositionActive = false;
    this->MeleeCheckBodyOrientationForgivenessAngle = 3.00f;
    this->MeleeCheckCapsuleRadiusMultiplier = 1.00f;
    this->MinMeleeAttackCapsuleDistance = 15.00f;
    this->MinMeleeBurrowAttackCapsuleDistance = 15.00f;
    this->bIsCaged = false;
    this->BurrowTime = 1.50f;
    this->bWantsToBurrow = false;
    this->bAnimBurrowed = false;
    this->BurrowAlpha = 0.00f;
    this->bIsBurrowed = false;
    this->bIsBurrowingDownOrUp = false;
    this->bShouldOrientBeforeMoving = false;
    this->bAdditionalPersonalityOverridesWeapon = false;
    this->bDebugTrap = false;
    this->HazardToSpawnOnDeath = NULL;
    this->EmitterComponent->SetupAttachment(p_Mesh_Parent->ContainerPtrToValuePtr<UOEICCSkeletalMeshComponent>(this));
    this->StatusTagSMComponent->SetupAttachment(RootComponent);
}

bool AIndianaAiCharacter::ValidateProjectileFiringLocation(FVector Location, FVector Direction) {
    return false;
}

void AIndianaAiCharacter::TurretEngageActor(AActor* ActorToEngage) {
}

void AIndianaAiCharacter::SwitchPersonality(const FGameplayTag& PersonalityTag, bool bOverrideWeaponPersonality) {
}

bool AIndianaAiCharacter::ShouldOrientBeforeMoving() {
    return false;
}

bool AIndianaAiCharacter::SetThrowGrenadeTimer(FName Channel, float Chance, bool bPerformCheck) {
    return false;
}

void AIndianaAiCharacter::SetStatusTagSuppressed(bool bSuppressed) {
}

void AIndianaAiCharacter::SetOrigin(const FTransform& NewTransform) {
}

void AIndianaAiCharacter::SetOccupyLocation(FVector Location, float Time) {
}

void AIndianaAiCharacter::SetNamedCooldown(const FName& Name, float Time) {
}

void AIndianaAiCharacter::SetMinMeleeBurrowAttackCapsuleDistance(float InCapsuleDistance) {
}

void AIndianaAiCharacter::SetMinMeleeAttackCapsuleDistance(float InCapsuleDistance) {
}

void AIndianaAiCharacter::SetIgnorePlayerPlacedTraps(bool bShouldIgnorePlayerPlacedTraps) {
}

void AIndianaAiCharacter::SetIgnoreDistractionDevices(bool bShouldIgnoreDistractionDevices) {
}

void AIndianaAiCharacter::SetHardPoint(AHardPoint* InHardPoint) {
}

void AIndianaAiCharacter::SetCinematicModeEnabled(bool bEnable, const FAICinematicModeParams& Params) {
}

void AIndianaAiCharacter::SetCanUseCover(bool bNewCanUseCover) {
}

void AIndianaAiCharacter::SetCanUnequipWeapon(bool bCanUnequip) {
}

void AIndianaAiCharacter::SetCanTether(bool bInCanTether) {
}

void AIndianaAiCharacter::SetAnchorOverrideLocation(FVector OverrideLocation) {
}

void AIndianaAiCharacter::SetAnchoredToPlayer(bool bAnchored) {
}

void AIndianaAiCharacter::ResetOriginTransform() {
}

void AIndianaAiCharacter::RefreshAI() {
}

float AIndianaAiCharacter::RangedCheckFromLocation(FVector FeetLocation) {
    return 0.0f;
}

float AIndianaAiCharacter::RangedCheck() {
    return 0.0f;
}

bool AIndianaAiCharacter::PlayCoverMontageWithWarp(ACoverNode* CoverNode, UAnimMontage* AnimMontage, FVector DestLocation, FVector DestAngle, bool bUseMontageDelta, bool bAdjustForTarget, bool bAdjustAngleForTarget, bool bReturnToNode) {
    return false;
}

UAnimMontage* AIndianaAiCharacter::PickCoverDestroyedReaction(ACoverNode* CoverNode, ECoverSide& OutCurrentCoverSide) {
    return NULL;
}

bool AIndianaAiCharacter::PickCoverAction(ACoverNode* CoverNode, ECoverActions ActionFilter, ECoverActions& OutCoverAction, FCoverActionAnim& OutCoverActionAnim, ECoverActions PreferredAction) {
    return false;
}

void AIndianaAiCharacter::OnWeaponEndUnequip(UEquipmentComponent* InEquipmentComponent, UWeapon* Weapon) {
}

void AIndianaAiCharacter::OnWeaponEndEquip(UEquipmentComponent* InEquipmentComponent, UWeapon* Weapon) {
}

void AIndianaAiCharacter::OnMontageEndDelegate(UAnimMontage* Montage, bool bInterrupted) {
}

void AIndianaAiCharacter::OnLootGenerated() {
}

void AIndianaAiCharacter::OnLocomotionStateUpdated(ELocomotionStateEnum NewState) {
}

void AIndianaAiCharacter::OnDeferredMovementFinished(bool bSuccess) {
}

void AIndianaAiCharacter::OnDamageEvent(const FCauseDamageInfo& CauseDamageInfo) {
}




void AIndianaAiCharacter::OnAlertStateChange(AActor* TargetActor, EAlertState PreviousAlertState, EAlertState TargetAlertState, bool bRestoring) {
}

void AIndianaAiCharacter::OnAIStartTraverse(ETraverseType TraverseType, int32 NavLinkDirection, AReservableNavLink* ReservableNavLink, ALadder* ClimbLadder) {
}


void AIndianaAiCharacter::OccupyNearbyCoverOnDowned(float CoverNodeOccupationPadding) {
}

bool AIndianaAiCharacter::MeleeReachable(bool bDebug) {
    return false;
}

bool AIndianaAiCharacter::MeleeNavWalk(FVector Start, FVector Target, FVector& End) {
    return false;
}

void AIndianaAiCharacter::MeleeNavPathFindCancel() {
}

void AIndianaAiCharacter::MeleeNavPathFind(const FOnMeleeNavPathFind& Delegate, FVector Destination) {
}

bool AIndianaAiCharacter::MeleeCheckFromLocation(FVector GroundLocation, float CapsuleDistance, float WidthRadius, bool bNavTrace, bool bDebug, const FName CooldownName, bool bRunExtraGeometryAvoidanceTests, float GeoAvoidanceWidthPadding, bool bIgnoreOtherCharacters) {
    return false;
}

bool AIndianaAiCharacter::MeleeCheck(float CapsuleDistance, float WidthRadius, bool bFacingTarget, bool bNavTrace, bool bDebug, bool bUseBurrowCheck, const FName CooldownName, bool bRunExtraGeometryAvoidanceTests, float GeoAvoidanceWidthPadding) {
    return false;
}

void AIndianaAiCharacter::K2_SetUseSearchingAnimLayer(const bool bSet) {
}

void AIndianaAiCharacter::K2_SetInteractionTarget(UInteractableComponent* InInteractionTarget) {
}

void AIndianaAiCharacter::K2_SetInteractionOverrides(TArray<EInteractionType> Interactions) {
}

void AIndianaAiCharacter::K2_SetInteractionAdditions(TArray<EInteractionType> Interactions) {
}

void AIndianaAiCharacter::K2_SetAnimationState(const EAnimTreeState AnimationState) {
}

void AIndianaAiCharacter::K2_RemoveInteractionOverride(EInteractionType Interaction) {
}

void AIndianaAiCharacter::K2_RemoveInteractionAddition(EInteractionType Interaction) {
}

bool AIndianaAiCharacter::K2_IsTrackingRegionFacingTarget(TEnumAsByte<ETrackingRegion> TrackingRegion, float Tolerance) const {
    return false;
}

bool AIndianaAiCharacter::K2_IsRegionNearGoal(TEnumAsByte<ETrackingRegion> Region, float DeltaDegrees) const {
    return false;
}

bool AIndianaAiCharacter::K2_IsPacifist() const {
    return false;
}

bool AIndianaAiCharacter::K2_IsEndangered() const {
    return false;
}

bool AIndianaAiCharacter::K2_GetShouldIgnoreDistractionDevices() const {
    return false;
}

FRotator AIndianaAiCharacter::K2_GetRegionGoalRotation(TEnumAsByte<ETrackingRegion> Region) const {
    return FRotator{};
}

FRotator AIndianaAiCharacter::K2_GetRegionGoalRemainingRotation(TEnumAsByte<ETrackingRegion> Region) const {
    return FRotator{};
}

float AIndianaAiCharacter::K2_GetRegionGoalRemainingDegrees(TEnumAsByte<ETrackingRegion> Region) const {
    return 0.0f;
}

FVector AIndianaAiCharacter::K2_GetRegionCurrentTargetLocation(TEnumAsByte<ETrackingRegion> Region, bool& bValid) const {
    return FVector{};
}

FRotator AIndianaAiCharacter::K2_GetRegionCurrentRotation(TEnumAsByte<ETrackingRegion> Region) const {
    return FRotator{};
}

FQuat AIndianaAiCharacter::K2_GetOriginRotation() const {
    return FQuat{};
}

FVector AIndianaAiCharacter::K2_GetOriginLocation() const {
    return FVector{};
}

FRotator AIndianaAiCharacter::K2_GetHeadRotation() const {
    return FRotator{};
}

FVector AIndianaAiCharacter::K2_GetHeadLocation() const {
    return FVector{};
}

UWeaponAnimationsTPV* AIndianaAiCharacter::K2_GetCurrentWeaponAnimations() const {
    return NULL;
}

UWeaponAnimationsCreature* AIndianaAiCharacter::K2_GetCurrentCreatureWeaponAnimations() const {
    return NULL;
}

bool AIndianaAiCharacter::K2_GetCompanionFollowTargetLocation(FVector& OutFollowTargetLocation) const {
    return false;
}

EAnimTreeState AIndianaAiCharacter::K2_GetAnimationState() {
    return EAnimTreeState::None;
}

FRotator AIndianaAiCharacter::K2_GetAimRotation() const {
    return FRotator{};
}

FVector AIndianaAiCharacter::K2_GetAimOriginLocation() const {
    return FVector{};
}

void AIndianaAiCharacter::K2_GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const {
}

void AIndianaAiCharacter::K2_ClearInteractionOverrides() {
}

void AIndianaAiCharacter::K2_ClearInteractionAdditions() {
}

void AIndianaAiCharacter::K2_AddInteractionOverride(EInteractionType Interaction) {
}

void AIndianaAiCharacter::K2_AddInteractionAddition(EInteractionType Interaction) {
}

bool AIndianaAiCharacter::JumpTo(FVector Destination) {
    return false;
}

bool AIndianaAiCharacter::IsUsingAnimationProxy(AAnimationProxyActor* AnimationProxyActor) const {
    return false;
}

bool AIndianaAiCharacter::IsTargetClearWorld() {
    return false;
}

bool AIndianaAiCharacter::IsTargetClearOfGrenadeFriendlyFireFromLocation(FVector Location) {
    return false;
}

bool AIndianaAiCharacter::IsTargetClearOfGrenadeFriendlyFire() {
    return false;
}

bool AIndianaAiCharacter::IsTargetClearOfFriendlyFireFromLocation(FVector Location, bool bForMelee) {
    return false;
}

bool AIndianaAiCharacter::IsTargetClearOfFriendlyFire() {
    return false;
}

bool AIndianaAiCharacter::IsStatusTagSuppressed() const {
    return false;
}

bool AIndianaAiCharacter::IsNavLoadedAtFeetLocation() const {
    return false;
}

bool AIndianaAiCharacter::IsNamedCooldownRunning(const FName& Name) {
    return false;
}

bool AIndianaAiCharacter::IsJumping() {
    return false;
}

bool AIndianaAiCharacter::IsElongated() const {
    return false;
}

bool AIndianaAiCharacter::IsDormant() const {
    return false;
}

bool AIndianaAiCharacter::IsCompanion() const {
    return false;
}

bool AIndianaAiCharacter::IsAnimationProxyTaskInProgress() const {
    return false;
}

bool AIndianaAiCharacter::IsAnimationProxyTaskComplete() const {
    return false;
}

bool AIndianaAiCharacter::IsAnchoredToPlayer() const {
    return false;
}

void AIndianaAiCharacter::HazardSpawned(AActor* Hazard, bool bSuccess) {
}

bool AIndianaAiCharacter::GetWanderSettingsFromSpawnModifiers(FAISettingsWander& OutWanderSettings, const bool bIncludeDefaultBehavior) {
    return false;
}

float AIndianaAiCharacter::GetTargetsSimpleCapsuleRadiusForMelee() const {
    return 0.0f;
}

float AIndianaAiCharacter::GetStationaryTime() const {
    return 0.0f;
}

APatrolNode* AIndianaAiCharacter::GetPatrolNodeFromSpawnModifiers(EPatrolType& OutPatrolType, bool& OutWantTeleport, const bool bIncludeDefaultBehavior) {
    return NULL;
}

bool AIndianaAiCharacter::GetPatrolNavigationFlagsFromSpawnModifiers(int32& OutNavigationFlags, bool bIncludeDefaultBehavior) {
    return false;
}

AIndianaAiController* AIndianaAiCharacter::GetOwningController() const {
    return NULL;
}

bool AIndianaAiCharacter::GetOverrideOriginFromSpawnModifiers(FVector& OutOrigin, const bool bIncludeDefaultBehavior) {
    return false;
}

float AIndianaAiCharacter::GetOutOfCombatStartDelay(const bool bIncludeDefaultBehavior) {
    return 0.0f;
}

float AIndianaAiCharacter::GetOccupyScore(FVector Location, float Radius, bool bLineOfSight, bool bIgnoreFurther, bool bIgnoreCorpses) {
    return 0.0f;
}

FVector AIndianaAiCharacter::GetOccupyLocation() {
    return FVector{};
}

int32 AIndianaAiCharacter::GetNumAIBuffZones() {
    return 0;
}

TArray<AIndianaCharacter*> AIndianaAiCharacter::GetNearbyCharacters() {
    return TArray<AIndianaCharacter*>();
}

float AIndianaAiCharacter::GetMinMeleeBurrowAttackCapsuleDistance() const {
    return 0.0f;
}

float AIndianaAiCharacter::GetMinMeleeAttackCapsuleDistance() const {
    return 0.0f;
}

ELostTargetSearchMode AIndianaAiCharacter::GetLostTargetSearchMode() const {
    return ELostTargetSearchMode::DirectSearch;
}

bool AIndianaAiCharacter::GetIsAiMeleeStallDebugEnabled() const {
    return false;
}

bool AIndianaAiCharacter::GetIdleMovementState(EAIMovementState& OutMovementState, const bool bIncludeDefaultBehavior) {
    return false;
}

bool AIndianaAiCharacter::GetFollowPlayerFromSpawnModifiers(bool& OutCanCrouch, const bool bIncludeDefaultBehavior) {
    return false;
}

AActor* AIndianaAiCharacter::GetFollowBehaviorFromSpawnModifiers(float& OutMinRange, float& OutMaxRange, float& OutRunRange, const bool bIncludeDefaultBehavior) {
    return NULL;
}

AEncounter* AIndianaAiCharacter::GetEncounter() const {
    return NULL;
}

FVector AIndianaAiCharacter::GetElongatedCenter() const {
    return FVector{};
}

float AIndianaAiCharacter::GetDefaultMoveToLocationAcceptanceRadius() const {
    return 0.0f;
}

float AIndianaAiCharacter::GetDamageMemory(FVector Location) const {
    return 0.0f;
}

UAnimMontage* AIndianaAiCharacter::GetCoverActionMontage() {
    return NULL;
}

UCompanionComponent* AIndianaAiCharacter::GetCompanionComponent() const {
    return NULL;
}

ECautiousBehaviorType AIndianaAiCharacter::GetCautiousBehaviorType() const {
    return ECautiousBehaviorType::WanderSearch;
}

float AIndianaAiCharacter::GetCapsuleDistanceToActor(const AActor* InTargetActor) const {
    return 0.0f;
}

bool AIndianaAiCharacter::GetAnimationProxyTeleportBehaviorFromSpawnModifiers(const bool bIncludeDefaultBehavior) {
    return false;
}

bool AIndianaAiCharacter::GetAnimationProxyNavigationFlagsFromSpawnModifiers(int32& OutNavigationFlags, const bool bIncludeDefaultBehavior) {
    return false;
}

bool AIndianaAiCharacter::GetAnimationProxyMovementStateFromSpawnModifiers(EAIMovementState& OutMovementState, const bool bIncludeDefaultBehavior) {
    return false;
}

AAnimationProxyActor* AIndianaAiCharacter::GetAnimationProxyActorFromSpawnModifiers(const bool bIncludeDefaultBehavior) {
    return NULL;
}

void AIndianaAiCharacter::EnableParkour() {
}

void AIndianaAiCharacter::DisableParkour() {
}

bool AIndianaAiCharacter::CombatShouldHide(bool bDebug) {
    return false;
}

bool AIndianaAiCharacter::CombatShouldFallback(bool bDebug) {
    return false;
}

bool AIndianaAiCharacter::CombatReachable(bool bDebug) {
    return false;
}

void AIndianaAiCharacter::ClearNamedCooldown(const FName& Name) {
}

bool AIndianaAiCharacter::CheckThrowGrenadeTimer(FName Channel) {
    return false;
}

bool AIndianaAiCharacter::CheckJumpClearance(FVector Destination, FVector& ProjectedDestination, float Radius, float MinHeight, float MaxHeight, AActor* IgnoreActor, bool bDebug) {
    return false;
}

bool AIndianaAiCharacter::CanUseCover() const {
    return false;
}

bool AIndianaAiCharacter::CanTether() const {
    return false;
}

bool AIndianaAiCharacter::CanParkour() {
    return false;
}

bool AIndianaAiCharacter::CanFireProjectileAtTarget(float SustainTime) {
    return false;
}

void AIndianaAiCharacter::BodyPartStateChanged(UHealthComponent* Health, FCauseDamageInfo CDI, bool bHealthy, bool bFromRestore) {
}

void AIndianaAiCharacter::BodyPartHealthChanged(UHealthComponent* Health, FGameplayTag BodyPart, float OldHealthNormalized, float NewHealthNormalized) {
}

void AIndianaAiCharacter::AwakenFromDormantUnaware() {
}

void AIndianaAiCharacter::AwakenFromDormantAndAttackPlayer() {
}

void AIndianaAiCharacter::AwakenFromDormant(AActor* ActorToEngage) {
}

void AIndianaAiCharacter::AssignStageMarkAfterTick(AStageMarkActor* StageMark, const UOEICineConversationInstance* Instance, const AStagePrefabActor* Stage, int32 AssignmentType) {
}

void AIndianaAiCharacter::AIDebugPrintTime(const FText Text, int32 Level, float Time, bool bEvent) {
}

void AIndianaAiCharacter::AIDebugPrintStringTime(const FString& Text, int32 Level, float Time, bool bEvent) {
}

void AIndianaAiCharacter::AIDebugPrintString(const FString& Text, int32 Level) {
}

void AIndianaAiCharacter::AIDebugPrint(const FText Text, int32 Level) {
}

int32 AIndianaAiCharacter::AIDebugLevel() {
    return 0;
}

void AIndianaAiCharacter::AddDamageMemory(FVector Center, float Damage) {
}


