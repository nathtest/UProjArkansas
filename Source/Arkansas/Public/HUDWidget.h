#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "EPresentationModeCameraFadeType.h"
#include "IndianaInterfaceUserWidget.h"
#include "Templates/SubclassOf.h"
#include "HUDWidget.generated.h"

class UAmmoReadoutWidget;
class UAudioLogWidget;
class UAwarenessIndicatorWidget;
class UCanvasPanel;
class UCharacterInfoComponent;
class UCompanionOverviewWidget;
class UDamageIndicatorWidget;
class UFlaw;
class UGenericNotificationWidget;
class UGrenadeIndicatorWidget;
class UHUDFactionPromptWidget;
class UInteractionPromptWidget;
class UItemContainerWidget;
class UItemToolTipWidget;
class ULevelUpNotificationWidget;
class UMinimapWidget;
class UObservationGuideWidget;
class UOwConversationInstance;
class UPOIPromptWidget;
class UPlayerStatsDisplayWidget;
class UQuestLogWidget;
class URadioNotificationWidget;
class UReticleWidget;
class UTTDEnemyScanner;
class UWeaponSelectWidget;
class UWidgetSwitcher;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UHUDWidget : public UIndianaInterfaceUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag WidthScaleSettingTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag HeightScaleSettingTag;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* SafeSpaceCanvasPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* HudContents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReticleWidget* Reticle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayerStatsDisplayWidget* PlayerStatsDisplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCompanionOverviewWidget* CompanionOverview_0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCompanionOverviewWidget* CompanionOverview_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTTDEnemyScanner* EnemyScanner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UQuestLogWidget* QuestLog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGenericNotificationWidget* GenericLog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeaponSelectWidget* WeaponSelect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractionPromptWidget* InteractionPrompt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAmmoReadoutWidget* AmmoReadout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULevelUpNotificationWidget* LevelUpNotification;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPOIPromptWidget* POIPrompt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemContainerWidget* ItemContainerWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemToolTipWidget* HudStaticTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemToolTipWidget* ComparisonTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGrenadeIndicatorWidget* GrenadeIndicatorWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageIndicatorWidget* DamageIndicatorWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObservationGuideWidget* ObservationGuide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapWidget* MinimapWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAwarenessIndicatorWidget* AwarenessIndicatorMasterWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHUDFactionPromptWidget* FactionPromptWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URadioNotificationWidget* RadioNotificationWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioLogWidget* AudioLogWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetSwitcher* AudioRadioSwitcher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlawDisplayDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LevelUpDisplayDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowMapTransitionNotifications;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFlaw> Flaw;
    
public:
    UHUDWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void QueueLevelUpNotification(UCharacterInfoComponent* InCharacterInfoComponent, int32 NewLevel);
    
    UFUNCTION(BlueprintCallable)
    void OnRadioNotifStateChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnHUDWidthSafeZoneChanged(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnHUDSafeZoneChanged(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnHUDHeightSafeZoneChanged(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnConversationFadeToBlackStarted(UOwConversationInstance* ConversationInstance, EPresentationModeCameraFadeType FadeType);
    
    UFUNCTION(BlueprintCallable)
    void OnConversationEnded(UOwConversationInstance* ConversationInstance);
    
};

