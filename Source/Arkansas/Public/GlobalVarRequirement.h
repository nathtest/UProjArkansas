#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include <GlobalVariableReference.h>
#include <LocString.h>
#include "InteractableRequirement.h"
#include "GlobalVarRequirement.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UGlobalVarRequirement : public UInteractableRequirement {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 VariableValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableReference ExternalVariableValueID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString DisplayString;
    
public:
    UGlobalVarRequirement();

};

