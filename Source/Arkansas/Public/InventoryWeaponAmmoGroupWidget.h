#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "IndianaUserWidget.h"
#include "Templates/SubclassOf.h"
#include "InventoryWeaponAmmoGroupWidget.generated.h"

class UAmmo;
class UInventoryWeaponAmmoWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UInventoryWeaponAmmoGroupWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString AmmoName0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryWeaponAmmoWidget* Ammo0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAmmo> RelatedAmmoClass;
    
public:
    UInventoryWeaponAmmoGroupWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHighlightChange(bool bHighlight);
    
};

