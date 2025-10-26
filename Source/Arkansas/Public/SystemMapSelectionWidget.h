#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=Margin -FallbackName=Margin
#include "IndianaInterfaceUserWidget.h"
#include "Templates/SubclassOf.h"
#include "SystemMapSelectionWidget.generated.h"

class UImage;
class UInputLabelGroupWidget;
class USystemMapSelectionEntryWidget;
class UTextBlockBase;
class UVerticalBox;
class UWidget;

UCLASS(Blueprintable, EditInlineNew)
class USystemMapSelectionWidget : public UIndianaInterfaceUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin EntryPadding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USystemMapSelectionEntryWidget> EntryClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString FastTravelHeaderString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* HeaderTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* EntryList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelGroupWidget* InputLabelGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* MapPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* MapDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* EntryDivider;
    
public:
    USystemMapSelectionWidget();

};

