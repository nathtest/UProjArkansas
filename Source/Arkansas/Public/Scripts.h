#pragma once
#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
#include <GameplayTagContainer.h>
#include "ScriptLibrary.h"
#include "EArithmeticOperation.h"
#include "EBountyAdjustment.h"
#include "EBribeDifficulty.h"
#include "ECompanionSlot.h"
#include "ECooldownLength.h"
#include "EEmotion.h"
#include "ELookTargetRegion.h"
#include "EPosture.h"
#include "ERankAdjustment.h"
#include "ERestrictedAreaState.h"
#include "EScreenPersonalityType.h"
#include "ESkillDifficultyRange.h"
#include "ESkillDifficultyTier.h"
#include "ESpecialObsidianID.h"
#include "ESpeechAttackType.h"
#include "EStandingAdjustment.h"
#include "Templates/SubclassOf.h"
#include "Scripts.generated.h"

class UAchievementDataAsset;
class UAptitude;
class UAudioEvent;
class UBaseTeamData;
class UBroadcastStationAsset;
class UConversationAsset;
class UCraftingRecipe;
class UFactionData;
class UFlaw;
class UItem;
class UOEICinePresentationMode;
class UPerk;
class UPointOfInterestData;
class UShipDestinationData;
class UStaticLootList;
class UTrait;
class UTravelRegionData;

UCLASS(Blueprintable)
class UScripts : public UScriptLibrary {
    GENERATED_BODY()
public:
    UScripts();

    UFUNCTION(BlueprintCallable)
    static void WireTogglePower(const FGuid& WireID);
    
