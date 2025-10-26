#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "ActionLabelDescription.generated.h"

USTRUCT(BlueprintType)
struct FActionLabelDescription {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisplayKeyboard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisplayGamepad;
    
    ARKANSAS_API FActionLabelDescription();
};

