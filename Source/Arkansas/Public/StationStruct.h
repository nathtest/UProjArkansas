#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "StationAkEvents.h"
#include "StationStruct.generated.h"

class URadioStationDataAsset;

USTRUCT(BlueprintType)
struct FStationStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldStop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag StationTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URadioStationDataAsset* StationDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStationAkEvents StationEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> RecentSongsIndex;
    
    ARKANSAS_API FStationStruct();
};

