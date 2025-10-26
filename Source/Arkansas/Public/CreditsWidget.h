#pragma once
#include "CoreMinimal.h"
#include <GlobalVariableReference.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=ESlateVisibility -FallbackName=ESlateVisibility
#include "CreditsClosedDelegate.h"
#include "IndianaInterfaceUserWidget.h"
#include "Templates/SubclassOf.h"
#include "CreditsWidget.generated.h"

class UCreditsData;
class UCreditsFormattingData;
class UImage;
class UMusicCreditWidget;
class UScrollBox;
class USkipInteractionAnimationWidget;
class UVerticalBox;

UCLASS(Blueprintable, EditInlineNew)
class UCreditsWidget : public UIndianaInterfaceUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCreditsClosed CreditsClosedDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WidgetsPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPausedBlocksWidgetCreation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UCreditsData*> CreditOrganizationAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreditsFormattingData* CreditsFormattingData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMusicCreditWidget> MusicCreditClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESlateVisibility ActiveVisibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESlateVisibility InactiveVisibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference CreditsMusicGlobalVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OnCreditsStartGlobalVariableValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OnCreditsSkippedGlobalVariableValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OnCreditsEndedGlobalVariableValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScrollBox* CreditsScrollBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* CreditsVerticalBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkipInteractionAnimationWidget* SkipAnimationWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* LeftAnchorImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* RightAnchorImage;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UVerticalBox*> ActiveColumns;
    
public:
    UCreditsWidget();

    UFUNCTION(BlueprintCallable)
    void TickCredits_BP(float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void StartCredits_BP();
    
protected:
    UFUNCTION(BlueprintCallable)
    void PauseCredits(bool bIsPaused);
    
    UFUNCTION(BlueprintCallable)
    void BackSelected();
    
};

