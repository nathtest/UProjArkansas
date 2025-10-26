#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "ObservationGate.h"
#include "ObservationInfo.generated.h"

USTRUCT(BlueprintType)
struct FObservationInfo {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString PersonalityString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObservationGate ObservationGate;
    
public:
    ARKANSAS_API FObservationInfo();
};

