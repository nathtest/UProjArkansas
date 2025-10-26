#pragma once
#include "CoreMinimal.h"
#include <GlobalVariableConditional.h>
#include <ELogicalOperator.h>

#include "BlueprintFunctionLibraryConditional.h"
#include "CompanionStateConditional.h"
#include "DataAssetConditional.h"
#include "EConditionalType.h"
#include "KillOnSightConditional.h"
#include "PCGenderConditional.h"
#include "QuestStateConditional.h"
#include "LogicalStatement.generated.h"

USTRUCT(BlueprintType)
struct FLogicalStatement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELogicalOperator Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EConditionalType ConditionalType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableConditional Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestStateConditional QuestStateCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompanionStateConditional CompanionStateCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPCGenderConditional PCGenderCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataAssetConditional DataAssetCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FKillOnSightConditional KillOnSightCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintFunctionLibraryConditional BlueprintFunctionLibraryCondition;
    
    ARKANSAS_API FLogicalStatement();
};

