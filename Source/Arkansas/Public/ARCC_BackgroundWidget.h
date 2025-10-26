#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "ARCC_BasePageWidget.h"
#include "Templates/SubclassOf.h"
#include "ARCC_BackgroundWidget.generated.h"

class UARCC_CreationEntryItem;
class UAptitude;
class UImage;
class UPanelWidget;
class UScrollBox;
class UTextBlockBase;
class UWidgetAnimation;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UARCC_BackgroundWidget : public UARCC_BasePageWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAptitude>> AptitudeData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UARCC_CreationEntryItem> BackgroundItemEntryClass;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString BackgroundStaticFlavorText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyDefaultSelection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRandomlySelectBackground;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAptitude> DefaultAptitudeClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* BackgroundSummaryContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* BackgroundFlavorTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* BackgroundDescTextblock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* BackgroundTitleTextblock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* BackgroundIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScrollBox* ScrollBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* TransitionTextHideAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* TransitionTextShowAnim;
    
public:
    UARCC_BackgroundWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnTransitionTextAnimComplete();
    
};

