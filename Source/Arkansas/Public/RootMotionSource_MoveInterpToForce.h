#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RootMotionSource_MoveToForce -FallbackName=RootMotionSource_MoveToForce
#include "GameFramework/RootMotionSource.h"

#include "EInterpolationType.h"
#include "RootMotionSource_MoveInterpToForce.generated.h"

USTRUCT(BlueprintType)
struct ARKANSAS_API FRootMotionSource_MoveInterpToForce : public FRootMotionSource_MoveToForce {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInterpolationType InterpolationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpExp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InterpSteps;
    
    FRootMotionSource_MoveInterpToForce();
};

