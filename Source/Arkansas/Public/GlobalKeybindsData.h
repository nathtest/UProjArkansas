#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include <LocString.h>
#include "EGamepadLayoutType.h"
#include "EStickLayoutType.h"
#include "GamepadBindingsList.h"
#include "LinkedBinding.h"
#include "GlobalKeybindsData.generated.h"

class UOEIIntegerSetting;

UCLASS(Blueprintable)
class UGlobalKeybindsData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLinkedBinding> LinkedBindings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGamepadLayoutType, FGamepadBindingsList> GamepadBindings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EStickLayoutType, FGamepadBindingsList> LayoutBindings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EStickLayoutType, FGamepadBindingsList> StickLayoutBindings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOEIIntegerSetting* BumperLayoutSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UOEIIntegerSetting* TriggerLayoutSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AllowedBumperLayoutBindings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EStickLayoutType, FGamepadBindingsList> TriggerLayoutBindings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FKey, FLocString> KeyDisplayNameStrings;
    
    UGlobalKeybindsData();

};

