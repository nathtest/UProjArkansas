#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "ECarriageWallDir.h"
#include "ElevatorSpeedOverride.h"
#include "RPGInteractableRequirements.h"
#include "ElevatorFloorData.generated.h"

class AElevatorDoor;
class AElevatorSwitch;
class UPointOfInterestData;

USTRUCT(BlueprintType)
struct FElevatorFloorData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MapFloor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AElevatorDoor* ElevatorDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECarriageWallDir CarriageWallDir;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRPGInteractableRequirements Requirements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AElevatorSwitch*> ExternalCallButtons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FElevatorSpeedOverride> SpeedOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPointOfInterestData* TravelDestinationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGroundFloor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowInUI;
    
    ARKANSAS_API FElevatorFloorData();
};

