#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "ESetting.h"
#include "IndianaUserWidget.h"
#include "SettingsMenuVisualizerBaseWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class USettingsMenuVisualizerBaseWidget : public UIndianaUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ESetting> SettingsToVisualize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocString> GenericSettingNamesToVisualize;
    
public:
    USettingsMenuVisualizerBaseWidget();

};

