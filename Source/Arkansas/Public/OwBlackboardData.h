#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardData.h"

#include "BlackboardEntryConfig.h"
#include "OwBlackboardData.generated.h"

UCLASS(Blueprintable, MinimalAPI, Config=Game)
class UOwBlackboardData : public UBlackboardData {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FBlackboardEntryConfig> DefaultKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 PackageDirtyState;
    
public:
    UOwBlackboardData();

};

