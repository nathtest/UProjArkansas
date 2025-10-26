#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "AimAdhesionInterface.h"
#include "DamageDescription.h"
#include "DamageLevelScaler.h"
#include "DamageTierScaler.h"
#include "DestructibleDamagedDelegate.h"
#include "DestructibleDestroyedDelegate.h"
#include "DestructibleHealthTierScaler.h"
#include "DestructibleLightlyDamagedDelegate.h"
#include "DestructiblePristineDelegate.h"
#include "DestructibleStateData.h"
#include "ECoverTypes.h"
#include "EDestructibleState.h"
#include "ESkillDifficultyTier.h"
#include "OwActorPoolInterface.h"
#include "Templates/SubclassOf.h"
#include "TrapEffectSource.h"

#include "Destructible.generated.h"

class UCapsuleComponent;
class UDestructibleAudioComponent;
class UHealthComponent;
class UImpactDataSet;
class UMaterialInterface;
class UObsidianIDComponent;
class UOwActorPool;
class UOwNavModifierComponent;
class USceneComponent;
class UStaticMeshComponent;
class UTargetableComponent;
class UTrapAudioComponent;
class UTravelRegionData;

UCLASS(Blueprintable, MinimalAPI)
class ADestructible : public AActor, public ITrapEffectSource, public IAimAdhesionInterface, public IOwActorPoolInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDestructiblePristine OnDestructiblePristine;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDestructibleLightlyDamaged OnDestructibleLightlyDamaged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDestructibleDamaged OnDestructibleDamaged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDestructibleDestroyed OnDestructibleDestroyed;


    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDestructibleState InitialState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDestructibleStateData PristineState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDestructibleStateData LightlyDamagedState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDestructibleStateData DamagedState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDestructibleStateData DestroyedState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowHealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDestructibleHealthTierScaler MaxHealthTierScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableCollisionOnDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableCoverOnDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DisabledCoverExtents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChangeCoverTypeOnStateChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EDestructibleState, ECoverTypes> StateBasedCoverTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UImpactDataSet* ImpactDataSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UImpactDataSet* DestroyedDataSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageDescription DamageDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageLevelScaler DamageLevelScaler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageTierScaler DamageTierScaler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHealthComponent* HealthComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* DetonationPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTargetableComponent* TargetableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwNavModifierComponent* NavModifierComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTrapAudioComponent> TrapAudioClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrapAudioComponent* TrapAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDestructibleAudioComponent> DestructibleAudioClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDestructibleAudioComponent* DestructibleAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AISoundRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AISoundVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DisarmMaterialSensors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DisarmMaterialRing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DisarmLightColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* PlacedMaterialSensors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* PlacedMaterialRing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor PlacedLightColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowDamageNumbers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPooled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LootSeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLooted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitResult LastHitResult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkillDifficultyTier SkillDifficultyTierOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* ArmedMaterialSensors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* ArmedMaterialRing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UTravelRegionData*, TSoftObjectPtr<UMaterialInterface>> RegionMaterials;

    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOwActorPool* OwningPool;
    
public:
    ADestructible(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetLooted();
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetDestructibleState(EDestructibleState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReceiveTriggerUntripped();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReceiveTriggerTripped();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReceiveTriggerDisarmed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReceiveTriggerArmed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReceivePreDeploy();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReceiveDeployOrder();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateChanged(EDestructibleState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpawnedFromPoolBP();
    
    UFUNCTION(BlueprintCallable)
    void OnHealthChanged(UHealthComponent* InHealthComponent, float PrevNormalizedHealth, float CurrNormalizedHealth, AActor* InInstigator);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFreedToPoolBP();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLooted();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetInActorPool();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealthForState(EDestructibleState DSTState) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EDestructibleState GetCurrentState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCanDetonate() const;
    
    UFUNCTION(BlueprintCallable)
    void GenerateLootSeedIfUnset();
    
protected:
    UFUNCTION(BlueprintCallable)
    void FreeToPoolBP();
    

    // Fix for true pure virtual functions not being implemented
};

