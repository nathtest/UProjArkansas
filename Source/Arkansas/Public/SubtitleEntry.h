#pragma once
#include "CoreMinimal.h"
#include <EOEIGender.h>
#include <LocString.h>
#include "MiniTimeSpan.h"
#include "SubtitleEntry.generated.h"

USTRUCT(BlueprintType)
struct FSubtitleEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DebugName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMiniTimeSpan StartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMiniTimeSpan EndTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString NameString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SubtitleStringID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOEIGender Gender;
    
    ARKANSAS_API FSubtitleEntry();
};

