#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
#include <GameplayTagContainer.h>
#include "IndianaUserWidget.h"
#include "QuestLogWidget.generated.h"

class UBorder;
class UImage;
class UInvalidationBox;
class UOwConversationInstance;
class UQuestLogEntryWidget;
class UScaleBox;
class UWidgetAnimation;

UCLASS(Blueprintable, EditInlineNew)
class UQuestLogWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ScaleSettingTag;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBorder* AnimationBorder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* FadeIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* FadeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* QuestBacking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInvalidationBox* MainInvalidationBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScaleBox* ContainerScaleBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestLogEntryWidget* QuestEntry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDisplayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlwaysOnFadeOutStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AnimSpeedIncreaseThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimSpeedIncreaseScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimRatioMaxCutoff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisplayAllNotifications;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPauseAudioEventsDuringConversation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysShowSelectedQuestOnLedgerMinimize;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGuid SelectedQuestOnMaximize;
    
public:
    UQuestLogWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnSelfAnimFinished();
    
    UFUNCTION(BlueprintCallable)
    void OnScaleSettingChanged(float NewValue);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestUpdateModeChanged(int32 ModeIn);
    
    UFUNCTION(BlueprintCallable)
    void OnHUDVisibilityChanged(bool bVisibleIn);
    
    UFUNCTION(BlueprintCallable)
    void OnEntryAnimsFinished();
    
    UFUNCTION(BlueprintCallable)
    void OnConversationStarted(UOwConversationInstance* Instance);
    
    UFUNCTION(BlueprintCallable)
    void OnConversationEnded(UOwConversationInstance* Instance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyUpdatePhaseStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyOutroPhaseStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyIntroPhaseStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyFadeOutAnimCalled();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyFadeInAnimCalled();
    
    UFUNCTION(BlueprintCallable)
    void MoveToNextPhase(bool bForceNextPhase);
    
};

