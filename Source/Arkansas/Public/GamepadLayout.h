#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "EPlatformFamily.h"
#include "SettingPlatformStringContainer.h"
#include "GamepadLayout.generated.h"

USTRUCT(BlueprintType)
struct FGamepadLayout {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlatformFamily, FSettingPlatformStringContainer> PlatformOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocString> ButtonNames;
    
    ARKANSAS_API FGamepadLayout();
};

