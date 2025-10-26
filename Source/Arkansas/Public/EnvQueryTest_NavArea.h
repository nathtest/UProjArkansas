#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_NavArea.generated.h"

class UNavArea;

UCLASS(Blueprintable)
class UEnvQueryTest_NavArea : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSubclassOf<UNavArea>> NavAreaClasses;
    
public:
    UEnvQueryTest_NavArea();

};

