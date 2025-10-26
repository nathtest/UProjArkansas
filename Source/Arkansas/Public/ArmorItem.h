#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include <GameplayTagContainer.h>
#include "ArmorBase.h"
#include "ArmorModMatchSoundEffectsData.h"
#include "ArmorModifier.h"
#include "ArmorSetModSlot.h"
#include "BodyPartDestruction.h"
#include "EArmorSlot.h"
#include "EItemTier.h"
#include "ArmorItem.generated.h"

class AIndianaAiCharacter;
class AProjectile;
class UAkStateValue;
class UArmorAudio;
class UAssetCollection;
class UNiagaraSystem;
class UObject;
class UOwActorPool;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UArmorItem : public UArmorBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanGenerateLootOnBreakdown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FArmorModifier> ArmorModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FBodyPartDestruction> DestructibleParts;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FArmorSetModSlot ArmorModSlots[7];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FArmorSetModSlot BonusArmoringSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EArmorSlot ArmorSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EItemTier Tier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UArmorAudio> FPSoundEffectsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UArmorAudio> TPSoundEffectsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FArmorModMatchSoundEffectsData> ModdedSoundEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* ArmorAudioState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAssetCollection* AssetCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArmorAudio* CurrentArmorAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsesPooling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AProjectile> PooledProjectileClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AIndianaAiCharacter> PooledCharacterClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxPooledCharacterSpawnCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceAttackTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* SuccessfulSpawnFxSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* FailToSpawnFxSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalSpawnOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOwActorPool* CharacterPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOwActorPool* ProjectilePool;
    
public:
    UArmorItem();

protected:
    UFUNCTION(BlueprintCallable)
    void SpawnPooledProjectile(FVector SpawnLocation, FRotator SpawnRotator, float MinTime, float MaxTime);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void SpawnPooledCharacter(UObject* WorldContext, FVector SpawnLocation, FRotator SpawnRotator, AIndianaAiCharacter* ForceAttackTarget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnequip();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEquip();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UArmorAudio* GetCurrentAudio() const;
    
};

