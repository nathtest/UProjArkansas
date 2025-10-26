#pragma once
#include "CoreMinimal.h"
#include "GameFramework\HUD.h"

#include <LocString.h>
#include "ECheckBranches.h"
#include "EPresentationModeCameraFadeType.h"
#include "InteractionDescription.h"
#include "OnSpotterTriggeredDelegate.h"
#include "Templates/SubclassOf.h"
#include "IndianaUI.generated.h"

class AIndianaAiCharacter;
class APetKennel;
class AStatusTagActor;
class UArmorComponent;
class UCinematicFramingWidget;
class UCinematicPlayerWidget;
class UCompanionSelectionWidget;
class UComputerTerminalWidget;
class UConversationSubtitleWidget;
class UConversationWidget;
class UDamageTextContainerWidget;
class UDebugCharacterLoader;
class UDebugMenuWidget;
class UDebugOverlayWidget;
class UDialogBoxRespecWidget;
class UDialogBoxWidget;
class UDialogWarningBoxWidget;
class UDownedMenuWidget;
class UHUDWidget;
class UIndianaDamageType;
class UIndianaInterfaceUserWidget;
class UIndianaItemAudioData;
class UInventoryWidget;
class UItem;
class UItemBreakdownWidget;
class UItemContainerWidget;
class UItemInspectorWidget;
class UItemTransferWidget;
class ULedgerWidget;
class ULevelUpNotificationWidget;
class UMaterialParameterCollection;
class UMaterialParameterCollectionInstance;
class UMoviePlayerWidget;
class UMultifloorElevatorWidget;
class UNewWorkbenchWidget;
class UOwConversationInstance;
class UPauseMenuWidget;
class UPetListMenu;
class URPGExaminableWidget;
class URadialContextMenuWidget;
class USaveLoadMenuWidget;
class USettingsMenuWidget;
class USkipInteractionAnimationWidget;
class USlideshowWidget;
class USoundMix;
class USubtitleManagerWidget;
class UTechArtDebugWidget;
class UTexture2D;
class UTitleCardDataAsset;
class UTitleCardWidget;
class UToolTipContainerWidget;
class UToolTipContentWidget;
class UTutorialPopupWidget;
class UVendorComponent;
class UVendorWidget;
class UWaitTimeWidget;

UCLASS(Blueprintable, NonTransient)
class ARKANSAS_API AIndianaUI : public AHUD {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSpotterTriggered OnSpotterTriggered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UHUDWidget> HUDClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ULedgerWidget> LedgerWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInventoryWidget> InventoryWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPauseMenuWidget> PauseMenuWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDownedMenuWidget> DownedMenuWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuWidget> SettingsMenuWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UConversationWidget> ConversationWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UConversationSubtitleWidget> ConversationSubtitleWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USlideshowWidget> SlideshowWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UComputerTerminalWidget> ComputerTerminalWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemContainerWidget> ItemContainerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ULevelUpNotificationWidget> LevelUpNotificationClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDebugOverlayWidget> DebugOverlayWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URadialContextMenuWidget> ContextMenuClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemInspectorWidget> ItemInspectorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UNewWorkbenchWidget> NewWorkbenchClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UVendorWidget> VendorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemTransferWidget> ItemTransferClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UToolTipContainerWidget> ToolTipContainerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogBoxWidget> GenericDialogBoxClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogBoxWidget> MultiOptionDialogBoxClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogWarningBoxWidget> DialogWarningBoxClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogBoxRespecWidget> GenericDialogBoxRespecClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemBreakdownWidget> ItemBreakdownClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMoviePlayerWidget> GenericMoviePlayerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCinematicPlayerWidget> CinematicPlayerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTitleCardWidget* ActiveTitleCard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCinematicFramingWidget* CinematicFramingWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTitleCardWidget> TitleCardClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCinematicFramingWidget> CinematicFramingWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMultifloorElevatorWidget> MultifloorElevatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URPGExaminableWidget> RPGExaminableClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPetListMenu> PetListMenuClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UToolTipContentWidget> GenericItemToolTipClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UToolTipContentWidget> HealthKitToolTipClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UWaitTimeWidget> WaitTimeWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTutorialPopupWidget> TutorialPopupWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTutorialPopupWidget> TutorialCenterScreenWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USubtitleManagerWidget> SubtitleInterfaceClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USaveLoadMenuWidget> SaveLoadClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageTextContainerWidget> DamageTextContainerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCompanionSelectionWidget> CompanionSelectionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Missing32;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Missing64;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Missing128;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Missing256;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowItemInspector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UToolTipContainerWidget* ToolTipContainerWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UIndianaDamageType>> DamageTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArmorComponent* ArmorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AStatusTagActor> StatusTagClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UIndianaItemAudioData* UIItemAudioData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVendorComponent* ActiveVendorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* RestrictedAreaMaterialCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollectionInstance* CollectionInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UTexture2D>> DebugOverlays;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugOverlayWidget* DebugOverlayWidget;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDebugMenuWidget> DebugMenuWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTechArtDebugWidget> DebugTechArtWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDebugCharacterLoader> DebugCharacterLoaderClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USkipInteractionAnimationWidget> SkipInteractionAnimationWidgetClass;
    
public:
    AIndianaUI(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Exec)
    void ToggleTechArtWidget();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleSafeSpace();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleResurrect();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleDebugMenu();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ToggleDamageTextVisibility();
    
