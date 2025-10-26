#pragma once
#include "CoreMinimal.h"
#include "GauntletTestController.h"
#include "Templates/SubclassOf.h"
#include "ArkansasTestControllerPSOCollection.generated.h"

class UArmorItem;
class UArmorModItem;
class UImage;
class UPhysicalMaterial;
class UWeapon;
class UWeaponMod;
class UWorld;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UArkansasTestControllerPSOCollection : public UGauntletTestController {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> WorldsToProcess;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MapCollectionLoadRadius;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxBoundsWarning;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoundsIterationLimit;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 LocationFrameWaitCount;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MapCollectionVFXAdvanceTimePerTick;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ProcessingFrameWaitCount;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DynamicCollectionNiagaraSystemAdvanceAmount;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UIStepWaitTimeSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UImage* SpawnedUIImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UArmorItem>> EquipmentArmor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UArmorModItem>> EquipmentArmorMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UWeapon>> EquipmentWeapons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UWeaponMod>> EquipmentWeaponMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPhysicalMaterial*> FakePhysicsMaterials;
    
public:
    UArkansasTestControllerPSOCollection(const FObjectInitializer& ObjectInitializer);

};

