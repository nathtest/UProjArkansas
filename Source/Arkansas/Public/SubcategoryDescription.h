#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "EPlatformFamily.h"
#include "SettingPlatformStringContainer.h"
#include "SubcategoryDescription.generated.h"

USTRUCT(BlueprintType)
struct FSubcategoryDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlatformFamily, FSettingPlatformStringContainer> PlatformOverrides;
    
    ARKANSAS_API FSubcategoryDescription();
};