    UFUNCTION(BlueprintCallable)
    static void WireSetPower(const FGuid& WireID, bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    static void UpdateFogForVolume(const FGuid& FogOfWarVolumeID);
    
    UFUNCTION(BlueprintCallable)
    static void UpdateArchiveScreenPersonality(EScreenPersonalityType PersonalityType, bool bEnableScreen);
    
    UFUNCTION(BlueprintCallable)
    static void UnsealOCL(const FGuid& OCLObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void UnlockOCL(const FGuid& OCLObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void UnlockComputer(const FGuid& ComputerObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void UnlockCompanion(ESpecialObsidianID CompanionID);
    
    UFUNCTION(BlueprintCallable)
    static void UnjamOCL(const FGuid& OCLObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void UnbarOCL(const FGuid& OCLObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void TreatPartyViaDoctor(bool bIsFreeTreatment);
    
    UFUNCTION(BlueprintCallable)
    static void TravelToDestination(UPointOfInterestData* TravelDestination, bool bTriggerAutosave);
    
    UFUNCTION(BlueprintCallable)
    static void TransferBountyToNPC(TSubclassOf<UFactionData> Faction, const FGuid& SpeakerID);
    
    UFUNCTION(BlueprintCallable)
    static void StopLoudspeaker(const FString& StationTag, bool bPreventRestart);
    
    UFUNCTION(BlueprintCallable)
    static void StartLoudspeaker(const FString& StationTag, bool bForceStart, int32 StartNode);
    
    UFUNCTION(BlueprintCallable)
    static void SpeechAttackAction(ESpeechAttackType BuffDebuffType, const FGuid& CharacterID, FString& OtherTeam, bool bMutual);
    
    UFUNCTION(BlueprintCallable)
    static void ShowWorkbench();
    
    UFUNCTION(BlueprintCallable)
    static void ShowBeacon(const FGuid& BeaconObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void SetVisitedTravelDestination(UPointOfInterestData* TravelDestination);
    
    UFUNCTION(BlueprintCallable)
    static void SetVisitedRegion(UTravelRegionData* TravelRegion);
    
    UFUNCTION(BlueprintCallable)
    static void SetTravelDestinationLocked(UPointOfInterestData* TravelDestination, bool bLocked);
    
    UFUNCTION(BlueprintCallable)
    static void SetTravelDestinationHidden(UPointOfInterestData* TravelDestination, bool bHidden);
    
    UFUNCTION(BlueprintCallable)
    static void SetTrackedQuest(FGuid QuestID);
    
    UFUNCTION(BlueprintCallable)
    static void SetTeamRelationship(TSubclassOf<UBaseTeamData> SourceTeam, TSubclassOf<UBaseTeamData> OtherTeam, TEnumAsByte<ETeamAttitude::Type> Relationship, bool bMutual);
    
    UFUNCTION(BlueprintCallable)
    static void SetTalkIdleOverrideGameplayTag(FGuid Actor, FGameplayTag TalkIdleOverrideGameplayTag, FGameplayTag EmotionGameplayTag, float Delay, float Duration, bool Persist);
    
    UFUNCTION(BlueprintCallable)
    static void SetTalkIdleOverride(FGuid Actor, FName TalkIdleOverrideName, EEmotion Emotion, float Delay, float Duration, bool Persist);
    
    UFUNCTION(BlueprintCallable)
    static void SetSpeakersTalkIdleOverrideGameplayTag(FGameplayTag TalkIdleOverrideGameplayTag, FGameplayTag EmotionGameplayTag, float Delay, float Duration, bool Persist);
    
    UFUNCTION(BlueprintCallable)
    static void SetSpeakersTalkIdleOverride(FName TalkIdleOverrideName, EEmotion Emotion, float Delay, float Duration, bool Persist);
    
    UFUNCTION(BlueprintCallable)
    static void SetSpeakersEmotionFull(EEmotion Emotion, float Delay, float Duration, float HeadStrength, bool Persist, bool AffectHead, bool AffectBody);
    
    UFUNCTION(BlueprintCallable)
    static void SetSpeakersDefaultEmotion(EEmotion Emotion);
    
    UFUNCTION(BlueprintCallable)
    static void SetSlideshowImageKey(FString& ImageKey);
    
    UFUNCTION(BlueprintCallable)
    static void SetShouldDisplayOverrideName(const FGuid& CharacterID, bool bUseOverrideName);
    
    UFUNCTION(BlueprintCallable)
    static void SetShipLocation(UShipDestinationData* ShipDestination);
    
    UFUNCTION(BlueprintCallable)
    static void SetRestrictedAreaState(const FGuid& RestrictedAreaIdID, ERestrictedAreaState RestrictedAreaState);
    
    UFUNCTION(BlueprintCallable)
    static void SetRestrictedAreaAccess(const FGuid& RestrictedAreaIdID, bool bIsAccessible);
    
    UFUNCTION(BlueprintCallable)
    static void SetPresentationMode(TSubclassOf<UOEICinePresentationMode> PresentationMode);
    
    UFUNCTION(BlueprintCallable)
    static void SetPosture(EPosture Posture, float Delay, float Duration, bool Persist);
    
    UFUNCTION(BlueprintCallable)
    static void SetPointOfInterestDiscovered(UPointOfInterestData* PointOfInterestData, bool bCanAwardXP);
    
    UFUNCTION(BlueprintCallable)
    static void SetPlayerRelationship(const FGuid& CharacterID, TEnumAsByte<ETeamAttitude::Type> InRelationship);
    
    UFUNCTION(BlueprintCallable)
    static void SetPlayerOwnershipOfItemTypeInContainer(const FGuid& ContainerID, TSubclassOf<UItem> Item, bool bPlayerOwned, bool bClearNonPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void SetPlayerOwnershipOfItemsInContainer(const FGuid& ContainerID, bool bPlayerOwned, bool bClearNonPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void SetPickupPlayerOwnership(const FGuid& PickupID, bool bPlayerOwned, bool bClearNonPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void SetPickupNonPlayerOwnership(const FGuid& PickupID, const FGuid& Actor, bool bClearPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void SetPickupFactionOwnership(const FGuid& PickupID, TSubclassOf<UFactionData> Faction, bool bClearPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void SetNonPlayerOwnershipOfItemTypeInContainer(const FGuid& ContainerID, TSubclassOf<UItem> Item, const FGuid& Actor, bool bClearPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void SetNonPlayerOwnershipOfItemsInContainer(const FGuid& ContainerID, const FGuid& Actor, bool bClearPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void SetNodeCooldown(ECooldownLength Length, bool TrackPerVolume);
    
    UFUNCTION(BlueprintCallable)
    static void SetMusicVolumeLerpTime(const FGuid& ActorId, bool bCombat, bool bEnter, float LerpTime);
    
    UFUNCTION(BlueprintCallable)
    static void SetMusicVolumeIntensityLimit(const FGuid& ActorId, bool bCombat, bool bMinimum, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetMusicVolumeActivationDelay(const FGuid& ActorId, float Delay);
    
    UFUNCTION(BlueprintCallable)
    void SetKillOnSight(TSubclassOf<UFactionData> Faction);
    
    UFUNCTION(BlueprintCallable)
    static void SetHazardEnabled(const FGuid& HazardActorID, bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    static void SetFactionOwnershipOfItemTypeInContainer(const FGuid& ContainerID, TSubclassOf<UItem> Item, TSubclassOf<UFactionData> Faction, bool bClearPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void SetFactionOwnershipOfItemsInContainer(const FGuid& ContainerID, TSubclassOf<UFactionData> Faction, bool bClearPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void SetEmotionFull(FGuid Actor, EEmotion Emotion, float Delay, float Duration, float HeadStrength, bool Persist, bool AffectHead, bool AffectBody);
    
    UFUNCTION(BlueprintCallable)
    static void SetDefaultEmotion(FGuid Actor, EEmotion Emotion);
    
    UFUNCTION(BlueprintCallable)
    static void SetConversationLookTarget(FGuid Actor, FGuid Target, bool bRotateBody, bool bStickyTarget, ELookTargetRegion LookTargetRegion);
    
    UFUNCTION(BlueprintCallable)
    static void SetCompanionWantsToTalk(ESpecialObsidianID CompanionID, bool bWantsToTalk);
    
    UFUNCTION(BlueprintCallable)
    static void SetCompanionAccessory(ESpecialObsidianID CompanionID, TSubclassOf<UItem> AccessoryClass, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    static void SetBroadcastRTPC(UBroadcastStationAsset* Station, FName RTPC, float Value, bool bShouldReset);
    
    UFUNCTION(BlueprintCallable)
    static void SetAwareOfTravelDestination(UPointOfInterestData* TravelDestination);
    
    UFUNCTION(BlueprintCallable)
    static void SetAwareOfRegion(UTravelRegionData* TravelRegion);
    
    UFUNCTION(BlueprintCallable)
    static void SealOCL(const FGuid& OCLObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void ReplaceCompanionInSlot(ESpecialObsidianID CompanionID, ECompanionSlot CommpanionSlot);
    
    UFUNCTION(BlueprintCallable)
    static void RemovePlayerBounty(TSubclassOf<UFactionData> Faction);
    
    UFUNCTION(BlueprintCallable)
    static void RemovePerkFromActor(const FGuid& ActorId, const TSubclassOf<UPerk> Perk);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveItemFromPlayer(TSubclassOf<UItem> Item, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveItemFromActor(const FGuid& ActorId, TSubclassOf<UItem> Item, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveCurrency(const FGuid& ActorId, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveCompanionFromParty(ESpecialObsidianID CompanionID, bool bDespawn);
    
    UFUNCTION(BlueprintCallable)
    static void RemoteEvent(const FString& EventName);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterNamedTimestamp(const FString& TimestampName);
    
    UFUNCTION(BlueprintCallable)
    void ReducePlayerBounty(TSubclassOf<UFactionData> Faction, EBountyAdjustment BountySize, int32 OverrideBountySize);
    
    UFUNCTION(BlueprintCallable)
    static void PlayRadioSong(const FString& StationTag, bool bPlayRandom, int32 SongIndex, const FString& SongTag);
    
    UFUNCTION(BlueprintCallable)
    static void PlayBroadcastRadioSong(UBroadcastStationAsset* Station, int32 SongIndex);
    
    UFUNCTION(BlueprintCallable)
    static void PlayBroadcastAudioEvent(UBroadcastStationAsset* Station, UAudioEvent* Event);
    
    UFUNCTION(BlueprintCallable)
    static void PlayAudioEvent(UAudioEvent* Event);
    
    UFUNCTION(BlueprintCallable)
    static void PayOffBounty(TSubclassOf<UFactionData> Faction);
    
    UFUNCTION(BlueprintCallable)
    static void OpenOCL(const FGuid& OCLObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void OfferQuest(FGuid QuestID, int32 StartAlternateDescriptionIndex, int32 MentionAlternateDescriptionIndex);
    
    UFUNCTION(BlueprintCallable)
    static void ObservationSkillFeedback(ESkillDifficultyRange DifficultyRange, int32 FeedbackStringID, ESkillDifficultyTier SkillDifficultyTierOverride, int32 SkillValueOverride);
    
    UFUNCTION(BlueprintCallable)
    static void MentionPointOfInterest(UPointOfInterestData* PointOfInterestData);
    
    UFUNCTION(BlueprintCallable)
    static void MakePointOfInterestDiscoverable(UPointOfInterestData* PointOfInterestData, bool bStillHidden);
    
    UFUNCTION(BlueprintCallable)
    static void MainMenuSettings();
    
    UFUNCTION(BlueprintCallable)
    static void MainMenuNewGame();
    
    UFUNCTION(BlueprintCallable)
    static void MainMenuLoadGame();
    
    UFUNCTION(BlueprintCallable)
    static void MainMenuExtras();
    
    UFUNCTION(BlueprintCallable)
    static void MainMenuExitGame();
    
    UFUNCTION(BlueprintCallable)
    static void MainMenuDeliverables();
    
    UFUNCTION(BlueprintCallable)
    static void MainMenuContinueGame();
    
    UFUNCTION(BlueprintCallable)
    static void LockOCL(const FGuid& OCLObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void LockComputer(const FGuid& ComputerObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void KillNPC(const FGuid& Character);
    
    UFUNCTION(BlueprintCallable)
    static void JamOCL(const FGuid& OCLObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void InterrogationBribe();
    
    UFUNCTION(BlueprintCallable)
    void IncrementInstanceCount(const FString& Conversation, int32 IncrementAmount);
    
    UFUNCTION(BlueprintCallable)
    static void IncrementAchievement(UAchievementDataAsset* Achievement, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static void HidePointOfInterest(UPointOfInterestData* PointOfInterestData);
    
    UFUNCTION(BlueprintCallable)
    static void HideBeacon(const FGuid& BeaconObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void GiveTrait(UPARAM(Ref) TSubclassOf<UTrait>& Trait);
    
    UFUNCTION(BlueprintCallable)
    static void GivePerkToCompanion(ESpecialObsidianID CompanionID, const TSubclassOf<UPerk> Perk);
    
    UFUNCTION(BlueprintCallable)
    static void GivePerkToActor(const FGuid& ActorId, const TSubclassOf<UPerk> Perk);
    
    UFUNCTION(BlueprintCallable)
    static void GiveLootToPlayer(UStaticLootList* StaticLootList);
    
    UFUNCTION(BlueprintCallable)
    static void GiveLootToActor(const FGuid& ActorId, UStaticLootList* StaticLootList);
    
    UFUNCTION(BlueprintCallable)
    static void GiveItemToPlayer(TSubclassOf<UItem> Item, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static void GiveItemToActor(const FGuid& ActorId, TSubclassOf<UItem> Item, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static void GiveFlawToPlayer(const TSubclassOf<UFlaw> FlawSubclass);
    
    UFUNCTION(BlueprintCallable)
    static void GiveCurrency(const FGuid& ActorId, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static void GiveBackground(UPARAM(Ref) TSubclassOf<UAptitude>& Background);
    
    UFUNCTION(BlueprintCallable)
    static void GiveAudioLogOrTransmission(TSubclassOf<UItem> AudioLogTransmission);
    
    UFUNCTION(BlueprintCallable)
    static void ForcePlayRadioConversation(const FString& StationTag, UConversationAsset* Conversation);
    
    UFUNCTION(BlueprintCallable)
    static void DisplayThisWillBeRemembered();
    
    UFUNCTION(BlueprintCallable)
    static void DismissCompanion(ESpecialObsidianID CompanionID, bool bDespawn);
    
    UFUNCTION(BlueprintCallable)
    static void DisarmTrap(const FGuid& TrapObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void CompleteAchievement(UAchievementDataAsset* Achievement);
    
    UFUNCTION(BlueprintCallable)
    static void CloseOCL(const FGuid& OCLObjectID, bool Block, bool bSeal);
    
    UFUNCTION(BlueprintCallable)
    static void ClearTalkIdleOverrideOnNextEmotionChange(FGuid Actor);
    
    UFUNCTION(BlueprintCallable)
    static void ClearTalkIdleOverride(FGuid Actor, EEmotion Emotion, float Duration, bool Persist);
    
    UFUNCTION(BlueprintCallable)
    static void ClearSpeakersTalkIdleOverrideOnNextEmotionChange();
    
    UFUNCTION(BlueprintCallable)
    static void ClearSpeakersTalkIdleOverride(EEmotion Emotion, float Duration, bool Persist);
    
    UFUNCTION(BlueprintCallable)
    static void ClearSpeakersDefaultEmotion();
    
    UFUNCTION(BlueprintCallable)
    static void ClearPickupOwnerships(const FGuid& PickupID, bool bClearPlayerOwnership, bool bClearNonPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void ClearOwnershipsOfItemTypeInContainer(const FGuid& ContainerID, TSubclassOf<UItem> Item, bool bClearPlayerOwnership, bool bClearNonPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void ClearOwnershipsOfItemsInContainer(const FGuid& ContainerID, bool bClearPlayerOwnership, bool bClearNonPlayerOwnership);
    
    UFUNCTION(BlueprintCallable)
    static void ClearNamedTimestamp(const FString& TimestampName);
    
    UFUNCTION(BlueprintCallable)
    void ClearInstanceCount(const FString& Conversation);
    
    UFUNCTION(BlueprintCallable)
    static void ClearDefaultEmotion(FGuid Actor);
    
    UFUNCTION(BlueprintCallable)
    static void ClearConversationLookTarget(FGuid Actor, bool bStickyTarget, ELookTargetRegion LookTargetRegion);
    
    UFUNCTION(BlueprintCallable)
    static void BuyItemWithCurrency(TSubclassOf<UItem> Item, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static void Bribe(EBribeDifficulty BribeDifficulty, ESkillDifficultyTier DifficultyTier);
    
    UFUNCTION(BlueprintCallable)
    static void BeginTradeWithSpeaker();
    
    UFUNCTION(BlueprintCallable)
    static void BarOCL(const FGuid& OCLObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void ArmTrap(const FGuid& TrapObjectID);
    
    UFUNCTION(BlueprintCallable)
    static void AdvanceToTime(float Days, float Hours, float Minutes, float Seconds);
    
    UFUNCTION(BlueprintCallable)
    static void AdvanceTime(float Days, float Hours, float Minutes, float Seconds);
    
    UFUNCTION(BlueprintCallable)
    void AdjustFactionStanding(TSubclassOf<UFactionData> Faction, EStandingAdjustment StandingAdjustment, bool bPositiveAdjustment, float CustomStandingAdjustment);
    
    UFUNCTION(BlueprintCallable)
    void AdjustFactionRank(TSubclassOf<UFactionData> Faction, ERankAdjustment RankAdjustment, bool bPositiveAdjustment, float CustomRankAdjustment);
    
    UFUNCTION(BlueprintCallable)
    void AddPlayerBounty(TSubclassOf<UFactionData> Faction, EBountyAdjustment BountySize, int32 OverrideBountySize);
    
    UFUNCTION(BlueprintCallable)
    static void AddMusicVolumeModifier(const FGuid& ActorId, bool bCombat, EArithmeticOperation ArithmeticOperation, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void AddCraftingRecipe(TSubclassOf<UCraftingRecipe> Recipe);
    
    UFUNCTION(BlueprintCallable)
    static void AddCompanionToParty(ESpecialObsidianID CompanionID);
    
};

