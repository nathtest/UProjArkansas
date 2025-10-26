#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=ESelectInfo -FallbackName=ESelectInfo
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=Margin -FallbackName=Margin
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateColor -FallbackName=SlateColor
#include "Components/Widget.h"
#include "ComponentEventMCDDelegate.h"
#include "IndianaComboBoxStyle.h"
#include "ComboBoxStringBase.generated.h"

UCLASS(Blueprintable)
class UComboBoxStringBase : public UWidget {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSelectionChangedEvent, const FString&, SelectedItem, TEnumAsByte<ESelectInfo::Type>, SelectionType);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpeningEvent);
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> DefaultOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SelectedOption;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIndianaComboBoxStyle WidgetStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin ContentPadding;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxListHeight;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasDownArrow;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableGamepadNavigationMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateColor ForegroundColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFocusable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWidget::FGenerateWidgetForString OnGenerateWidgetEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSelectionChangedEvent OnSelectionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnOpeningEvent OnOpening;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnHoveredMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnUnhoveredMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnFocusReceivedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnFocusLostMCD;
    
    UComboBoxStringBase();

    UFUNCTION(BlueprintCallable)
    void SetSelectedOption(const FString& Option);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveOption(const FString& Option);
    
    UFUNCTION(BlueprintCallable)
    void RefreshOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSelectedOptionIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetSelectedOption() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetOptionCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetOptionAtIndex(int32 Index) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 FindOptionIndex(const FString& Option) const;
    
    UFUNCTION(BlueprintCallable)
    void ClearSelection();
    
    UFUNCTION(BlueprintCallable)
    void ClearOptions();
    
    UFUNCTION(BlueprintCallable)
    void AddOption(const FString& Option);
    
};

