#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "MapCompassUIVisuals.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FMapCompassUIVisuals {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Texture;
    
    ARKANSAS_API FMapCompassUIVisuals();
};

