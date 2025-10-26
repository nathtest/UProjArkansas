#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include <LocString.h>
#include "ComponentDebugInterface.h"
#include "ECreatureXPType.h"
#include "ESkillDifficultyTier.h"
#include "PerkSubclassArray.h"
#include "RangedStatModifierDescription.h"
#include "ScannerAbility.h"
#include "StreamableHandleWrapper.h"
#include "Templates/SubclassOf.h"
#include "CharacterInfoComponent.generated.h"

class AIndianaCharacter;
class UArmorComponent;
class UCompanionComponent;
class UCompanionManagerComponent;
class UEquipmentComponent;
class UHealthComponent;
class UOwSpeakerInfoComponent;
class UPerk;
class UPerkTree;
class URpgStat;
class URpgStatComponent;
class UScannerFlavorTextData;
class UTeamComponent;
class UTrait;
class UWeapon;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterInfoComponent : public UActorComponent, public IComponentDebugInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureXPType CreatureXPType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkillDifficultyTier DifficultyTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAddToScriptManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FScannerAbility> ScannerAbilities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString ScannerAnalysisString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UScannerFlavorTextData* FlavorTextAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString FlavorTextString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString CombatRoleTextString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRangedStatModifierDescription> RangedLevelStatModifiers;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InherentSkillValues[24];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPerkTree* PerkTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UTrait>> InnateTraits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UPerk>> PostLoadPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelsPerPerk;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThreatValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AIndianaCharacter* CharacterOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URpgStatComponent* StatComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCompanionComponent* CompanionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCompanionManagerComponent* CompanionManagerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UEquipmentComponent* EquipmentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTeamComponent* TeamComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UHealthComponent* HealthComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UArmorComponent* ArmorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UOwSpeakerInfoComponent* SpeakerInfoComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FPerkSubclassArray> Perks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FPerkSubclassArray> PerkTransactions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UTrait>> Traits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UPerk>, FStreamableHandleWrapper> PerkStreamHandleMap;
    
public:
    UCharacterInfoComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Exec)
    void UnlockPerksWithRandomLevels_Debug();
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetLevel(int32 NewLevel);
    
    UFUNCTION(BlueprintCallable)
    static void RemovePerkFromActor(AIndianaCharacter* Character, const TSubclassOf<UPerk> Perk);
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void PerkRemove(const FString& PerkName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkPurchase(const FString& PerkName);
    
    UFUNCTION(BlueprintCallable, Exec)
    void PerkPointsAdd(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponEndUnequip(UEquipmentComponent* InEquipmentComponent, UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponEndEquip(UEquipmentComponent* InEquipmentComponent, UWeapon* Weapon);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnStatUpdated(URpgStatComponent* InStatComponent, const URpgStat* Stat);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsALeader() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsABoss() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasPerk(TSoftClassPtr<UPerk> Perk, bool bWithTransaction) const;
    
    UFUNCTION(BlueprintCallable)
    static void GiveTraitToActor(AIndianaCharacter* Character, const TSubclassOf<UTrait> Trait);
    
    UFUNCTION(BlueprintCallable)
    static void GivePerkToActor(AIndianaCharacter* Character, const TSubclassOf<UPerk> Perk);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetThreatValue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetLevelScaledByWorld() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetLevelScaledAtLocation(const FVector& Location) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECreatureXPType GetCreatureXPType() const;
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void AddTraitDebug(const FString& TraitName);
    

    // Fix for true pure virtual functions not being implemented
};

