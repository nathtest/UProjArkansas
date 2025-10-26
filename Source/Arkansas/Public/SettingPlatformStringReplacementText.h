#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "SettingPlatformStringReplacementText.generated.h"

USTRUCT(BlueprintType)
struct FSettingPlatformStringReplacementText {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Token;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString AlternateString;
    
    ARKANSAS_API FSettingPlatformStringReplacementText();
};

