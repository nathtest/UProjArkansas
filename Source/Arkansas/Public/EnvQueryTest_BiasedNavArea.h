#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Templates/SubclassOf.h"
#include "EnvQueryTest_BiasedNavArea.generated.h"

class UNavArea;

UCLASS(Blueprintable)
class UEnvQueryTest_BiasedNavArea : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSubclassOf<UNavArea>> NavAreaClassesToBias;
    
public:
    UEnvQueryTest_BiasedNavArea();

};

