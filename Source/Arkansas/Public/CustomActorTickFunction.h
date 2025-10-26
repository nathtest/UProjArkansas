#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorTickFunction -FallbackName=ActorTickFunction
#include "CustomActorTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FCustomActorTickFunction /*:  public  FActorTickFunction */ {
    GENERATED_BODY()
public:
    //ARKANSAS_API FCustomActorTickFunction() = default;
};

