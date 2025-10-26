#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <GameplayTagContainer.h>
#include <GameplayTagContainer.h>
#include <LocString.h>
#include "ContainerOpenedDelegate.h"
#include "DefaultItemStack.h"
#include "DisplayInterface.h"
#include "EInteractionType.h"
#include "ESkillDifficultyTier.h"
#include "InteractionDescription.h"
#include "ItemStack.h"
#include "ItemStackDelegateDelegate.h"
#include "MapFloorTrackedActor.h"
#include "OCLBarredDelegate.h"
#include "OCLCloseEndDelegate.h"
#include "OCLCloseStartDelegate.h"
#include "OCLLockedDelegate.h"
#include "OCLLockpickInterruptedDelegate.h"
#include "OCLLockpickLoopStopDelegate.h"
#include "OCLLockpickStartDelegate.h"
#include "OCLLockpickSuccessDelegate.h"
#include "OCLOpenAttemptedLockedDelegate.h"
#include "OCLOpenEndDelegate.h"
#include "OCLOpenStartDelegate.h"
#include "OCLUnbarredDelegate.h"
#include "OCLUnlockedDelegate.h"
#include "OwnableInterface.h"
#include "RPGInteractableRequirements.h"
#include "Container.generated.h"

class UBranchingLootList;
class UInteractableComponent;
class UInventoryComponent;
class UItem;
class UOCLComponent;
class UObsidianIDComponent;
class USceneComponent;

UCLASS(Blueprintable)
class ARKANSAS_API AContainer : public AActor, public IDisplayInterface, public IMapFloorTrackedActor, public IOwnableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLOpenStart OnOCLOpenStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLOpenEnd OnOCLOpenEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLCloseStart OnOCLCloseStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLCloseEnd OnOCLCloseEnd;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLOpenAttemptedLocked OnOCLOpenAttemptedLocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLOpenAttemptedLocked OnOCLOpenAttemptedBarred;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLLocked OnOCLLocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLUnlocked OnOCLUnlocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLBarred OnOCLBarred;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLUnbarred OnOCLUnbarred;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLLockpickStart OnOCLLockpickStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLLockpickSuccess OnOCLLockpickSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLLockpickInterrupted OnOCLLockpickInterrupted;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOCLLockpickLoopStop OnOCLLockpickLoopStop;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStackDelegate OnItemAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStackDelegate OnItemRemoved;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FContainerOpened OnPlayerOpenedContainer;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOCLComponent* OCLComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InventoryComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GameplayTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLootManagerLootApplied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDefaultItemStack> LootManagerItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBranchingLootList* LootManagerLootList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkillDifficultyTier LootManagerTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer LootManagerItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer LootManagerBrand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LootManagerListEntriesToApply;
    
public:
    AContainer(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;

protected:
    UFUNCTION(BlueprintCallable)
    bool PassesRPGRequirements(uint8 InteractionIndex);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnInteractionTargetChanged(const FInteractionDescription& Description);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnContainerInteractableTargeted();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLightEnabled() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleItemRemoved(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void HandleItemAdded(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    FRPGInteractableRequirements GetRPGRequirements(EInteractionType InteractionType);
    
public:
    UFUNCTION(BlueprintCallable)
    void GetItemsInContainer(TArray<UItem*>& OutItems);
    
    UFUNCTION(BlueprintCallable)
    FLocString GetInteractName() const;
    
    UFUNCTION(BlueprintCallable)
    float GetInteractHoldTime(const FInteractionDescription& InteractionDescription);
    
    UFUNCTION(BlueprintCallable)
    FGameplayTag GetGameplayTag() const;
    

    // Fix for true pure virtual functions not being implemented
};

