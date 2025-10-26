#pragma once
#include "CoreMinimal.h"
#include "AI/Navigation/AvoidanceManager.h"
#include "AI/Navigation/NavEdgeProviderInterface.h"

#include "IndianaAvoidanceManager.generated.h"

UCLASS(Blueprintable)
class UIndianaAvoidanceManager : public UAvoidanceManager, public INavEdgeProviderInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AvoidanceSweepMaxSampleCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvoidanceSweepDeltaAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AvoidanceSweepMinDeltaAngleFromDesiredVelocity;
    
public:
    UIndianaAvoidanceManager();


    // Fix for true pure virtual functions not being implemented
};

