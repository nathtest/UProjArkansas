#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "SettingPlatformStringContainer.generated.h"

USTRUCT(BlueprintType)
struct FSettingPlatformStringContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Description;
    
    ARKANSAS_API FSettingPlatformStringContainer();
};

