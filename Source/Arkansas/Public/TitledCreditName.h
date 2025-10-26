#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "BasicCreditName.h"
#include "TitledCreditName.generated.h"

USTRUCT(BlueprintType)
struct FTitledCreditName : public FBasicCreditName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TitleLocString;
    
    ARKANSAS_API FTitledCreditName();
};

