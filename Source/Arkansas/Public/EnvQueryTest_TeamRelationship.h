#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_TeamRelationship.generated.h"

UCLASS(Blueprintable)
class UEnvQueryTest_TeamRelationship : public UEnvQueryTest {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExcludeSelf;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExcludeSimiliarType;
    
public:
    UEnvQueryTest_TeamRelationship();

};

