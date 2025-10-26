#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include <LocString.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=FontOutlineSettings -FallbackName=FontOutlineSettings
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateColor -FallbackName=SlateColor
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateFontInfo -FallbackName=SlateFontInfo
#include "Components/TextWidgetTypes.h"
#include "EIndianaUIColorType.h"
#include "ETextScalingType.h"
#include "IndianaTextBlockStyle.h"
#include "TextBlockBase.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class UTextBlockBase : public UTextLayoutWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TextReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideGuiText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Text;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoFormatText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TextFormatReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TextFormatTokenName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDesiredWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConvertToUpper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxFontScaling;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWrapWithInvalidationPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIndianaTextBlockStyle WidgetStyle;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseShadowOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseOutline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETextScalingType TextScalingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 InitialFontSize;
    
public:
    UTextBlockBase();

    UFUNCTION(BlueprintCallable)
    void UseTextStyleShadowOffset(bool bShouldUse);
    
    UFUNCTION(BlueprintCallable)
    void UseTextStyleOutline(bool bShouldUse);
    
    UFUNCTION(BlueprintCallable)
    void SetTextWithLengthLimit(const FString& InString, const int32 MaxLen);
    
    UFUNCTION(BlueprintCallable)
    void SetTextByLocString(const FLocString& LocString);
    
    UFUNCTION(BlueprintCallable)
    void SetText(const FString& InString);
    
    UFUNCTION(BlueprintCallable)
    void SetShadowOffset(FVector2D InShadowOffset);
    
    UFUNCTION(BlueprintCallable)
    void SetShadowColorAndOpacity(FLinearColor InShadowColorAndOpacity);
    
    UFUNCTION(BlueprintCallable)
    void SetOutline(FFontOutlineSettings OutlineSettings);
    
    UFUNCTION(BlueprintCallable)
    void SetOpacity(float InOpacity);
    
    UFUNCTION(BlueprintCallable)
    void SetMinDesiredWidth(float NewMinDesiredWidth);
    
    UFUNCTION(BlueprintCallable)
    void SetFont(FSlateFontInfo InFontInfo);
    
    UFUNCTION(BlueprintCallable)
    void SetColorOverride(EIndianaUIColorType ColorOverride);
    
    UFUNCTION(BlueprintCallable)
    void SetColorAndOpacity(FSlateColor InColorAndOpacity);
    
    UFUNCTION(BlueprintCallable)
    void ResetColorOverride();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEmpty() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetText() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSlateFontInfo GetFont() const;
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetDynamicOutlineMaterial();
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetDynamicFontMaterial();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSlateColor GetColorAndOpacity() const;
    
};

