#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include <GlobalVariableReference.h>
#include "GlobalVariableModifier.generated.h"

USTRUCT(BlueprintType)
struct FGlobalVariableModifier {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 ModifierAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference GlobalVariable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator ComparisonOperator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GlobalValue;
    
    ARKANSAS_API FGlobalVariableModifier();
};

