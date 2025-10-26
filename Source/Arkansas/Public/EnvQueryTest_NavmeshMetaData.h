#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_NavmeshMetaData.generated.h"

UCLASS(Blueprintable, Deprecated, NotPlaceable)
class UDEPRECATED_EnvQueryTest_NavmeshMetaData : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MetaDataAND;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MetaDataOR;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MetaDataNOT;
    
public:
    UDEPRECATED_EnvQueryTest_NavmeshMetaData();

};

