#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "UIAppearanceData.generated.h"

USTRUCT(BlueprintType)
struct FUIAppearanceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AssetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString CustomizationName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StepSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString CategoryName;
    
    ARKANSAS_API FUIAppearanceData();
};

