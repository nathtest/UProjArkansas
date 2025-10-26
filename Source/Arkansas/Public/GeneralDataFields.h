#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "GeneralDataFields.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FGeneralDataFields {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Image;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Description;
    
public:
    ARKANSAS_API FGeneralDataFields();
};

