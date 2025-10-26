#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "EPlatformFamily.h"
#include "ESettingSubcategory.h"
#include "SettingPlatformStringContainer.h"
#include "SettingPlatformStringReplacementText.h"
#include "SettingDescription.generated.h"

USTRUCT(BlueprintType)
struct FSettingDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlatformFamily, FSettingPlatformStringReplacementText> DescriptionStringReplacementOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESettingSubcategory SubCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlatformFamily, FSettingPlatformStringContainer> PlatformOverrides;
    
    ARKANSAS_API FSettingDescription();
};

