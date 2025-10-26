#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "EIndianaUIColorType.h"
#include "ESkill.h"
#include "IndianaInterfaceUserWidget.h"
#include "NotificationDurations.h"
#include "LevelUpNotificationWidget.generated.h"

class AIndianaCharacter;
class UBorder;
class UCharacterInfoComponent;
class UImage;
class UInputLabelGroupWidget;
class UOverlay;
class UScaleBox;
class UTextBlockBase;
class UWidgetAnimation;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ULevelUpNotificationWidget : public UIndianaInterfaceUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ScaleSettingTag;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScaleBox* ContainerScaleBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideReminderAfterPointScreenOpened;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultDisplayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EIndianaUIColorType InputLabelColorOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag LevelUpNotificationDurationTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNotificationDurations LevelUpNotificationDurations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* MainOverlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBorder* FadeInContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* LevelFlowLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* LevelFlowRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* DarkBacking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* LevelUpBacking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* CongratsTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* NewLevelTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* InputLabelOverlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelGroupWidget* LevelUpInputLabelGroupSkills;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelGroupWidget* LevelUpInputLabelGroupSkillsAndPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelGroupWidget* ReminderInputLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* LevelUpReminderOverlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* PrimaryFadeIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* FadeOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* SecondaryFadeIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* FadeInLevelUpReminder;
    
public:
    ULevelUpNotificationWidget();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetOpacities_BP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetMaterialData();
    
    UFUNCTION(BlueprintCallable)
    void PlayerCombatStateChanged(AIndianaCharacter* InCharacter, bool bIsInCombat, bool bRestoring);
    
    UFUNCTION(BlueprintCallable)
    void OnWaitTimerComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnTextAndSunFadeOutComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnSkillUpdated(UCharacterInfoComponent* InCharacterInfoComponent, ESkill Skill, int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSkillOrPerkPageVisited();
    
    UFUNCTION(BlueprintCallable)
    void OnScaleSettingChanged(float NewValue);
    
    UFUNCTION(BlueprintCallable)
    void OnProgressToSkillsPage();
    
    UFUNCTION(BlueprintCallable)
    void OnProgressToPerksPage();
    
    UFUNCTION(BlueprintCallable)
    void OnPrimaryTextAndSunFadeInComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnPerkAdded();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelUpReminderVisibilityChanged(bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void OnLevelUpNotificationVisibilityChanged(int32 NotificationDurationIn);
    
    UFUNCTION(BlueprintCallable)
    void OnHUDVisibilityChanged(bool bVisible);
    
};

