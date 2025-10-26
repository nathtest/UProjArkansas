#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_BuffThrowAtFriendlies.generated.h"

UCLASS(Blueprintable)
class UEnvQueryTest_BuffThrowAtFriendlies : public UEnvQueryTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebug;
    
    UEnvQueryTest_BuffThrowAtFriendlies();

};

