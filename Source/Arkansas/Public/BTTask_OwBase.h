#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
#include "OwBaseTaskStreamingState.h"
#include "BTTask_OwBase.generated.h"

UCLASS(Abstract, Blueprintable)
class UBTTask_OwBase : public UBTTaskNode {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid Guid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOwBaseTaskStreamingState StreamingState;
    
public:
    UBTTask_OwBase();

};

