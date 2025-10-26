#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StasisLogicBaseDataAsset -FallbackName=StasisLogicBaseDataAsset
#include "Engine\StasisLogicBaseDataAsset.h"

#include "LogicalGroupedExpression.h"
#include "StasisLogicDataAsset.generated.h"

UCLASS(Blueprintable)
class UStasisLogicDataAsset : public UStasisLogicBaseDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Comment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRecruitedCompanionStasis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowNonStasisEvenIfCompanionRecruited;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvertStasisConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicalGroupedExpression StasisConditions;
    
    UStasisLogicDataAsset();

};

