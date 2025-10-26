#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "EDependentBehaviorType.h"
#include "SettingToBuild.h"
#include "DependentSettingsToBuild.generated.h"

USTRUCT(BlueprintType)
struct FDependentSettingsToBuild {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSettingToBuild> DependentSettingsToBuild;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator DependentConditional;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConditionalValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDependentBehaviorType ConditionalResponse;
    
    ARKANSAS_API FDependentSettingsToBuild();
};

