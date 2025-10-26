#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <GameplayTagContainer.h>
#include <GameplayTagContainer.h>
#include <EOEIGender.h>
#include <LocString.h>
#include "DisplayInterface.h"
#include "EInteractionType.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "ItemStack.h"
#include "ItemStackDelegateDelegate.h"
#include "MapFloorTrackedActor.h"
#include "OnCorpseForcedDeathExecutedDelegate.h"
#include "Corpse.generated.h"

class AIndianaCharacter;
class UAnimationAsset;
class UAppearanceComponent;
class UCapsuleComponent;
class UCharacterDeathComponent;
class UEquipmentComponent;
class UInteractableComponent;
class UInventoryComponent;
class UItem;
class UObsidianIDComponent;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ACorpse : public AActor, public IDisplayInterface, public IMapFloorTrackedActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStackDelegate OnItemAdded;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemStackDelegate OnItemRemoved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer PreSeveredLimbsContainer;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCorpseForcedDeathExecuted OnCorpseForcedDeathExecuted;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOEIGender Gender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* DeathPose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAppearanceComponent* AppearanceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InventoryComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEquipmentComponent* EquipmentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCharacterDeathComponent* DeathComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USkeletalMeshComponent*> SkeletalMeshComponentsWithCloth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyFrost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FrostCPDIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FrostCPDValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CreatureType;
    
public:
    ACorpse(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnLootGenerated();
    
    UFUNCTION(BlueprintCallable)
    void HandleItemRemoved(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void HandleItemAdded(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
public:
    UFUNCTION(BlueprintCallable)
    void GetItemsOnCorpse(TArray<UItem*>& OutItems);
    
    UFUNCTION(BlueprintCallable)
    FLocString GetInteractName() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<EInteractionType> GetInteractions(const FInteractionDescription& Description) const;
    
    UFUNCTION(BlueprintCallable)
    FGameplayTag GetGameplayTag() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void DisableHighlight();
    
public:
    UFUNCTION(BlueprintCallable)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const;
    

    // Fix for true pure virtual functions not being implemented
};

