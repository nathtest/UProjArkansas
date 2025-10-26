#include "AISequencerBehaviors.h"
#include "MovieSceneObjectBindingID.h"

UAISequencerBehaviors::UAISequencerBehaviors() {
}

void UAISequencerBehaviors::VaultToLocation(AIndianaAiCharacter* Character, FVector LocalLandingLocation, FVector LocalLedgeFrontLocation, FVector LocalLedgeBackLocation)  {
}

void UAISequencerBehaviors::UsePreviousAnimProxy(AIndianaAiCharacter* Character)  {
}

void UAISequencerBehaviors::UseAnimProxy(AIndianaAiCharacter* Character, FMovieSceneObjectBindingID AnimProxyInteractableBinding, const FGameplayTag SlotKey, const bool bTeleport, const bool bTeleportOnMoveFail, const bool bInterruptOnMove, const bool bInfiniteDuration, const bool bAutoDeactivate)  {
}

void UAISequencerBehaviors::UnequipArmorInSlot(AIndianaAiCharacter* Character, EArmorSlot ArmorSlot)  {
}

void UAISequencerBehaviors::TriggerQuickMelee(AIndianaAiCharacter* Character)  {
}

void UAISequencerBehaviors::Suicide(AIndianaAiCharacter* Character)  {
}

void UAISequencerBehaviors::StopUsingAnimProxy(AIndianaAiCharacter* Character, bool bSkipProxyExit, bool bExitImmediatelyOnNodeSkip)  {
}

void UAISequencerBehaviors::ShootTarget_SwitchToNeutralAnimState(TWeakObjectPtr<AIndianaAiCharacter> InCharacter, bool bInstantBlend) const  {
}

void UAISequencerBehaviors::ShootTarget_StopShooting(TWeakObjectPtr<AIndianaAiCharacter> InCharacter) const  {
}

void UAISequencerBehaviors::ShootTarget_OnWeaponAttack(UWeapon* Weapon) const {
}

void UAISequencerBehaviors::ShootTarget_OnTargetTakenDamage(const FCauseDamageInfo& CauseDamageInfo) const  {
}

void UAISequencerBehaviors::ShootTarget_OnPlayerSkippedNode(UOwConversationInstance* InConversationInstance) const {
}

void UAISequencerBehaviors::ShootTarget_CombatStateFullyBlended(TWeakObjectPtr<AIndianaAiCharacter> InCharacter) const {
}

void UAISequencerBehaviors::ShootTarget(AIndianaAiCharacter* Character, const FMovieSceneObjectBindingID& Target, int32 NumOfShots, int32 InstantKillShotIndex, FName SocketOnTarget, bool bShouldDismemberOnKill, bool bBlendAnimationState)  {
}

void UAISequencerBehaviors::SetOrientation(AIndianaAiCharacter* Character, TEnumAsByte<ETrackingRegion> TrackingRegion, FAIOrientationControl AIOrientationControl)  {
}

void UAISequencerBehaviors::SetHeadTrackingLockState(AIndianaAiCharacter* Character, bool bLocked, bool bMaintainCurrentOrientation)  {
}

void UAISequencerBehaviors::SetConversationLookAtTarget(AIndianaAiCharacter* Character, const FMovieSceneObjectBindingID& Binding, bool bPersist, bool bTurnBody, bool bSnapToLookAtOnNodeSkipped, const FForceBodyTrackingAngleParams& ExactAngleParams)  {
}

void UAISequencerBehaviors::SetConversationBodyRotationComfortAngle(AIndianaAiCharacter* Character, float Angle, bool bReevaluateBodyAngle)  {
}

void UAISequencerBehaviors::SetCanUnequipWeapon(AIndianaAiCharacter* Character, bool bCanUnequip)  {
}

void UAISequencerBehaviors::SetBodyTrackingLockState(AIndianaAiCharacter* Character, bool bLocked, bool bMaintainCurrentOrientation)  {
}

void UAISequencerBehaviors::SetBodyTrackingIgnoreState(AIndianaAiCharacter* Character, TEnumAsByte<ETrackingRegion> TrackingRegion, bool bIgnoreBodyTracking)  {
}

void UAISequencerBehaviors::ResetConversationBodyRotationComfortAngle(AIndianaAiCharacter* Character)  {
}

void UAISequencerBehaviors::RemoveForcedBodyAngleRelativeToTarget(AIndianaAiCharacter* Character)  {
}

void UAISequencerBehaviors::RemoveCurrentStageMarkLock(AIndianaAiCharacter* Character)  {
}

void UAISequencerBehaviors::RegisterConversationParticipant(AIndianaAiCharacter* Character)  {
}

void UAISequencerBehaviors::PlayMotionWarpingAnimMontage(AIndianaAiCharacter* Character, UAnimMontage* MontageToPlay, TArray<FTransform> LocalSyncTransforms)  {
}

void UAISequencerBehaviors::PlayAnimMontage(AIndianaAiCharacter* Character, UAnimMontage* MontageToPlay)  {
}

void UAISequencerBehaviors::MantleToLocation(AIndianaAiCharacter* Character, FVector LocalLandingLocation, FVector LocalLedgeLocation)  {
}

void UAISequencerBehaviors::JumpAcrossToLocation(AIndianaAiCharacter* Character, FVector LocalLandingLocation, float HeightOverride)  {
}

void UAISequencerBehaviors::HolsterWeapon(AIndianaAiCharacter* Character, bool bInstant)  {
}

void UAISequencerBehaviors::FireWeaponStop(AIndianaAiCharacter* Character)  {
}

void UAISequencerBehaviors::FireWeaponStart(AIndianaAiCharacter* Character, const FAIWeaponFiringSettings& AIWeaponFiringSettings)  {
}

void UAISequencerBehaviors::ExitSequencer(AIndianaAiCharacter* Character)  {
}

void UAISequencerBehaviors::EquipWeaponByTag(AIndianaAiCharacter* Character, const FGameplayTag Tag, bool bInstant)  {
}

void UAISequencerBehaviors::EquipWeaponBySlot(AIndianaAiCharacter* Character, int32 SlotIndex, bool bInstant)  {
}

void UAISequencerBehaviors::EquipWeaponByInstance(AIndianaAiCharacter* Character, const UWeapon* Weapon, bool bInstant)  {
}

void UAISequencerBehaviors::EquipItem(AIndianaAiCharacter* Character, const FItemDefinitionVariant& ItemDefinition)  {
}

void UAISequencerBehaviors::DropDownToLocation(AIndianaAiCharacter* Character, FVector LocalLandingLocation, FVector LocalLedgeLocation)  {
}

void UAISequencerBehaviors::ClearPersistentLookAtTarget(AIndianaAiCharacter* Character)  {
}

void UAISequencerBehaviors::ClearOrientation(AIndianaAiCharacter* Character, TEnumAsByte<ETrackingRegion> TrackingRegion)  {
}

void UAISequencerBehaviors::ClearAllOrientation(AIndianaAiCharacter* Character)  {
}

void UAISequencerBehaviors::CallGroupBehaviorEvent(AIndianaAiCharacter* Character, FName EventName) {
}

void UAISequencerBehaviors::AssignStageMark(AIndianaAiCharacter* Character, FMovieSceneObjectBindingID StageMarkActorBinding, EStageMarkAssignmentType StageMarkAssignmentType, bool bApplyStageMarkLock, bool bTeleportOnNodeSkipped)  {
}

void UAISequencerBehaviors::ApplyForcedBodyAngleRelativeToTarget(AIndianaAiCharacter* Character, float InAngle) {
}

