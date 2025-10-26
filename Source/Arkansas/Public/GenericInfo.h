#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "GenericInfo.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FGenericInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Image;
    
    ARKANSAS_API FGenericInfo();
};

