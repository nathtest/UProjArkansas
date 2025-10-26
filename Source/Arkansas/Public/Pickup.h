#pragma once
#include "CoreMinimal.h"
#include "DefaultItemStack.h"
#include "ItemStack.h"
#include "ItemVisualizer.h"
#include "MapFloorTrackedActor.h"
#include "OnPickupDelegate.h"
#include "OwnableInterface.h"
#include "Templates/SubclassOf.h"
#include "Pickup.generated.h"

class AActor;
class UFactionData;
class UInteractableComponent;
class UItem;
class UObsidianIDComponent;
class UPrimitiveComponent;
class UStaticLootList;

UCLASS(Blueprintable, MinimalAPI)
class APickup : public AItemVisualizer, public IMapFloorTrackedActor, public IOwnableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPickup OnPickup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeshLoadDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MeshUnloadDistance;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDefaultItemStack DefaultItemStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDefaultItemStack CachedItemStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticLootList* LootList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItem* LootListItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
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
    bool bAddItemToInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsOneOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsChildActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowDebugBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLeaveOriginal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowEasyApply;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyAllowEasyApply;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LootSeed;
    
public:
    APickup(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;

protected:
    UFUNCTION(BlueprintCallable)
    void ShutdownDropPhysics(bool bUpdateTransforms);
    
    UFUNCTION(BlueprintCallable)
    void SetupDropPhysics();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetSeedFromActor(AActor* SeedActor);
    
    UFUNCTION(BlueprintCallable)
    void RegenerateSeed();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPhysicsWake(UPrimitiveComponent* WakingComponent, FName BoneName);
    
    UFUNCTION(BlueprintCallable)
    void OnPhysicsSleep(UPrimitiveComponent* SleepingComponent, FName BoneName);
    
public:
    UFUNCTION(BlueprintCallable)
    void LockLootListItem();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FItemStack GetItemStack() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UItem* GetItem() const;
    
    UFUNCTION(BlueprintCallable)
    void ClearOwnership();
    

    // Fix for true pure virtual functions not being implemented
};

