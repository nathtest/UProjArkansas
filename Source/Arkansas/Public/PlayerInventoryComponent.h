#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <QuestReference.h>
#include <GlobalVariableReference.h>
#include "CharacterInventoryComponent.h"
#include "LootOnBreakdown.h"
#include "OnCraftOrBuyAmmoDelegate.h"
#include "Templates/SubclassOf.h"
#include "PlayerInventoryComponent.generated.h"

class AIndianaAiCharacter;
class UAkAudioEvent;
class UCharacterInfoComponent;
class UCraftingRecipe;
class UItem;
class URpgStat;
class URpgStatComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerInventoryComponent : public UCharacterInventoryComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCraftOrBuyAmmo OnCraftOrBuyAmmo;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLootOnBreakdown> LootOnWeaponBreakdown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLootOnBreakdown> LootOnArmorBreakdown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseCarryingCapacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URpgStat* LootOnBreakdownChanceStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URpgStat* ModFinderFieldRepairStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URpgStat* ScavengeMaxItemLevelStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AutoBreakDownTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference CraftOrBuyAmmoGlobalVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestReference CraftOrBuyAmmoQuest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* EvilMoonManAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSubclassOf<UCraftingRecipe>> KnownRecipes;
    
public:
    UPlayerInventoryComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, Exec)
    void VendorRepairItemDebug(const FName& ItemName);
    
public:
    UFUNCTION(BlueprintCallable)
    void UnlearnRecipe(TSubclassOf<UCraftingRecipe> Recipe);
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void SetWeaponHealthDebug(float Percent);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetItemHealthDebug(const FName& ItemName, float Percent);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetHelmetHealthDebug(float Percent);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetArmorHealthDebug(float Percent);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RepairItemDebug(const FName& ItemName, bool bFieldRepair);
    
    UFUNCTION(BlueprintCallable)
    void OnStatUpdated(URpgStatComponent* InStatComponent, const URpgStat* Stat);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerLevelChanged(UCharacterInfoComponent* InCharacterInfoComponent, int32 PlayerLevel);
    
    UFUNCTION(BlueprintCallable)
    void OnCompanionRegistered(AIndianaAiCharacter* Character, bool bAdded);
    
public:
    UFUNCTION(BlueprintCallable)
    void LearnRecipe(TSubclassOf<UCraftingRecipe> Recipe);
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void IgnoreEncumbrance(bool bIgnored);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasPlayerCompletedMostCards() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasPlayerCompletedAllCards() const;
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void GiveTools();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumOfCollectedCards() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesPlayerKnowRecipe(TSubclassOf<UCraftingRecipe> Recipe) const;
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void CraftingRemoveRecipe(const FName& RecipeName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CraftingRemoveAllRecipes();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CraftingOpenCraftingUI();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CraftingOpenBreakDownUI();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CraftingGiveAllMaterialComponents();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CraftingBreakDownItem(const FName& ItemName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CraftingAddRecipe(const FName& RecipeName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CraftingAddAllRecipes();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool CanPlayerCraftItem(TSubclassOf<UItem> ItemClass) const;
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void BreakDownItemDebug(const FName& ItemName, bool bFieldBreakdown);
    
};

