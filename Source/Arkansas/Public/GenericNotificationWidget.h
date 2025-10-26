#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "EItemRarity.h"
#include "ESaveGameResult.h"
#include "ESaveGameType.h"
#include "IndianaUserWidget.h"
#include "NotificationDurations.h"
#include "GenericNotificationWidget.generated.h"

class UBorder;
class UGenericNotificationEntryWidget;
class UScaleBox;
class USizeBox;
class UWidgetAnimation;
class UWidgetSwitcher;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UGenericNotificationWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ScaleSettingTag;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBorder* MainBorder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGenericNotificationEntryWidget* EntryWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USizeBox* ContentSizeBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScaleBox* ContainerScaleBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBorder* ContentContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetSwitcher* RaritySwitcher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* FadeIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* FadeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* RarityFade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ContentResizeInterpExponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ContentVerticalPadding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GenericLogBackingMaterialSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNotificationDurations ItemNotificationDurations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNotificationDurations ExpNotificationDurations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowTickWhilePaused;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideNotificationIfPaused;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RestoreHiddenTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPauseForFullScreenTutorial;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EItemRarity, int32> RarityToSwitcherIndex;
    
public:
    UGenericNotificationWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnScaleSettingChanged(float NewValue);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameComplete(ESaveGameResult SaveResult, ESaveGameType SaveGameType);
    
    UFUNCTION(BlueprintCallable)
    void OnNotificationDurationChanged(int32 NotificationDurationIn);
    
    UFUNCTION(BlueprintCallable)
    void OnHUDVisibilityChanged(bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void OnFadeOutComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnFadeInComplete();
    
};

