#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"

#include "BTService_CoverDeploy.generated.h"

UCLASS(Blueprintable)
class UBTService_CoverDeploy : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCoverDeploy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyIfFriends;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitForTurn;
    
    UBTService_CoverDeploy();

};

