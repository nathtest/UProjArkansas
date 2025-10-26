#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
#include <GameplayTagContainer.h>
#include <EComparisonOperator.h>
#include "ConditionalLibrary.h"
#include "EArmorSlot.h"
#include "EGameDifficulty.h"
#include "ERankLevel.h"
#include "ESkill.h"
#include "ESkillDifficultyRange.h"
#include "ESpecialObsidianID.h"
#include "EStandingLevel.h"
#include "EStandingType.h"
#include "Templates/SubclassOf.h"
#include "GameStateMetadataConditionals.generated.h"

class UAptitude;
class UArmorItem;
class UBrandDataAsset;
class UFactionData;
class UFlaw;
class UGadget;
class UItem;
class UPerk;
class UTrait;
class UTravelRegionData;
class UWeapon;

UCLASS(Blueprintable)
class ARKANSAS_API UGameStateMetadataConditionals : public UConditionalLibrary {
    GENERATED_BODY()
public:
    UGameStateMetadataConditionals();

    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasWeaponEquipped(TSoftClassPtr<UWeapon> Weapon);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasWeaponCategoryEquipped(FGameplayTag CategoryTag);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasTrait(TSubclassOf<UTrait> Trait);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasSkillTagged(ESkill Skill);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasSkillOrPerkPoints();
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasSkill(ESkill Skill, EComparisonOperator Operator, ESkillDifficultyRange DifficultyRange, int32 TierOverride, int32 SkillValueOverride);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasPerk(TSubclassOf<UPerk> Perk);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasMakeshiftArmorerDamageThresholdBonus();
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasItem(TSoftClassPtr<UItem> Item, EComparisonOperator Operator, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasGadgetEquipped(TSoftClassPtr<UGadget> Gadget);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasFlaw(TSubclassOf<UFlaw> Flaw);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasFactionStanding(TSoftClassPtr<UFactionData> Faction, EStandingType StandingType, EStandingLevel StandingLevel, EComparisonOperator Operator);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasFactionRank(TSoftClassPtr<UFactionData> Faction, EComparisonOperator Operator, ERankLevel RankLevel);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasDifficulty(EGameDifficulty Difficulty);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasCompanionUnlocked(ESpecialObsidianID Companion);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasCompanionInParty(ESpecialObsidianID Companion);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasCompanionDismissed(ESpecialObsidianID Companion);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasBonusArmorModSlotFilled(EArmorSlot ArmorSlot);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasBackground(TSubclassOf<UAptitude> Background);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasArmorEquipped(TSoftClassPtr<UArmorItem> ArmorItem);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasAllWeaponSlotsFilled();
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasAllThrowableSlotsFilled();
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasAllInhalerSlotsFilled();
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameHasActiveCompanionAmount(EComparisonOperator Operator, int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static bool LatestSaveGameEquipmentHasBrandSynergy(TSoftObjectPtr<UBrandDataAsset> BrandDataAsset);
    
    UFUNCTION(BlueprintCallable)
    static bool IsQuestTrackedForLatestSave(FGuid QuestID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsQuestCompleteForLatestSave(FGuid QuestID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsQuestActiveForLatestSave(FGuid QuestID);
    
    UFUNCTION(BlueprintCallable)
    static bool IsLatestSaveInRegion(TSoftObjectPtr<UTravelRegionData> TravelRegion);
    
    UFUNCTION(BlueprintCallable)
    static bool IsGlobalVariable(FGuid Variable, EComparisonOperator Operator, int32 Value);
    
    UFUNCTION(BlueprintCallable)
    static bool HasQuestFailedForLatestSave(FGuid QuestID);
    
    UFUNCTION(BlueprintCallable)
    static bool HasLatestSaveGame();
    
};

