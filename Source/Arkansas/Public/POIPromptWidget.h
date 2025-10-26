#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "IndianaUserWidget.h"
#include "NotificationDurations.h"
#include "POIPromptWidget.generated.h"

class UAkAudioEvent;
class UScaleBox;
class UTextBlockBase;
class UWidgetAnimation;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UPOIPromptWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ScaleSettingTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag PromptDurationTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNotificationDurations PromptAnimationScalars;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* DiscoveredSFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlockBase* POINameTextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWidgetAnimation* Intro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UScaleBox* ContainerScaleBox;
    
public:
    UPOIPromptWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnScaleSettingChanged(float NewValue);
    
    UFUNCTION(BlueprintCallable)
    void OnPromptDurationIndexChanged(int32 DurationIn);
    
};

