#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "EWorkbenchState.h"
#include "IndianaInterfaceUserWidget.h"
#include "NewWorkbenchWidget.generated.h"

class UFlaw;
class UItemBreakdownWidget;
class UTextBlockBase;
class UWBCompanionUpgradeWidget;
class UWBCraftingPageWidget;
class UWBLandingPageWidget;
class UWBModificationPageWidget;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UNewWorkbenchWidget : public UIndianaInterfaceUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CategoryTransitionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClearInterestOnEntry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EWorkbenchState> WorkbenchCategoryOrderArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EWorkbenchState, FLocString> StateToActivityStringMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UFlaw> DisableBreakdownFlawClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* StateTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWBCraftingPageWidget* CraftingWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWBLandingPageWidget* LandingPageWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWBModificationPageWidget* ModificationWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemBreakdownWidget* BreakdownWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWBCompanionUpgradeWidget* CompanionUpgradeWidget;
    
public:
    UNewWorkbenchWidget();

};

