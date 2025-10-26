#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include <LocString.h>
#include "ENotificationIconOverride.h"
#include "NotificationHelpers.generated.h"

UCLASS(Blueprintable)
class UNotificationHelpers : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UNotificationHelpers();

    UFUNCTION(BlueprintCallable)
    static void ShowGoldenShroudBitsLost(int32 BitCount);
    
    UFUNCTION(BlueprintCallable)
    static void ShowGenericNotification(FLocString String, ENotificationIconOverride OverrideIcon);
    
};

