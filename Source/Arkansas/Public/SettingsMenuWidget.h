#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=IntPoint -FallbackName=IntPoint
#include <GameplayTagContainer.h>
#include <LocString.h>
#include "ECategory.h"
#include "ESetting.h"
#include "ESettingSubcategory.h"
#include "IndianaInterfaceUserWidget.h"
#include "OnHDRCalibrationEndedDelegate.h"
#include "OnHDRCalibrationStartedDelegate.h"
#include "SettingDescription.h"
#include "SettingsClosedDelegate.h"
#include "Templates/SubclassOf.h"
#include "SettingsMenuWidget.generated.h"

class UBackgroundPanelWidget;
class UHUDAdjustorWidget;
class UIndianaUserWidget;
class UInputLabelGroupWidget;
class UKeyBindsMenuWidget;
class UNavigationGroupWidget;
class UOEIUserSetting;
class UOwSettingsList;
class UPanelWidget;
class UScrollBox;
class USettingSubMenuHDR;
class USettingsMenuButtonSlotWidget;
class USettingsMenuColorPickerWidget;
class USettingsMenuData;
class USettingsMenuOptionPresenterWdgt;
class USettingsMenuSliderWidget;
class USettingsMenuSlotWidget;
class USettingsMenuSubcategoryWidget;
class USettingsMenuToggleWidget;
class USettingsMenuVisualizerBaseWidget;
class UTextBlockBase;
class UUserSetting;
class UUserSettingBool;
class UUserSettingInt32;
class UVerticalBox;
class UWidget;
class UWidgetSwitcher;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class USettingsMenuWidget : public UIndianaInterfaceUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSettingsClosed SettingsClosedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnHDRCalibrationStarted OnHDRCalibrationStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOnHDRCalibrationEnded OnHDRCalibrationEnded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideSettingsContent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOwSettingsList* OverrideSettingsList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsesSettingsFinish;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideLanguageOptionIfDisabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuSlotWidget> SubcategorySlotClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuSubcategoryWidget> SubcategoryClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuSliderWidget> SliderClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuToggleWidget> ToggleClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuOptionPresenterWdgt> OptionPresenterClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuOptionPresenterWdgt> LanguageOptionPresenterClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuColorPickerWidget> ColorPickerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuButtonSlotWidget> ButtonClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UKeyBindsMenuWidget> KeyBindInterfaceClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UHUDAdjustorWidget> HUDAdjustorSoftClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UIndianaUserWidget> HUDAdjustorBGSoftClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingSubMenuHDR> HDR_CalibrationClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSettingDescription HDR_CalibrationDisplayConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ECategory, FGameplayTag> CategoryTagMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, ESettingSubcategory> SubcategoryTagMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag SavesTargetTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UOEIUserSetting*> ReticleColorSetSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GamepadScrollMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint PlayInEditorOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PostProcessChromaticAberrationThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinCVarChromaticAberrationThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScrollBox* MenuScrollBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScrollBox* DescriptionScrollBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* Category0VerticalBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* Category1VerticalBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* Category2VerticalBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* Category3VerticalBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* Category4VerticalBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* Category5VerticalBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USettingsMenuSubcategoryWidget* DisplaySubcategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetSwitcher* MenuSwitcher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* DescriptionTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* NameTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidget* Background;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* VisualizerPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetSwitcher* VisualizerSwitcher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBackgroundPanelWidget* DescriptionBackgroundPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInputLabelGroupWidget* InputLabelGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UUserSetting*> UserSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UUserSetting*> DisplayUserSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ECategory, FLocString> NavBarCategories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString XboxSaveTargetText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString LocalSaveTargetText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USettingsMenuData* SettingsData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNavigationGroupWidget* NavigationBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UHUDAdjustorWidget* HUDAdjustorWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UIndianaUserWidget* HUDAdjustorBGWidget;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USettingsMenuSubcategoryWidget* VisualEffectCategoryWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USettingsMenuSlotWidget* ChromaticAberrationSlotWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<USettingsMenuVisualizerBaseWidget>> VisualizerClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<ESetting, USettingsMenuVisualizerBaseWidget*> VisualizerMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<FLocString, USettingsMenuVisualizerBaseWidget*> VisualizerByNameMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UUserSettingInt32* ResolutionSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UUserSettingInt32* WindowModeSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UUserSettingBool* CrossSaveSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USettingsMenuSlotWidget* CrossSaveSettingSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USettingsMenuToggleWidget* CrossSaveToggle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UOwSettingsList* RuntimeCombinedSettingsList;
    
public:
    USettingsMenuWidget();

    UFUNCTION(BlueprintCallable)
    void ValueChanged(UUserSetting* UserSetting);
    
private:
    UFUNCTION(BlueprintCallable)
    void UpdateDialogTimerText(float DeltaTime);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetVisualEffectQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetViewDistanceQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetTextureQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetShadowQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetReflectionQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetPostProcessingQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetGraphicsQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetGlobalIlluminationQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetFoliageQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetCrowdDensity(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetAntiAliasingQuality(int32 Value);
    
    UFUNCTION(BlueprintCallable)
    void SetAntiAliasingMethod(int32 Value);
    
public:
    UFUNCTION(BlueprintCallable)
    void RestoreFocusOnDelay();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnToggleFullscreenMode(bool bIsFullscreen);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnShowSaveTargetWarning(bool bSaveToXbox);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnParentSettingChanged(const FString& ParentSettingName);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnOpenKeybindMenu(bool bIsPcKeybinds);
    
    UFUNCTION(BlueprintCallable)
    void OnOpenHUDAdjustor();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenCalibrateHDR();
    
    UFUNCTION(BlueprintCallable)
    void OnInputBack();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnDetectGraphics();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnDefaultAllClicked();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCyclePageRight();
    
    UFUNCTION(BlueprintCallable)
    void OnCyclePageLeft();
    
    UFUNCTION(BlueprintCallable)
    void HandleAppUnconstrain();
    
public:
    UFUNCTION(BlueprintCallable)
    void EmptyHandler();
    
};

