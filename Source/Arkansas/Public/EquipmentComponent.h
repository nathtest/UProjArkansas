#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include <GameplayTagContainer.h>
#include "AccessoryItemDefinition.h"
#include "ArmorSetItemDefinition.h"
#include "CompanionItemDefinition.h"
#include "ComponentDebugInterface.h"
#include "EArmorModSlot.h"
#include "EArmorSlot.h"
#include "EModSlot.h"
#include "EThrowableTrajectoryAdjustMode.h"
#include "EUnlockAbility.h"
#include "EquipmentWeaponEventDelegate.h"
#include "HelmetItemDefinition.h"
#include "ItemStack.h"
#include "MedKitConsumableSlot.h"
#include "MedKitUsedDelegate.h"
#include "OnGadgetActiveChangeDelegate.h"
#include "OnGadgetDeactivateVisualsDelegate.h"
#include "Templates/SubclassOf.h"
#include "UndersuitItemDefinition.h"
#include "WeaponAttackDelegate.h"
#include "WeaponEndEquipDelegate.h"
#include "WeaponEndReloadDelegate.h"
#include "WeaponEndUnequipDelegate.h"
#include "WeaponEndUnholsterDelegate.h"
#include "WeaponItemDefinition.h"
#include "WeaponSlot.h"
#include "WeaponStartEquipDelegate.h"
#include "WeaponStartFineAimDelegate.h"
#include "WeaponStartHolsterDelegate.h"
#include "WeaponStartReloadDelegate.h"
#include "WeaponStartUnequipDelegate.h"
#include "WeaponStartUnholsterDelegate.h"
#include "WeaponStopFineAimDelegate.h"
#include "EquipmentComponent.generated.h"