    UFUNCTION(BlueprintCallable)
    void SubtitleFontSizeModifierChanged(int32 ModifierIn);
    
    UFUNCTION(BlueprintCallable, Exec)
    void StartWorkbench();
    
    UFUNCTION(BlueprintCallable)
    static void ShowItemUsedOnDisplay(TSubclassOf<UItem> ItemIn);
    
    UFUNCTION(BlueprintCallable)
    static void ShowItemOnDisplay(TSubclassOf<UItem> ItemIn, int32 ItemCount, const FText OptionalItemName);
    
    UFUNCTION(BlueprintCallable)
    void SetSoundMixVolume(USoundMix* SoundMix, float Volume);
    
    UFUNCTION(BlueprintCallable)
    void SetHudVisible(bool bNewVisible);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSubtitleManagerInstance(USubtitleManagerWidget* ManagerWidget);
    
    UFUNCTION(BlueprintCallable, Exec)
    void OverlayCycle();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPlayerTargettedChanged(const bool bAdded);
    
    UFUNCTION(BlueprintCallable)
    void OnInteractableModified(const FInteractionDescription& Description);
    
    UFUNCTION(BlueprintCallable)
    void OnConversationStarted(UOwConversationInstance* ConversationInstance);
    
    UFUNCTION(BlueprintCallable)
    void OnConversationFadeToBlackStarted(UOwConversationInstance* ConversationInstance, EPresentationModeCameraFadeType FadeType);
    
    UFUNCTION(BlueprintCallable)
    void OnConversationFadeInStarted(UOwConversationInstance* ConversationInstance, EPresentationModeCameraFadeType FadeType);
    
    UFUNCTION(BlueprintCallable)
    void OnConversationEnded(UOwConversationInstance* ConversationInstance);
    
public:
    UFUNCTION(BlueprintCallable)
    void HideNpcOnMinimap(AIndianaAiCharacter* AICharacter, bool bHideNPC);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UIndianaInterfaceUserWidget* GetUserWidget(ECheckBranches& Branches, TSubclassOf<UIndianaInterfaceUserWidget> WidgetClass) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USlideshowWidget* GetSlideshowWidget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UHUDWidget* GetHUD() const;
    
    UFUNCTION(BlueprintCallable)
    void FontSizeModifierChanged(int32 ModifierIn);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugSetFontScaling(int32 ModifierIn);
    
    UFUNCTION(BlueprintCallable, Exec)
    void DebugCharacterLoader();
    
    UFUNCTION(BlueprintCallable)
    static void CreateTitleCard(UTitleCardDataAsset* DataAsset);
    
    UFUNCTION(BlueprintCallable)
    void CreatePetList(APetKennel* CurrentPetKennel);
    
    UFUNCTION(BlueprintCallable)
    UMoviePlayerWidget* CreateGenericMoviePlayer(bool bPauseGameDuringPlayback);
    
    UFUNCTION(BlueprintCallable)
    void CreateExaminable(const FLocString& NameString, const FLocString& DescriptionString, const FLocString& ActionString, const FName& RemoteEventOnExaminationEnd);
    
    UFUNCTION(BlueprintCallable)
    UCinematicPlayerWidget* CreateCinematicPlayer();
    
    UFUNCTION(BlueprintCallable)
    UIndianaInterfaceUserWidget* ConstructUserWidget(ECheckBranches& Branches, TSubclassOf<UIndianaInterfaceUserWidget> WidgetClass);
    
    UFUNCTION(BlueprintCallable)
    void CloseWorkbench();
    
    UFUNCTION(BlueprintCallable)
    static void CloseTitleCard();
    
    UFUNCTION(BlueprintCallable)
    void CloseGenericMoviePlayer();
    
};

