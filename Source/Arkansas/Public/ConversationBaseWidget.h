#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "EIndianaUIColorType.h"
#include "EResponseConditionalType.h"
#include "ESpeechAttackType.h"
#include "IndianaInterfaceUserWidget.h"
#include "Templates/SubclassOf.h"
#include "ConversationBaseWidget.generated.h"

class UConversationResponseWidget;
class UTexture2D;
class UVerticalBox;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UConversationBaseWidget : public UIndianaInterfaceUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* InvalidResponses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* ResponsesContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* InvalidResponsesContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UConversationResponseWidget> ResponseWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UConversationResponseWidget*> SelectableResponseWidgets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UConversationResponseWidget*> UnselectableResponseWidgets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EResponseConditionalType, FLocString> MissingRequirementTextDisplayed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EIndianaUIColorType CheckPassedColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EIndianaUIColorType CheckFailedColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EIndianaUIColorType CheckItemColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESpeechAttackType, UTexture2D*> SpeechAttackIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString PrependTradeString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* BribeBonusTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowBonusValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowBonusMath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysShowBonusText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSkipThreshold;
    
public:
    UConversationBaseWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnSkipInputAction();
    
    UFUNCTION(BlueprintCallable)
    void OnResponse9InputAction();
    
    UFUNCTION(BlueprintCallable)
    void OnResponse8InputAction();
    
    UFUNCTION(BlueprintCallable)
    void OnResponse7InputAction();
    
    UFUNCTION(BlueprintCallable)
    void OnResponse6InputAction();
    
    UFUNCTION(BlueprintCallable)
    void OnResponse5InputAction();
    
    UFUNCTION(BlueprintCallable)
    void OnResponse4InputAction();
    
    UFUNCTION(BlueprintCallable)
    void OnResponse3InputAction();
    
    UFUNCTION(BlueprintCallable)
    void OnResponse2InputAction();
    
    UFUNCTION(BlueprintCallable)
    void OnResponse1InputAction();
    
    UFUNCTION(BlueprintCallable)
    void OnPauseInputAction();
    
    UFUNCTION(BlueprintCallable)
    void OnGameplayDebuggerAction();
    
};

