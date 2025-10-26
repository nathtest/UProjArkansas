#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RuntimeFloatCurve -FallbackName=RuntimeFloatCurve
#include <GameplayTagContainer.h>
#include <GameplayTagContainer.h>
#include "CalledShotEndedDelegate.h"
#include "CalledShotStartedDelegate.h"
#include "CauseDamageInfo.h"
#include "DegradableItem.h"
#include "EAnimNotify.h"
#include "EGripStyle.h"
#include "EItemTier.h"
#include "EMeleeImpactType.h"
#include "ERangedWeaponAccuracy.h"
#include "ESkill.h"
#include "EThirdPersonSocket.h"
#include "EndEquipDelegate.h"
#include "EndHolsterDelegate.h"
#include "EndReloadDelegate.h"
#include "EndUnequipDelegate.h"
#include "EndUnholsterDelegate.h"
#include "ModMatchSoundEffectsData.h"
#include "OnHitStatusEffects.h"
#include "QuickMeleeAttemptedDelegate.h"
#include "RpgStatCollection.h"
#include "SpellSet.h"
#include "StartEquipDelegate.h"
#include "StartHolsterDelegate.h"
#include "StartReloadDelegate.h"
#include "StartUnequipDelegate.h"
#include "StartUnholsterDelegate.h"
#include "StatModifierDescription.h"
#include "TryReloadDelegate.h"
#include "UnspecifiedPickupTransform.h"
#include "WeaponEventDelegate.h"
#include "WeaponSettingsUpdatedDelegate.h"
#include "Weapon.generated.h"

class AIndianaAiCharacter;
class AIndianaCharacter;
class UAISettings_Weapon;
class UAkAudioEvent;
class UAmmoPoolBase;
class UAssetCollection;
class UBodyLocationSpellAsset;
class UCharacterInfoComponent;
class UMaterialInterface;
class UPreviewWeaponAnimations;
class UPrimaryWeaponVisuals;
class URpgStatComponent;
class USharedWeaponVisuals;
class USightData;
class USkeletalMesh;
class USkeletalMeshComponent;
class USpell;
class UStaticMeshModVisual;
class UTacticalTimeDilationComponent;
class UWeaponAnimInstance;
class UWeaponAnimations;
class UWeaponAnimationsCreature;
class UWeaponAnimationsFPV;
class UWeaponAudio;
class UWeaponCameraSwayData;
class UWeaponClippingCheckConfig;
class UWeaponModContainer;
class UWeaponMode;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UWeapon : public UDegradableItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStartEquip StartEquipDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEndEquip EndEquipDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStartUnequip StartUnequipDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEndUnequip EndUnequipDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStartReload StartReloadDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEndReload EndReloadDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTryReload TryReloadDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStartHolster StartHolsterDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEndHolster EndHolsterDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStartUnholster StartUnholsterDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEndUnholster EndUnholsterDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponEvent HolsterInstantDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponEvent UnholsterInstantDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCalledShotStarted CalledShotStartedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCalledShotEnded CalledShotEndedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponSettingsUpdated WeaponSettingsUpdatedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FUnspecifiedPickupTransform> UnspecifiedPickupTransformForMods;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RecacheStealthDamageMinDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* TPVWeaponMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* TPVAttachMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* FPVWeaponMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* FPVAttachMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    URpgStatComponent* StatComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCharacterInfoComponent* CharacterInfoComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTacticalTimeDilationComponent* TTDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTacticalTimeDilationComponent> PlayerTTDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreMovementRestrictionPerks;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 AllowedMovementActions;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ReloadAllowedMovementActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActiveSpeedMoveMult_HipFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActiveSpeedMoveMult_ADS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActiveSpeedMoveMult_Sprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActiveSpeedReturnDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadSpeedMoveMult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadSprintSpeedMoveMult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ADSBobStrengthMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ADSBobPlayRateMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeaponMode* PrimaryMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreSecondaryModeInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeaponMode* SecondaryMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SprintToFireTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SprintFireHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SprintFireRelaxTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoresAmmoConsumption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsGadgetWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAmmoPoolBase* AmmoPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve JumpLandingCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeaponModContainer* WeaponModContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBodyLocationSpellAsset* WeaponLocationSpellAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWeaponCameraSwayData* CameraSwayData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> WeaponMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshModVisual*> DefaultMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshModVisual*> DupedDefaulMeshMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, TSoftObjectPtr<UMaterialInterface>> MaterialOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UWeaponAnimInstance> WeaponAnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EquipTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UnequipTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitMarkerVisibilityTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float KillMarkerVisibilityTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UPrimaryWeaponVisuals> FPVVisualsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UPrimaryWeaponVisuals> TPVVisualsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<USharedWeaponVisuals> SharedVisualsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UWeaponAnimationsFPV> FPAnimationsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UWeaponAnimationsCreature> CreatureTPAnimationsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UWeaponAnimationsCreature> PlayerTPAnimationsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UWeaponAudio> SoundEffectsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UWeaponAudio> TPSoundEffectsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UWeaponAudio> CompanionSoundEffectsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FModMatchSoundEffectsData> ModdedSoundEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableAutoFootsteps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UPreviewWeaponAnimations> PreviewAnimationsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRpgStatCollection RpgStatCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStatModifierDescription> WeaponStatModifiers;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkill Skill;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkill SkillSecondary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpulseOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ArmorPenetration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERangedWeaponAccuracy RangedWeaponAccuracy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag WeaponCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag WeaponCategoryQuickMelee;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreventQuickMelee;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreventQuickMeleeWhileFullyAimed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuickMeleeAttempted QuickMeleeAttempted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAISettings_Weapon* AISettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAISettings_Weapon* AlternateAISettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAssetCollection* AssetCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOnHitStatusEffects> OnHitStatusEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpellSet WeaponSpellSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DamageTypeStacksPerShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MinSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MinAttribute;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeakSpotMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<USpell> OnHitSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnHitSpellChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequireDirectHitForHitSpell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldAdsInterruptFireAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileWizzRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* ProjectileWizzEventOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanGenerateLootOnBreakdown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EItemTier Tier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMeleeImpactType MeleeImpactType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGripStyle GripStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseWeaponOutEquipWhenSwitching;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimaryWeaponVisuals* TPVCurrentVisuals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimaryWeaponVisuals* FPVCurrentVisuals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeaponAnimations* ThirdPersonAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeaponAnimations* FirstPersonAnimations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MetaTags;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeaponAudio* CurrentlyLinkedWeaponAudio;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnFromMuzzle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnFromMuzzlePosOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnFromMuzzlePosOnly2;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasIronSights;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSupportsDetachOnNextAnimNotifyAttachHack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWeaponClippingCheckConfig> ClipCheckConfig;
    
