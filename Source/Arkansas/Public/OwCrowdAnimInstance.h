#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <AnimationProxyRuntime.h>
#include <BodyIdle.h>
#include <FacialIdle.h>
#include "OEIAnimInstance.h"
#include "OEIMergedCrowdAnimInstance.h"

#include "OwCrowdAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ARKANSAS_API UOwCrowdAnimInstance : public UOEIAnimInstance, public IOEIMergedCrowdAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag CrowdBodyIdlePriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationProxyRuntime AnimProxyRuntime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFacialIdle FacialIdle0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFacialIdle FacialIdle1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBodyIdle BodyIdle0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBodyIdle BodyIdle1;
    
    UOwCrowdAnimInstance();


    // Fix for true pure virtual functions not being implemented
};

