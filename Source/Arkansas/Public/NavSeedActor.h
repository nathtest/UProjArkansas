#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <AI/Navigation/NavAgentSelector.h>
#include "NavSeedActor.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API ANavSeedActor : public AActor {
    GENERATED_BODY()
public:
protected:
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavAgentSelector SeededAgents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSeedCompanionNavAgents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInfiniteRadius;
    
public:
    ANavSeedActor(const FObjectInitializer& ObjectInitializer);

};

