#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "ESettingSubcategory.h"
#include "KeybindSettingConfig.generated.h"

USTRUCT(BlueprintType)
struct FKeybindSettingConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESettingSubcategory SubcategoryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    ARKANSAS_API FKeybindSettingConfig();
};