public:
    UWeapon();

    UFUNCTION(BlueprintCallable)
    void StartCalledShotMode(AIndianaCharacter* InCalledShotTarget, EThirdPersonSocket InPreferredCalledShotTargetSocket, float InCalledShotDamageScalar);
    
    UFUNCTION(BlueprintCallable)
    void SetSight(const TSoftObjectPtr<USightData>& NewSightData);
    
    UFUNCTION(BlueprintCallable)
    void SetSaveGameFloat(const FName& InVariableName, float InValue);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnequipBP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTryQuickMelee();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReloadBP();
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerStoppedSprinting();
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerStartedSprinting();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEquipBP();
    
    UFUNCTION(BlueprintCallable)
    void OnAnimNotifyEvent(EAnimNotify AnimNotifyEvent, FName OptionalSocket);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool NeedsReload() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUnequipping() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTwoHanded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReloading() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRechambering() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPrimaryTriggerActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOneHanded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHolstered() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFullyAimed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEquipping() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEmptyAndNeedsReload() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleDamageResponseBP(const FCauseDamageInfo& CauseDamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UWeaponModContainer* GetWeaponModContainer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USkeletalMeshComponent* GetTPVMeshComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URpgStatComponent* GetStats() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UWeaponMode* GetSecondaryMode() const;
    
    UFUNCTION(BlueprintCallable)
    float GetSaveGameFloat(const FName& InVariableName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRadialDamageOuterRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetProjectileCollisionRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UWeaponMode* GetPrioritizedSightMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UWeaponMode* GetPrimaryMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AIndianaCharacter* GetOwnerCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIgnoresAmmoConsumption() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USkeletalMeshComponent* GetFPVMeshComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPrimaryWeaponVisuals* GetCurrentVisuals() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UWeaponMode* GetCurrentMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentAmmoCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCharacterInfoComponent* GetCharacterInfoComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBuildUpRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAmmoPoolBase* GetAmmoPool() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAISettings_Weapon* GetAISettings(AIndianaAiCharacter* InOwner) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USkeletalMeshComponent* GetActiveMeshComponent() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void FinishDetachOnNextAnimNotifyAttachHack();
    
public:
    UFUNCTION(BlueprintCallable)
    void EndSecondaryTrigger(bool bForceEnd);
    
    UFUNCTION(BlueprintCallable)
    bool EndPrimaryTrigger(bool bForceEnd);
    
    UFUNCTION(BlueprintCallable)
    void EndCalledShotMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanQuickMelee() const;
    
    UFUNCTION(BlueprintCallable)
    void BeginSecondaryTrigger();
    
    UFUNCTION(BlueprintCallable)
    bool BeginPrimaryTrigger();
    
};

