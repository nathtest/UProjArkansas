#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "ConditionalDeathClass.h"
#include "DamageDescription.h"
#include "EAnimNotify.h"
#include "ESkill.h"
#include "ItemStack.h"
#include "ResourceItem.h"
#include "Templates/SubclassOf.h"
#include "Throwable.generated.h"

class AActor;
class AProjectile;
class UAssetCollection;
class UInventoryComponent;
class UOwActorPool;
class UPlayerTPVWeaponAnimations;
class UProjectileArcVisuals;
class UThrowableAnimationsFPV;
class UWeapon;
class UWeaponActorSpawnData;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UThrowable : public UResourceItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkill Skill;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AProjectile> HeldProjectileClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AProjectile> ProjectileClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageDescription DamageDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditionalDeathClass InnerRadiusDeathClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditionalDeathClass OuterRadiusDeathClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWeaponActorSpawnData> ImpactActorSpawnData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyDamageDescriptionToSpawnedActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UThrowableAnimationsFPV> FPVAnimationsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UPlayerTPVWeaponAnimations> PlayerWeaponAnimationsOverrideClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPlayerTPVWeaponAnimations* PlayerWeaponAnimationsOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimPitchOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerProjectileInitialLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCookable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerProjectilePostBounceLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AIProjectileInitialLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AIProjectilePostBounceLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UProjectileArcVisuals> ArcVisualsClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAssetCollection* AssetCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AProjectile* HeldProjectileClassDefaultObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AProjectile* ProjectileClassDefaultObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AProjectile* AttachedProxyProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UProjectileArcVisuals* ArcVisuals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ThrowableType;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAIPreferLowArc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsOffensiveThrowable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDefensiveThrowable;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOwActorPool* ActorPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PoolSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> PooledActorClass;
    
public:
    UThrowable();

private:
    UFUNCTION(BlueprintCallable)
    void ReenableProjectileCollision();
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerStopSprint();
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerInterrupted();
    
    UFUNCTION(BlueprintCallable)
    void OnInventoryItemRemoved(UInventoryComponent* InInventoryComponent, const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable)
    void OnEquippedWeaponEndHolster(UWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable)
    void OnAnimNotifyEvent(EAnimNotify AnimNotifyEvent, FName OptionalSocket);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTag GetThrowableTag() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRadius() const;
    
};

