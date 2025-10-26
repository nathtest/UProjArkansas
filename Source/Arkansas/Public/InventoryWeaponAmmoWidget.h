#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateBrush -FallbackName=SlateBrush
#include "Blueprint/UserWidget.h"
#include "InventoryWeaponAmmoWidget.generated.h"

class UButtonBase;
class UImage;
class UTextBlockBase;
class UTexture2D;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UInventoryWeaponAmmoWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush Brush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* Button;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* Image;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* CountTextBlock;
    
public:
    UInventoryWeaponAmmoWidget();

    UFUNCTION(BlueprintCallable)
    void SetIcon(UTexture2D* Icon);
    
};

