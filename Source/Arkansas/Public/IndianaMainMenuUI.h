#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "EPlatformFamily.h"
#include "IndianaUI.h"
#include "MovieData.h"
#include "OnFrontEndFlowCompleteDelegate.h"
#include "Templates/SubclassOf.h"
#include "IndianaMainMenuUI.generated.h"

class AIndianaMainMenuUI;
class UDialogBoxWidget;
class UGammaSelectionWidget;
class UMainMenuWidget;
class UMoviePlayerWidget;
class USettingsMenuWidget;
class UShaderPreCacheWidget;

UCLASS(Blueprintable, NonTransient)
class AIndianaMainMenuUI : public AIndianaUI {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFrontEndFlowComplete OnFrontEndFlowComplete;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideAlwaysRunFrontEndFlow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideAlwaysRunFirstTimeFlow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyShowPhotosensitivityInFirstTimeFlow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyShowAutosaveInFirstTimeFlow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMovieData> IntroMovieQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UShaderPreCacheWidget> ShaderPreCacheWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogBoxWidget> PhotosensitivityDialogBoxClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDialogBoxWidget> AutosaveDialogBoxClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString BodyStringFormat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString DefaultSystemName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlatformFamily, FLocString> SystemNamePlatformOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGammaSelectionWidget> GammaSelectionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USettingsMenuWidget> AccessibilityMenuClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMainMenuWidget> MainMenuClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UShaderPreCacheWidget* CachedShaderPreCacheWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMoviePlayerWidget> CachedIntroMoviesWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDialogBoxWidget* CachedFrontEndDialogBoxWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UGammaSelectionWidget* CachedGammaSelectionWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USettingsMenuWidget* CachedAccessibilityMenuWidget;
    
public:
    AIndianaMainMenuUI(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StartFrontEndFlow_BP();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnShaderPreCacheComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnIntroMoviesComplete(bool bWasSkipped);
    
    UFUNCTION(BlueprintCallable)
    void OnGammaSelectionComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnConfirmDialogBoxComplete();
    
    UFUNCTION(BlueprintCallable)
    void OnAccessibilitySettingsComplete();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UMainMenuWidget* GetMainMenuWidget_BP() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AIndianaMainMenuUI* GetMainMenuHUD_BP() const;
    
};

