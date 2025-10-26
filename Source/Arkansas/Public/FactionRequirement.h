#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "EStandingLevel.h"
#include "EStandingType.h"
#include "InteractableRequirement.h"
#include "Templates/SubclassOf.h"
#include "FactionRequirement.generated.h"

class UFactionData;

UCLASS(Blueprintable, EditInlineNew)
class UFactionRequirement : public UInteractableRequirement {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFactionData> RequiredStandingFaction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStandingType RequiredStandingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStandingLevel RequiredStandingLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator RequiredStandingOperator;
    
public:
    UFactionRequirement();

};

