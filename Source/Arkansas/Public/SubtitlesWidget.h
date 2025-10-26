#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "IndianaUserWidget.h"
#include "SubtitlesWidget.generated.h"

class UImage;
class UOWRichTextBlockBase;
class UOverlay;
class UPanelWidget;
class USizeBox;
class UTextBlockBase;
class UVerticalBox;
class UWidget;
class UWidgetSwitcher;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class USubtitlesWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TextSizeBoxVerticalOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TextSizeBoxHorizontalOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag SubtitleDirectionArrowTagName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSpeakerArrowDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UpdateArrowDistanceThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag SubtitleRadioContentTagName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag SubtitleAudioLogContentTagName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag SubtitleMaxWidthTagName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> SubtitleWidths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* SubtitlesBackgroundImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* SubtitlesBackgroundPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetSwitcher* AlternateContentSwitcher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* AudioLogDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* RadioDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* SpeakerArrowPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* SubtitleOverlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* SubtitleTextVerticalBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* SpeakerInfoPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* SpeakerTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOWRichTextBlockBase* MessageTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* PrependMessageTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USizeBox* TextSizeBox;
    
public:
    USubtitlesWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnSubtitleTextOpacityChanged(float NewOpacity);
    
    UFUNCTION(BlueprintCallable)
    void OnSubtitleTextColorChanged(int32 NewColorIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnSubtitleShowSpeakerDirectionChanged(bool bShowDirection);
    
    UFUNCTION(BlueprintCallable)
    void OnSubtitleShowRadioContentChanged(bool bShowRadioContent);
    
    UFUNCTION(BlueprintCallable)
    void OnSubtitleShowAudioLogContentChanged(bool bShowAudioLogContentIn);
    
    UFUNCTION(BlueprintCallable)
    void OnSubtitleMaxWidthChanged(int32 MaxWidthOption);
    
    UFUNCTION(BlueprintCallable)
    void OnSubtitleFontSizeChanged(int32 NewSize);
    
    UFUNCTION(BlueprintCallable)
    void OnSubtitleBGOpacityChanged(float NewOpacity);
    
    UFUNCTION(BlueprintCallable)
    void OnSubtitleBGColorChanged(int32 NewColorIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnShowSubtitleSpeakerChanged(bool bShowSpeakerName);
    
    UFUNCTION(BlueprintCallable)
    void OnShowFontOutlineChanged(bool bShowFontOutline);
    
    UFUNCTION(BlueprintCallable)
    void OnShowFontDropShadowChanged(bool bShowShadowOffset);
    
    UFUNCTION(BlueprintCallable)
    void OnBarkSubtitleVisibilityChanged(bool bVisible);
    
};

