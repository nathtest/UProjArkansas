#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=EnvDirection -FallbackName=EnvDirection
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryAngleRange.h"
#include "EnvQueryTest_AngleRangeAroundVector.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class UEnvQueryTest_AngleRangeAroundVector : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvDirection LineA;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnvDirection LineB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnvQueryAngleRange> AngleRangeScores;
    
public:
    UEnvQueryTest_AngleRangeAroundVector();

};

