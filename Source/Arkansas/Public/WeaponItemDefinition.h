#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "DegradableItemDefinition.h"
#include "Templates/SubclassOf.h"
#include "WeaponItemDefinition.generated.h"

class UAmmo;
class UConsumableItem;
class UWeapon;
class UWeaponMod;

USTRUCT(BlueprintType)
struct FWeaponItemDefinition : public FDegradableItemDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UWeapon> WeaponClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAmmo> AmmoClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UConsumableItem> AmmoConsumableClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AmmoPoolSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UWeaponMod>> EquippedMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MetaTags;
    
    ARKANSAS_API FWeaponItemDefinition();
};

