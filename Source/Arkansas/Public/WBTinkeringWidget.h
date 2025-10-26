#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "BaseInventoryItemManagement.h"
#include "BaseWorkbenchActivtyWidget.h"
#include "ETinkeringState.h"
#include "WBTinkeringWidget.generated.h"

class AIndianaAiCharacter;
class UItemToolTipWidget;
class UTextBlockBase;
class UVerticalBox;
class UWBTinkerOptionWidget;
class UWeapon;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UWBTinkeringWidget : public UBaseInventoryItemManagement, public IBaseWorkbenchActivtyWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* StateTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* TinkerOptionContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemToolTipWidget* ItemTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWBTinkerOptionWidget* TinkerOption1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWBTinkerOptionWidget* TinkerOption2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWBTinkerOptionWidget* TinkerOption3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AIndianaAiCharacter>> ProhibitedCharacterClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ETinkeringState, FLocString> StateToTinkeringStringMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeapon* SelectedTinkerItem;
    
public:
    UWBTinkeringWidget();


    // Fix for true pure virtual functions not being implemented
};

