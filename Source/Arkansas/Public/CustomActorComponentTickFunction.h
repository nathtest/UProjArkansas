#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponentTickFunction -FallbackName=ActorComponentTickFunction
#include "CustomActorComponentTickFunction.generated.h"

USTRUCT(BlueprintType)
struct FCustomActorComponentTickFunction /* : public FActorComponentTickFunction */ {
    GENERATED_BODY()
public:
    //ARKANSAS_API FCustomActorComponentTickFunction() = default;
};

