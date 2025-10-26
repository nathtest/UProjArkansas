#pragma once
#include "CoreMinimal.h"
#include <ELogicalOperator.h>
#include "LogicalExpression.h"
#include "LogicalExpressionGroup.generated.h"

USTRUCT(BlueprintType)
struct FLogicalExpressionGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELogicalOperator Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicalExpression Expression;
    
    ARKANSAS_API FLogicalExpressionGroup();
};