class UAccessory;
class UArmorItem;
class UArmorModItem;
class UArmorSet;
class UConsumableItem;
class UGadget;
class UHelmet;
class UInventoryComponent;
class UItem;
class UOwConversationInstance;
class UThrowable;
class UWeapon;
class UWeaponMod;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEquipmentComponent : public UActorComponent, public IComponentDebugInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponStartEquip WeaponStartEquipDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponEndEquip WeaponEndEquipDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponStartUnequip WeaponStartUnequipDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponEndUnequip WeaponEndUnequipDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponStartReload WeaponStartReloadDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponEndReload WeaponEndReloadDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponStartHolster WeaponStartHolsterDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponStartUnholster WeaponStartUnholsterDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponEndUnholster WeaponEndUnholsterDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipmentWeaponEvent WeaponHolsterInstantDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipmentWeaponEvent WeaponUnholsterInstantDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponAttack WeaponAttackDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponStartFineAim WeaponStartFineAimDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponStopFineAim WeaponStopFineAimDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WeaponAttachSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WeaponAttachSocketFPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponItemDefinition DefaultEquippedWeaponItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeapon* PendingWeaponToEquip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeapon* EquippedWeapon;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponSlot WeaponSlots[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FArmorSetItemDefinition DefaultArmorSetItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHelmetItemDefinition DefaultHelmetItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUndersuitItemDefinition DefaultUndersuitItem;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAccessoryItemDefinition DefaultAccessory[8];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompanionItemDefinition DefaultCompanionItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoSlotEquipment;
    
    UPROPERTY(EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UArmorItem* NewArmorSlots[12];
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMedKitUsed OnMedKitUsedDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMedKitConsumableSlot> MedKitConsumableSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UConsumableItem> DefaultMedKitConsumable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UConsumableItem> FirstMedKitSlotConsumable;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGadgetActiveChange OnGadgetActivate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGadgetActiveChange OnGadgetDeactivate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGadgetDeactivateVisuals OnGadgetDeactivateVisuals;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGadget*> GadgetSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGadget*> PassiveGadgets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UGadget* EquippedGadget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UGadget* PendingGadgetToEquip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EThrowableTrajectoryAdjustMode ThrowableTrajectoryAdjustModeFPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UThrowable*> ThrowableSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UThrowable* EquippedThrowable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UThrowable* OverrideThrowable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UThrowable* CurrentThrowable;
    
public:
    UEquipmentComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Exec)
    void WeaponAdvanceLevelDebug(int32 NumLevels, bool bIgnoreCost);
    
    UFUNCTION(BlueprintCallable, Exec)
    void UnlockWeaponSlotsDebug(int32 NumSlots);
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void UnequipAllModsDebug();
    
public:
    UFUNCTION(BlueprintCallable)
    void ToggleGadgetActivation();
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void SlotWeaponDebug(FName WeaponName);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void SetWeaponLevel(int32 Level, bool bOverrideWeaponLevels);
    
    UFUNCTION(BlueprintCallable)
    void SetSkipDetachOnUnequip(bool bSkip);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetCalledShotWeaponLevel(int32 Level);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetArmorLevel(int32 Level, bool bOverrideArmorLevels);
    
    UFUNCTION(BlueprintCallable)
    void RemoveWeapon_BP(TSubclassOf<UWeapon> WeaponClass);
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void RemoveConsumableAmmoDebug();
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveArmor_BP(EArmorSlot ArmorSlot);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnUnlockAbilityChanged(EUnlockAbility Ability);
    
    UFUNCTION(BlueprintCallable)
    void OnUnholsterWeaponInstant(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnStopFineAim(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnStopClimb();
    
    UFUNCTION(BlueprintCallable)
    void OnStartUnholsterWeapon(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnStartUnequipWeapon(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnStartReloadWeapon(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnStartHolsterWeapon(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnStartFineAim(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnStartEquipWeapon(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnStartClimb();
    
    UFUNCTION(BlueprintCallable)
    void OnMedKitUsed(bool bDoubleDose);
    
    UFUNCTION(BlueprintCallable)
    void OnItemRemovedFromInventory(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void OnItemCountChangedInInventory(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void OnItemAddedToInventory(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void OnHolsterWeaponInstant(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEndUnholsterWeapon(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEndUnequipWeapon(UWeapon* Weapon);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnEndUnequipGadget(UGadget* Gadget);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnEndTacticalReloadWeapon(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEndReloadWeapon(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEndHolsterWeapon(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEndEquipWeapon(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnEndEmptyReloadWeapon(UWeapon* Weapon);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnConversationStarted(UOwConversationInstance* ConversationInstance);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCancelReloadWeapon(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LoadConsumableAsAmmoDebug(FName ConsumableName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void LoadAmmoDebug(FName AmmoName);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsingNRayScanner();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsItemInAnySlot(TSubclassOf<UItem> Item) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGadgetActivated() const;
    
    UFUNCTION(BlueprintCallable)
    void InitializeDestructibleBodyParts(bool bFromDelegate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEquippedAccessory(TSubclassOf<UAccessory> TargetAccessory) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxNumberOfAccessories() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UWeapon* GetEquippedWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UHelmet* GetEquippedHelmet() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UArmorSet* GetEquippedArmor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAccessory* GetEquippedAccessory(int32 Slot) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UAccessory*> GetAllAccessoriesCoveringRegion(FGameplayTag AccessoryRegion) const;
    
    UFUNCTION(BlueprintCallable)
    void EquipWeaponModByClassDebug(EModSlot ModSlot, TSubclassOf<UWeaponMod> WeaponMod, bool bIgnoreSlotModdability);
    
    UFUNCTION(BlueprintCallable)
    void EquipWeaponFromSlotDebugOnly(int32 SlotIndex, bool bInstantEquip, bool bStartingCombat);
    
    UFUNCTION(Exec)
    void EquipWeaponFromSlot(uint32 SlotIndex, bool bInstantEquip, bool bStartingCombat);
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void EquipWeaponDebug(FName WeaponName);
    
public:
    UFUNCTION(BlueprintCallable)
    void EquipWeaponBP(TSubclassOf<UWeapon> Weapon);
    
    UFUNCTION(BlueprintCallable)
    void EquipWeapon_BP(TSubclassOf<UWeapon> WeaponClass, int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable, Exec)
    void EquipPreviousWeapon();
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void EquipModDebug(FName ModName);
    
public:
    UFUNCTION(BlueprintCallable)
    void EquipGadgetByClass(TSubclassOf<UGadget> GadgetClass);
    
    UFUNCTION(BlueprintCallable)
    void EquipArmorModByClassDebug(EArmorModSlot ArmorModSlot, TSubclassOf<UArmorModItem> ArmorModItem);
    
    UFUNCTION(BlueprintCallable, Exec)
    void EquipArmorDebug(FName ArmorName);
    
    UFUNCTION(BlueprintCallable)
    void EquipArmorByClassDebug(EArmorSlot ArmorSlot, TSubclassOf<UArmorItem> ArmorItem);
    
    UFUNCTION(BlueprintCallable)
    void EquipArmor_BP(EArmorSlot ArmorSlot, TSubclassOf<UArmorItem> ArmorItem);
    
protected:
    UFUNCTION(BlueprintCallable)
    void AutoFillWeaponSlots();
    
public:
    UFUNCTION(BlueprintCallable)
    void AddMedKitCharges(float ChargesToAdd);
    

    // Fix for true pure virtual functions not being implemented
};

