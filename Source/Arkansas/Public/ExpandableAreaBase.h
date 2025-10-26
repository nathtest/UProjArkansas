#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=ExpandableAreaStyle -FallbackName=ExpandableAreaStyle
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=Margin -FallbackName=Margin
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateBrush -FallbackName=SlateBrush
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateColor -FallbackName=SlateColor
#include "Components\NamedSlotInterface.h"

#include "Components/Widget.h"
#include "ComponentEventMCDDelegate.h"
#include "OnExpandableAreaExpansionChangedDelegate2.h"
#include "ExpandableAreaBase.generated.h"

class USlateWidgetStyleAsset;

UCLASS(Blueprintable)
class UExpandableAreaBase : public UWidget, public INamedSlotInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USlateWidgetStyleAsset* HeaderWidgetStyle;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpandableAreaStyle Style;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush BorderBrush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateColor BorderColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin HitTestMargin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCenterSweepHitTest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsExpanded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin BorderPadding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin HeaderPadding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMargin AreaPadding;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnExpandableAreaExpansionChanged OnExpansionChanged;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnHeaderHoveredMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnHeaderUnhoveredMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnHeaderFocusReceivedMCD;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentEventMCD OnHeaderFocusLostMCD;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* HeaderContent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* BodyContent;
    
public:
    UExpandableAreaBase();

    UFUNCTION(BlueprintCallable)
    void SetIsExpanded_Animated(bool IsExpanded);
    
    UFUNCTION(BlueprintCallable)
    void SetIsExpanded(bool IsExpanded);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsExpanded() const;

    // INamedSlotInterface
    virtual void GetSlotNames(TArray<FName>& SlotNames) const override;
    virtual UWidget* GetContentForSlot(FName SlotName) const override;
    virtual void SetContentForSlot(FName SlotName, UWidget* Content) override;
    

    // Fix for true pure virtual functions not being implemented
};

