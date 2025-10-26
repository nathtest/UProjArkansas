#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include <LocString.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=EButtonClickMethod -FallbackName=EButtonClickMethod
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=EButtonTouchMethod -FallbackName=EButtonTouchMethod
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=EFocusCause -FallbackName=EFocusCause
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=Margin -FallbackName=Margin
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateBrush -FallbackName=SlateBrush
#include "Components/ContentWidget.h"
#include "ButtonEventMCDDelegate.h"
#include "ComponentEventMCDDelegate.h"
#include "ContinuousHoldConfig.h"
#include "EButtonType.h"
#include "IndianaButtonStyle.h"
#include "NoParamMCDDelegate.h"
#include "Templates/SubclassOf.h"
#include "ButtonBase.generated.h"

class UTexture2D;
class UToolTipContentWidget;

UCLASS(Blueprintable)
class UButtonBase : public UContentWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UToolTipContentWidget> ToolTipClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TextReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EButtonType ButtonType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClickEnabled;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSelected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsFocusable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowSelectionStateChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanActivateByKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProcessDoubleClickAsClick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProcessAuxDoubleClickAsAuxClick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseHoldToClick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoldToClickTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowHoldText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseHoldToClickAux;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoldToClickAuxTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FContinuousHoldConfig ContinuousHoldConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FContinuousHoldConfig ContinuousHoldConfigAux;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EButtonClickMethod::Type> ClickMethod;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EButtonTouchMethod::Type> TouchMethod;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnHoveredMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnPressedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnReleasedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnClickedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnAuxClickedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnDoubleClickedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnAuxDoubleClickedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnUnhoveredMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnFocusLostMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnFocusReceivedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNoParamMCD OnSelectedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNoParamMCD OnUnselectedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnHoldStartedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnHoldCancelledMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnHoldCompletedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnAuxHoldStartedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnAuxHoldCancelledMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonEventMCD OnAuxHoldCompletedMCD;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIndianaButtonStyle WidgetStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin HitTestMargin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCenterSweepHitTest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* AdvancedHitTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AdvancedHitAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPopulateWithDefaultAudio;
    
public:
    UButtonBase();

    UFUNCTION(BlueprintCallable)
    void StopSimulateHoldClick();
    
    UFUNCTION(BlueprintCallable)
    void StartSimulateHoldClick(float OverrideHoldTime);
    
    UFUNCTION(BlueprintCallable)
    void SetShowDisabled(bool bShowDisabledIn);
    
    UFUNCTION(BlueprintCallable)
    void SetSelectedPressedBrush(const FSlateBrush& InBrush);
    
    UFUNCTION(BlueprintCallable)
    void SetSelectedNormalBrush(const FSlateBrush& InBrush);
    
    UFUNCTION(BlueprintCallable)
    void SetSelectedHoveredBrush(const FSlateBrush& InBrush);
    
    UFUNCTION(BlueprintCallable)
    void SetSelectedFocusedBrush(const FSlateBrush& InBrush);
    
    UFUNCTION(BlueprintCallable)
    void SetSelected(bool NewBSelected, EFocusCause Cause);
    
    UFUNCTION(BlueprintCallable)
    void SetPressedBrush(const FSlateBrush& InBrush);
    
    UFUNCTION(BlueprintCallable)
    void SetNormalBrush(const FSlateBrush& InBrush);
    
    UFUNCTION(BlueprintCallable)
    void SetHoveredBrush(const FSlateBrush& InBrush);
    
    UFUNCTION(BlueprintCallable)
    void SetFocusedBrush(const FSlateBrush& InBrush);
    
    UFUNCTION(BlueprintCallable)
    void SetFocusable(bool bFocused);
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool bInEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetDisabledBrush(const FSlateBrush& InBrush);
    
    UFUNCTION(BlueprintCallable)
    void SetContentColor(FLinearColor InColorAndOpacity);
    
    UFUNCTION(BlueprintCallable)
    void SetClickable(bool bIsClickableIn);
    
    UFUNCTION(BlueprintCallable)
    void SetButtonType(EButtonType TypeIn);
    
    UFUNCTION(BlueprintCallable)
    void SetButtonColor(FLinearColor InBackgroundColor);
    
    UFUNCTION(BlueprintCallable)
    void SetAllowSelectionStateChange(bool bAllowChange);
    
    UFUNCTION(BlueprintCallable)
    void SetAdvancedHitTexture(UTexture2D* InTexture);
    
    UFUNCTION(BlueprintCallable)
    void SetAdvancedHitAlpha(int32 InAlpha);
    
    UFUNCTION(BlueprintCallable)
    void OverrideSelectedBrushTextures(UTexture2D* InTexture);
    
    UFUNCTION(BlueprintCallable)
    void OverrideBrushTextures(UTexture2D* InTexture);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSelected() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPressed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHoldInProgress() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleOnSimulateClickTimeComplete();
    
    UFUNCTION(BlueprintCallable)
    void HandleOnClickTimeComplete();
    
public:
    UFUNCTION(BlueprintCallable)
    FSlateBrush GetSelectedPressedBrush();
    
    UFUNCTION(BlueprintCallable)
    FSlateBrush GetSelectedNormalBrush();
    
    UFUNCTION(BlueprintCallable)
    FSlateBrush GetSelectedHoveredBrush();
    
    UFUNCTION(BlueprintCallable)
    FSlateBrush GetSelectedFocusedBrush();
    
    UFUNCTION(BlueprintCallable)
    FSlateBrush GetPressedBrush();
    
    UFUNCTION(BlueprintCallable)
    FSlateBrush GetNormalBrush();
    
    UFUNCTION(BlueprintCallable)
    FSlateBrush GetHoveredBrush();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHoldToClickTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHoldToClickAuxTime() const;
    
    UFUNCTION(BlueprintCallable)
    FSlateBrush GetFocusedBrush();
    
    UFUNCTION(BlueprintCallable)
    FSlateBrush GetDisabledBrush();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EButtonType GetButtonType() const;
    
    UFUNCTION(BlueprintCallable)
    void DisableHoldClick();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllowsSelectionStateChange() const;
    
};

