#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "OwTaskDebugPrint.generated.h"

UCLASS(Blueprintable)
class UOwTaskDebugPrint : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Text;
    
    UOwTaskDebugPrint();

};

