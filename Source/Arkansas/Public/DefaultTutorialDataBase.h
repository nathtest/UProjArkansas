#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "EPlatformFamily.h"
#include "ETutorialDisplayDefaultType.h"
#include "TutorialPlatformStringContainer.h"
#include "DefaultTutorialDataBase.generated.h"

USTRUCT(BlueprintType)
struct FDefaultTutorialDataBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETutorialDisplayDefaultType DisplayDefaultType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TutorialNameString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TutorialBodyString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPlatformFamily, FTutorialPlatformStringContainer> PlatformOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ActionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> ActionNameList;
    
    ARKANSAS_API FDefaultTutorialDataBase();
};

