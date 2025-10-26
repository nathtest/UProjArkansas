#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Templates/SubclassOf.h"
#include "SettingsMenuSubcategoryWidget.generated.h"

class UButtonBase;
class USettingsMenuSlotWidget;
class UTextBlockBase;
class UVerticalBox;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class USettingsMenuSubcategoryWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButtonBase* ApplyButton;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* CategoryNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* SlotsVerticalBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuSlotWidget> SubcategorySlotClass;
    
public:
    USettingsMenuSubcategoryWidget();

};

