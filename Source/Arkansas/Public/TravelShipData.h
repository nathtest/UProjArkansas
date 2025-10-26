#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "TravelShipMapPosition.h"
#include "TravelShipData.generated.h"

class UPointOfInterestData;

USTRUCT(BlueprintType)
struct FTravelShipData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPointOfInterestData* PlayerShipDestinationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTravelShipMapPosition> ShipLocations;
    
    ARKANSAS_API FTravelShipData();
};

