#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include <EIKGoalTarget.h>
#include "HandIKInfo.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FHandIKInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EIKGoalTarget IKGoalTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference IKTargetComponentReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IKTargetSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IKStrengthCurveName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> PrimitiveComponent;
    
    ARKANSAS_API FHandIKInfo();
};

