#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include <GameplayTagContainer.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICommon -ObjectName=EBoolResult -FallbackName=EBoolResult
#include "ComponentDebugInterface.h"
#include "DefaultItemStack.h"
#include "EItemRarity.h"
#include "EUnlockAbility.h"
#include "ItemStack.h"
#include "ItemStackCountChangedDelegateDelegate.h"
#include "ItemStackDelegateDelegate.h"
#include "OnLootGeneratedDelegate.h"
#include "RelevanceOptimizationInterface.h"
#include "Templates/SubclassOf.h"
#include "InventoryComponent.generated.h"

class AActor;
class UAkAudioEvent;
class UFactionData;
class UItem;
class UStaticLootList;

UCLASS(Blueprintable, MinimalAPI, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UInventoryComponent : public UActorComponent, public IComponentDebugInterface, public IRelevanceOptimizationInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStackDelegate ItemAddedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStackDelegate ItemCountChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStackDelegate ItemRemovedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStackDelegate ItemJunkStatusChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStackCountChangedDelegate ItemStackCountChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLootGenerated OnLootGeneratedDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDefaultItemStack> DefaultItemStacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemStack> Items;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticLootList* BaseLootTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticLootList* SecondaryTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UStaticLootList*> AdditionalLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsOneOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideNonPlayerOwnership;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverridePlayerOwnership;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFactionData> OwningFaction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<AActor> OwningActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayerOwned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseContainerTagForMedKit;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EItemRarity, UAkAudioEvent*> ItemRarityAudioEvents;
    
public:
    UInventoryComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static bool TransferItemsBetweenActorsByTag(AActor* SourceActor, AActor* DestinationActor, FGameplayTagContainer MatchTags, int32 Count, bool bPotentialTheft);
    
    UFUNCTION(BlueprintCallable)
    static void ShowItemRemovedNotification(TSubclassOf<UItem> ItemType, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static void ShowItemGainedNotification(TSubclassOf<UItem> ItemType, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveItemsFromActorByTag(AActor* Actor, FGameplayTagContainer MatchTags, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveItemFromPlayer(TSubclassOf<UItem> ItemType, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveItemFromActor(AActor* Actor, TSubclassOf<UItem> ItemType, int32 Count);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RemoveCurrency(int32 Amount);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnUnlockedAbilityAdded(EUnlockAbility Ability);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEmpty() const;
    
    UFUNCTION(BlueprintCallable)
    static bool HasItemCountOnActorByTag(AActor* Actor, FGameplayTagContainer MatchTags, EBoolResult& OutResult, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static bool HasItemCountOnActorBP(AActor* Actor, TSubclassOf<UItem> ItemType, EBoolResult& OutResult, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static void GiveLootToPlayer(UStaticLootList* StaticLootList);
    
    UFUNCTION(BlueprintCallable)
    static void GiveLootToActor(AActor* Actor, UStaticLootList* StaticLootList);
    
    UFUNCTION(BlueprintCallable)
    static void GiveItemToPlayer(TSubclassOf<UItem> ItemType, int32 Count, bool bShowNotification, bool bPlayItemPickupAudio);
    
    UFUNCTION(BlueprintCallable)
    static void GiveItemToActor(AActor* Actor, TSubclassOf<UItem> ItemType, int32 Count, bool bLootable);
    
    UFUNCTION(BlueprintCallable)
    static void GiveCurrency(AActor* Actor, int32 Count);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetItemCountOnActor(AActor* Actor, TSubclassOf<UItem> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ContainsLoot() const;
    
protected:
    UFUNCTION(Exec)
    void AddItemDebug(const FName& ItemName, uint32 Count);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void AddCurrency(int32 Amount, bool bLootable);
    

    // Fix for true pure virtual functions not being implemented
};

