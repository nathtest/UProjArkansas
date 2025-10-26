#pragma once
#include "CoreMinimal.h"
#include <GlobalVariableConditional.h>
#include "BlueprintFunctionLibraryConditional.h"
#include "CompanionStateConditional.h"
#include "DataAssetConditional.h"
#include "EConditionalType.h"
#include "KillOnSightConditional.h"
#include "LogicalStatement.h"
#include "PCGenderConditional.h"
#include "QuestStateConditional.h"
#include "LogicalExpression.generated.h"

USTRUCT(BlueprintType)
struct FLogicalExpression {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EConditionalType ConditionalType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalVariableConditional BaseCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestStateConditional BaseQuestStateCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompanionStateConditional BaseCompanionStateCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPCGenderConditional BasePCGenderCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataAssetConditional BaseDataAssetCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FKillOnSightConditional BaseKillOnSightCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintFunctionLibraryConditional BaseBlueprintFunctionLibraryCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLogicalStatement> AdditionalConditions;
    
    ARKANSAS_API FLogicalExpression();
};

