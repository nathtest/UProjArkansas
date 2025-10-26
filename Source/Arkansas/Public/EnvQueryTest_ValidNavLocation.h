#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_ValidNavLocation.generated.h"

UCLASS(Blueprintable)
class UEnvQueryTest_ValidNavLocation : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NavigationFlags;
    
public:
    UEnvQueryTest_ValidNavLocation();

};

