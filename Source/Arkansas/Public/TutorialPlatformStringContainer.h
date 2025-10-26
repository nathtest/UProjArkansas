#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "TutorialPlatformStringContainer.generated.h"

USTRUCT(BlueprintType)
struct FTutorialPlatformStringContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Description;
    
    ARKANSAS_API FTutorialPlatformStringContainer();
};

