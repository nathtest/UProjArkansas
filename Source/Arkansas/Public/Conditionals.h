#pragma once
#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
#include <GameplayTagContainer.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICommon -ObjectName=EBoolResult -FallbackName=EBoolResult
#include <EComparisonOperator.h>
#include <EOEIGender.h>
#include "ConditionalLibrary.h"
#include "EBountyLevel.h"
#include "EBribeDifficulty.h"
#include "EBuildType.h"
#include "EConditionalCrimeType.h"
#include "EDownLoadableContent.h"
#include "EOCLState.h"
#include "EPhaseOfDay.h"
#include "EQuestObjectiveStatus.h"
#include "EQuestStatus.h"
#include "ERankLevel.h"
#include "ESkill.h"
#include "ESkillDifficultyRange.h"
#include "ESkillDifficultyTier.h"
#include "ESpecialObsidianID.h"
#include "EStandingLevel.h"
#include "EStandingType.h"
#include "ETrapTriggerState.h"
#include "Templates/SubclassOf.h"
#include "Conditionals.generated.h"

class UAchievementDataAsset;
class UAptitude;
class UArmorItem;
class UBrandDataAsset;
class UBroadcastStationAsset;
class UConversationAsset;
class UDialogSpeechModifiersDataAsset;
class UFactionData;
class UFlaw;
class UItem;
class UMapInformation;
class UPerk;
class UPointOfInterestData;
class UShipDestinationData;
class UTrait;
class UTravelRegionData;
class UWeapon;

UCLASS(Blueprintable)
class UConditionals : public UConditionalLibrary {
    GENERATED_BODY()
public:
    UConditionals();

