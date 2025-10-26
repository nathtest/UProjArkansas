#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <EQuestType.h>
#include <GlobalVariableReference.h>
#include "CharacterInfoComponent.h"
#include "ECreatureXPType.h"
#include "EPointOfInterestXPType.h"
#include "ESkill.h"
#include "ESkillDifficultyRange.h"
#include "ESkillDifficultyTier.h"
#include "LevelDifferenceRangeScalar.h"
#include "SkillValueExperienceRange.h"
#include "Templates/SubclassOf.h"
#include "PlayerInfoComponent.generated.h"

class AContainer;
class AIndianaAiCharacter;
class UAptitude;
class UFlaw;
class UInventoryEntitlements;
class UOEIAreaMusicData;
class UPerk;
class UPetData;
class UTrait;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerInfoComponent : public UCharacterInfoComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> PlayerXPTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESkillDifficultyRange, int32> SkillCheckDifficultyXP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSkillValueExperienceRange> SkillCheckValueXP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GenericInteractionXP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ECreatureXPType, int32> CreatueXPTypeMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLevelDifferenceRangeScalar> EnemyXPLevelDiffScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPointOfInterestXPType, int32> PointOfInterestXPMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EQuestType, int32> QuestTypeXPMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float QuestXPPercentFromObjectives;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumSkillsPointsPerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSkillLevelForCategoryPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxSkillLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumSkillLevelsBetweenUpgrades;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PointsForTaggedSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlawOfferCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UFlaw>> FlawTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFlaw> PriorityFlaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFlaw> ConsumerismFlaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFlaw*> FlawPtrs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UFlaw>, int32> LoadedFlawCounts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSubclassOf<UFlaw>> FlawsChosen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSubclassOf<UFlaw>> FlawsRejected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFlaw> PendingOfferFlaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFlaw> QueuedOfferFlaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAptitude> Aptitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTrait> DumbTrait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSubclassOf<UPerk>> TaggedPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSubclassOf<UPetData>> UnlockedPets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPetData> SelectedPet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UPetData>> AllPets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference FirstPetGlobalVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOEIAreaMusicData* AreaMusicData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInventoryEntitlements* InventoryEntitlements;
    
public:
    UPlayerInfoComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UnlockPet(TSubclassOf<UPetData> PetData);
    
    UFUNCTION(BlueprintCallable)
    void UnlockEntitlements();
    
    UFUNCTION(BlueprintCallable, Exec)
    void UnlockAllPets();
    
    UFUNCTION(BlueprintCallable, Exec)
    void TraitRemoveDebug(const FString& TraitName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void TraitAddDebug(const FString& TraitName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleDoubleJump();
    
    UFUNCTION(BlueprintCallable)
    static void SetPlayerSkillDebug(ESkill Skill, int32 SkillValue);
    
    UFUNCTION(BlueprintCallable)
    bool SetFlawAsOfferable(TSubclassOf<UFlaw> Flaw, bool bIgnoreTimer);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetAptitudeDebug(const FString& AptitudeName);
    
    UFUNCTION(BlueprintCallable)
    void SelectPet(TSubclassOf<UPetData> PetData);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RespecSkillPoints();
    
    UFUNCTION(BlueprintCallable, Exec)
    void RespecPerks(bool bNoCost);
    
    UFUNCTION(BlueprintCallable, Exec)
    void ResetFlawOfferTimer();
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerTargetedContainer(AContainer* Container);
    
    UFUNCTION(BlueprintCallable)
    void OnEntitlementAvailabilityChanged(const FGameplayTag& Entitlement, bool bAdded);
    
    UFUNCTION(BlueprintCallable)
    void OnCompanionRegistered(AIndianaAiCharacter* Companion, bool bRegister);
    
    UFUNCTION(BlueprintCallable, Exec)
    void NextPet();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LockAllPets();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTaggedSkill(ESkill Skill) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsPetUnlocked(TSubclassOf<UPetData> PetData);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDumbSkill(ESkill Skill) const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void GiveSkills();
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<UPetData> GetSelectedPet();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ESkillDifficultyTier GetLevelTierEquivalent() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    void FlawOfferRejectDebug();
    
    UFUNCTION(BlueprintCallable, Exec)
    void FlawOfferDebug(const FString& FlawName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void FlawOfferAcceptDebug();
    
    UFUNCTION(BlueprintCallable, Exec)
    void FlawClearOfferDebug();
    
    UFUNCTION(BlueprintCallable, Exec)
    void FlawClearDebug(const FString& FlawName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void FlawAddDebug(const FString& FlawName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DisableFlawOffers();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugUnlockEntitlements();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ClearPet();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddXPDebug(int32 XP);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddTaggedSkillDebug(const FString& Skill);
    
    UFUNCTION(BlueprintCallable)
    void AddFlaw_BP(TSubclassOf<UFlaw> FlawSubclass);
    
};

