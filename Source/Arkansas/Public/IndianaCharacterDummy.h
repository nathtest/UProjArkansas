#pragma once
#include "CoreMinimal.h"
#include "GameFrameWork\Character.h"
#include "PropComponents.h"
#include "RandomPlayerSequenceEntryNamed.h"
#include "IndianaCharacterDummy.generated.h"

class AIndianaCharacter;
class UAppearanceComponent;
class UEquipmentComponent;
class USceneComponent;
class UWeapon;

UCLASS(Blueprintable)
class AIndianaCharacterDummy : public ACharacter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreWeaponIdles;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowUnderKillPlane;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMakeTickableWhenPaused;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRandomPlayerSequenceEntryNamed> DefaultFidgets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* GroundOffsetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEquipmentComponent* EquipmentComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAppearanceComponent* AppearanceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeapon* PendingWeapon;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPropComponents> Props;
    
    AIndianaCharacterDummy(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnWeaponEndEquip(UEquipmentComponent* InEquipmentComponent, UWeapon* Weapon);
    
public:
    UFUNCTION(BlueprintCallable)
    void CopyFromCharacter(AIndianaCharacter* Character);
    
};