    UFUNCTION(BlueprintCallable)
    static bool SpeakerHasCheckpointPendingResume(FGuid ConversationID, FGuid SpeakerID);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredSkill(ESkill Skill, ESkillDifficultyRange DifficultyRange, ESkillDifficultyTier TierOverride, int32 SkillValueOverride, UDialogSpeechModifiersDataAsset* DialogSpeechModifiersDataAsset);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredQuestStatus(FGuid QuestID, EQuestStatus QuestStatus);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredQuestObjective(FGuid QuestID, int32 ObjectiveNodeID, EQuestObjectiveStatus ObjectiveNodeStatus);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredQuestEndState(FGuid QuestID, int32 EndStateID);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredQuest(FGuid QuestID, EQuestStatus QuestStatus, int32 ObjectiveNodeID, EQuestObjectiveStatus ObjectiveNodeStatus, int32 EndStateID);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredPlayerTrait(TSoftClassPtr<UTrait> Trait);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredPlayerPerk(TSoftClassPtr<UPerk> Perk);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredPlayerBackground(TSoftClassPtr<UAptitude> Aptitude);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredLuckyChance(bool bUseOverrideChance, float OverrideChance);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredItemValue(TSubclassOf<UItem> Item, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredItemCount(TSoftClassPtr<UItem> Item, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredHack(ESkillDifficultyRange DifficultyRange, ESkillDifficultyTier TierOverride, int32 SkillValueOverride, UDialogSpeechModifiersDataAsset* DialogSpeechModifiersDataAsset);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredGlobalInfo(const FGuid& Variable, EComparisonOperator Operator, int32 Value, FGuid GlobalScriptID, int32 StringID);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredFlaw(TSoftClassPtr<UFlaw> Flaw);
    
    UFUNCTION(BlueprintCallable)
    bool RequiredFactionStanding(TSubclassOf<UFactionData> Faction, EStandingType StandingType, EStandingLevel StandingLevel, EComparisonOperator Operator);
    
    UFUNCTION(BlueprintCallable)
    bool RequiredFactionRank(TSubclassOf<UFactionData> Faction, EComparisonOperator Operator, ERankLevel RankLevel, bool bRankEarned);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredCurrency(int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static bool RequiredCompanion(ESpecialObsidianID CompanionID);
    
    UFUNCTION(BlueprintCallable)
    static bool PlayerHasTrait(TSoftClassPtr<UTrait> Trait);
    
    UFUNCTION(BlueprintCallable)
    static bool PlayerHasSkillOrPerkPoints();
    
    UFUNCTION(BlueprintCallable)
    static bool PlayerHasPerk(TSoftClassPtr<UPerk> Perk);
    
    UFUNCTION(BlueprintCallable)
    static bool PlayerHasFlaw(TSoftClassPtr<UFlaw> Flaw);
    
    UFUNCTION(BlueprintCallable)
    static bool PlayerHasBackground(TSoftClassPtr<UAptitude> Aptitude);
    
    UFUNCTION(BlueprintCallable)
    static bool IsWireEnabled(const FGuid& WireID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsWeaponEquipped(TSoftClassPtr<UWeapon> Weapon, bool bIncludeDerivedClasses);
    
    UFUNCTION(BlueprintCallable)
    static bool IsWeaponBrandEquipped(UBrandDataAsset* Brand);
    
    UFUNCTION(BlueprintCallable)
    static bool IsTravelDestinationLocked(TSoftObjectPtr<UPointOfInterestData> TravelDestination);
    
    UFUNCTION(BlueprintCallable)
    static bool IsTravelDestinationHidden(TSoftObjectPtr<UPointOfInterestData> TravelDestination);
    
    UFUNCTION(BlueprintCallable)
    static bool IsTrapStateEqual(FGuid TrapObjectID, ETrapTriggerState State);
    
    UFUNCTION(BlueprintCallable)
    static bool IsTimeSlice(int32 StartHour, int32 EndHour);
    
    UFUNCTION(BlueprintCallable)
    static bool IsSpeakerGender(EOEIGender Gender);
    
    UFUNCTION(BlueprintCallable)
    static bool IsSpeakerCrowdCharacter();
    
    UFUNCTION(BlueprintCallable)
    static bool IsSpeaker(const FGuid& SpeakerID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsRestrictedAreaEnabled(FGuid RestrictedAreaID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsRespondingToCrime(EConditionalCrimeType Crime);
    
    UFUNCTION(BlueprintCallable)
    static bool IsQuestTracked(FGuid QuestID, EBoolResult& OutResult);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerWounded();
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerWithinVolume(FGameplayTag Type, FGameplayTag Flavor);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerSkillWithModifiers(ESkill Skill, EComparisonOperator Operator, ESkillDifficultyRange DifficultyRange, int32 TierOverride, int32 SkillValueOverride, bool bUseCompanionInterjection, UDialogSpeechModifiersDataAsset* DialogSpeechModifiersDataAsset);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerSkillLevelScaled(ESkill Skill, EComparisonOperator Operator, ESkillDifficultyTier SkillDifficultyTierOverride, ESkillDifficultyRange SkillDifficultyRange, bool bUseCompanionInterjection);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerSkill(ESkill Skill, EComparisonOperator Operator, ESkillDifficultyRange DifficultyRange, int32 TierOverride, int32 SkillValueOverride, bool bUseCompanionInterjection);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerShipLocation(TSoftObjectPtr<UShipDestinationData> ShipDestination);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerInStealth();
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerInCombat();
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerInActiveHazard();
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerElektrumExposure(float ExposureRatio, EComparisonOperator Operator);
    
    UFUNCTION(BlueprintCallable)
    bool IsPlayerBountyLevel(TSubclassOf<UFactionData> Faction, EComparisonOperator Operator, EBountyLevel BountyLevel, int32 OverrideBountyAmount);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerAwareOfPointOfInterest(UPointOfInterestData* POIData);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPhaseOfDay(EPhaseOfDay Phase);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPartyFull();
    
    UFUNCTION(BlueprintCallable)
    static bool IsPackagedBuild(EBuildType BuildType);
    
    UFUNCTION(BlueprintCallable)
    static bool IsOCLStateEqual(FGuid OCLObjectID, EOCLState State);
    
    UFUNCTION(BlueprintCallable)
    static bool IsObservationSuccess(int32 Node);
    
    UFUNCTION(BlueprintCallable)
    static bool IsNodeOffCooldown(int32 NodeID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsNight();
    
    UFUNCTION(BlueprintCallable)
    static bool IsInterrogationInRestrictedArea();
    
    UFUNCTION(BlueprintCallable)
    static bool IsInterrogationCrime(EConditionalCrimeType Crime);
    
    UFUNCTION(BlueprintCallable)
    static bool IsInRegion(TSoftObjectPtr<UTravelRegionData> TravelRegion);
    
    UFUNCTION(BlueprintCallable)
    static bool IsInMap(TSoftObjectPtr<UMapInformation> MapID);
    
    UFUNCTION(BlueprintCallable)
    bool IsFactionStanding(TSubclassOf<UFactionData> Faction, EStandingType StandingType, EStandingLevel StandingLevel, EComparisonOperator Operator);
    
    UFUNCTION(BlueprintCallable)
    static bool IsFactionRelationship(TSubclassOf<UFactionData> Faction, TEnumAsByte<ETeamAttitude::Type> AttitudeType);
    
    UFUNCTION(BlueprintCallable)
    bool IsFactionRank(TSubclassOf<UFactionData> Faction, EComparisonOperator Operator, ERankLevel RankLevel, bool bRankEarned);
    
    UFUNCTION(BlueprintCallable)
    static bool IsDay();
    
    UFUNCTION(BlueprintCallable)
    static bool IsCurrentActiveCompanionAmount(EComparisonOperator Operator, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCompanionUnlocked(ESpecialObsidianID CompanionID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCompanionInActiveParty(ESpecialObsidianID Companion);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCompanionDismissed(ESpecialObsidianID CompanionID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsAwareOfTravelDestination(TSoftObjectPtr<UPointOfInterestData> TravelDestination);
    
    UFUNCTION(BlueprintCallable)
    static bool IsAwareOfRegion(TSoftObjectPtr<UTravelRegionData> TravelRegion);
    
    UFUNCTION(BlueprintCallable)
    static bool IsArmorEquipped(TSoftClassPtr<UArmorItem> ArmorItem, bool bIncludeDerivedClasses);
    
    UFUNCTION(BlueprintCallable)
    static bool IsArmorBrandEquipped(UBrandDataAsset* Brand);
    
    UFUNCTION(BlueprintCallable)
    static bool IsAnyArmorEquipped();
    
    UFUNCTION(BlueprintCallable)
    static bool HasVisitedTravelDestination(TSoftObjectPtr<UPointOfInterestData> TravelDestination);
    
    UFUNCTION(BlueprintCallable)
    static bool HasVisitedRegion(TSoftObjectPtr<UTravelRegionData> TravelRegion);
    
    UFUNCTION(BlueprintCallable)
    static bool HasTimeElapsedSinceNamedTimestamp(const FString& TimestampName, int32 Days, int32 Hours, int32 Minutes, float Seconds);
    
    UFUNCTION(BlueprintCallable)
    static bool HasPlayerOnlyHeardAboutPointOfInterest(UPointOfInterestData* POIData);
    
    UFUNCTION(BlueprintCallable)
    static bool HasPlayerDiscoveredPointOfInterest(UPointOfInterestData* POIData);
    
    UFUNCTION(BlueprintCallable)
    static bool HasItemValue(const FGuid& Variable, TSubclassOf<UItem> Item);
    
    UFUNCTION(BlueprintCallable)
    static bool HasItemsByTag(const FString& GameplayTag, EComparisonOperator Operator, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static bool HasItemCountOnActor(const FGuid& ActorId, TSubclassOf<UItem> ItemType, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static bool HasItem(TSoftClassPtr<UItem> Item, EComparisonOperator Operator, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static bool HasInternetConnection();
    
    UFUNCTION(BlueprintCallable)
    bool HasInstanceBeenChecked(UConversationAsset* Conversation, EComparisonOperator Operator, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static bool HasDLCTag(const FGameplayTag& DLCEntitlementTag);
    
    UFUNCTION(BlueprintCallable)
    static bool HasDLC(EDownLoadableContent DLC);
    
    UFUNCTION(BlueprintCallable)
    static bool HasCompletedAchievement(UAchievementDataAsset* Achievement);
    
    UFUNCTION(BlueprintCallable)
    static void GetOCLState(FGuid OCLObjectID, EOCLState& State);
    
    UFUNCTION(BlueprintCallable)
    static bool DoesPlayerNeedDoctor();
    
    UFUNCTION(BlueprintCallable)
    static bool DoesConversationNodePass(FGuid ConversationID, int32 NodeID);
    
    UFUNCTION(BlueprintCallable)
    static bool CompanionWantsToTalk(ESpecialObsidianID CompanionID);
    
    UFUNCTION(BlueprintCallable)
    static bool CompanionHasTrait(ESpecialObsidianID CompanionID, TSoftClassPtr<UTrait> Trait);
    
    UFUNCTION(BlueprintCallable)
    static bool CompanionHasPerk(ESpecialObsidianID CompanionID, TSoftClassPtr<UPerk> Perk);
    
    UFUNCTION(BlueprintCallable)
    static bool CanPlayerSafelyTakePickup(const FGuid& PickupID);
    
    UFUNCTION(BlueprintCallable)
    static bool CanPlayerSafelyTakeItemTypeInContainer(const FGuid& ContainerID, const FString& Item);
    
    UFUNCTION(BlueprintCallable)
    bool CanPlayerPayBounty(TSubclassOf<UFactionData> Faction);
    
    UFUNCTION(BlueprintCallable)
    bool CanPlayerHearRadioStation(TSubclassOf<UBroadcastStationAsset> BroadcastStationAsset);
    
    UFUNCTION(BlueprintCallable)
    static bool CanPlayerDiscoverPointOfInterest(UPointOfInterestData* POIData);
    
    UFUNCTION(BlueprintCallable)
    static bool CanPlayerAffordDoctor();
    
    UFUNCTION(BlueprintCallable)
    static bool CanInterrogationBribe(EBribeDifficulty BribeDifficulty);
    
    UFUNCTION(BlueprintCallable)
    static bool CanExitGameViaMenu();
    
    UFUNCTION(BlueprintCallable)
    static bool CanBribe(EBribeDifficulty BribeDifficulty, ESkillDifficultyTier DifficultyTier);
    
    UFUNCTION(BlueprintCallable)
    static bool CanAccessTravelDestination(TSoftObjectPtr<UPointOfInterestData> TravelDestination);
    
};

