#pragma once
#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include <GameplayTagContainer.h>
#include "ESSTargetType.h"
#include "EStateOfBeing.h"
#include "EWeaponState.h"
#include "Templates/SubclassOf.h"
#include "CharacterBlueprintFunctionLibrary.generated.h"

class AActor;
class AIndianaCharacter;
class AIndianaPlayerCharacter;
class UThrowable;
class UWeapon;

UCLASS(Blueprintable)
class UCharacterBlueprintFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UCharacterBlueprintFunctionLibrary();

    UFUNCTION(BlueprintCallable)
    static bool UnequipThrowable(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool IsWeaponWithTagEquipped(AIndianaCharacter* Character, const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    static bool IsUnlimiedRangedWeaponEquipped(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool IsRangedWeaponEquipped(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPotentialPlayerScreenSpaceTarget(AIndianaPlayerCharacter* Character, AActor* Target, const bool bRequireLOS, const ESSTargetType TargetType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPlayerScreenSpaceTarget(AIndianaPlayerCharacter* Character, AActor* Target, const ESSTargetType TargetType, float MinActiveTime);
    
    UFUNCTION(BlueprintCallable)
    static bool IsMeleeWeaponEquipped(AIndianaCharacter* Character, const bool bIncludeUnwarmedWeapon);
    
    UFUNCTION(BlueprintCallable)
    static bool IsLimitedRangedWeaponEquipped(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool IsCalledShotWeaponEquipped(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool HasWeaponWithTagInEquipment(AIndianaCharacter* Character, const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    static bool HasUnlimitedRangedWeaponInEquipment(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool HasThrowableVarietyInInventory(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool HasThrowableInInventory(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool HasRangedWeaponWithTagInEquipment(AIndianaCharacter* Character, const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    static bool HasRangedWeaponInEquipment(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasOffensiveThrowableInInventory(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool HasMultipleSlottedGadgets(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool HasMeleeWeaponWithTagInEquipment(AIndianaCharacter* Character, const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    static bool HasMeleeWeaponInEquipment(AIndianaCharacter* Character, const bool bIncludeUnwarmedWeapon);
    
    UFUNCTION(BlueprintCallable)
    static bool HasLimitedRangedWeaponInEquipment(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool HasEquippedThrowable(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasDefensiveThrowableInInventory(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool HasCalledShotWeaponInEquipment(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static UWeapon* GetWeaponWithTagFromEquipment(AIndianaCharacter* Character, const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetWeaponWithTagEquipmentSlotIndex(AIndianaCharacter* Character, const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetWeaponReactsToState(UWeapon* Weapon, const EWeaponState WeaponState);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetWeaponInstanceEquipmentSlotIndex(AIndianaCharacter* Character, const UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    static UWeapon* GetUnlimitedRangedWeaponFromEquipment(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetUnlimitedRangedWeaponEquipmentSlotIndex(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TEnumAsByte<ETeamAttitude::Type> GetTeamAttitudeTowards(AIndianaCharacter* Character, AActor* Other);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EStateOfBeing GetStateOfBeing(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static UWeapon* GetRangedWeaponWithTagFromEquipment(AIndianaCharacter* Character, const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetRangedWeaponWithTagEquipmentSlotIndex(AIndianaCharacter* Character, const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    static UWeapon* GetRangedWeaponFromEquipment(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetRangedWeaponEquipmentSlotIndex(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector2D GetPlayerScreenSpaceTargetScreenPosition(bool& bIsValid, AIndianaPlayerCharacter* Character, AActor* Target, const ESSTargetType TargetType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetPlayerScreenSpaceTargetScore(bool& bIsValid, AIndianaPlayerCharacter* Character, AActor* Target, const ESSTargetType TargetType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetPlayerScreenSpaceTargetNormalizedDistance(bool& bIsValid, AIndianaPlayerCharacter* Character, AActor* Target, const ESSTargetType TargetType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetPlayerScreenSpaceTargetLineOfSightTime(bool& bIsValid, AIndianaPlayerCharacter* Character, AActor* Target, const ESSTargetType TargetType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetPlayerScreenSpaceTargetLineOfSight(bool& bIsValid, AIndianaPlayerCharacter* Character, AActor* Target, const ESSTargetType TargetType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetPlayerScreenSpaceTargetDistance(bool& bIsValid, AIndianaPlayerCharacter* Character, AActor* Target, const ESSTargetType TargetType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetPlayerScreenSpaceTargetActiveTime(bool& bIsValid, AIndianaPlayerCharacter* Character, const ESSTargetType TargetType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AActor* GetPlayerScreenSpaceTarget(AIndianaPlayerCharacter* Character, const ESSTargetType TargetType);
    
    UFUNCTION(BlueprintCallable)
    static UWeapon* GetMeleeWeaponWithTagFromEquipment(AIndianaCharacter* Character, const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetMeleeWeaponWithTagEquipmentSlotIndex(AIndianaCharacter* Character, const FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    static UWeapon* GetMeleeWeaponFromEquipment(AIndianaCharacter* Character, const bool bIncludeUnwarmedWeapon);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetMeleeWeaponEquipmentSlotIndex(AIndianaCharacter* Character, const bool bIncludeUnwarmedWeapon);
    
    UFUNCTION(BlueprintCallable)
    static UWeapon* GetLimitedRangedWeaponFromEquipment(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetLimitedRangedWeaponEquipmentSlotIndex(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetEquippedWeaponIndex(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static UWeapon* GetEquippedWeapon(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetEquippedThrowableIndex(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static UThrowable* GetEquippedThrowable(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetCharacterScreenHorizontalRelativeness(AIndianaCharacter* Character, bool& bOnScreen);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetCharacterScreenCenterness(AIndianaCharacter* Character, bool& bOnScreen);
    
    UFUNCTION(BlueprintCallable)
    static UWeapon* GetCalledShotWeaponFromEquipment(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCalledShotWeaponEquipmentSlotIndex(AIndianaCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static bool EquipThrowableByIndex(AIndianaCharacter* Character, const int32 Index);
    
    UFUNCTION(BlueprintCallable)
    static bool EquipThrowableByClass(AIndianaCharacter* Character, const TSubclassOf<UThrowable> Class);
    
    UFUNCTION(BlueprintCallable)
    static bool EquipThrowable(AIndianaCharacter* Character);
    
};

