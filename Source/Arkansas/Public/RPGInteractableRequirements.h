#pragma once
#include "CoreMinimal.h"
#include <ELogicalOperator.h>
#include "RPGInteractableRequirements.generated.h"

class UInteractableRequirement;

USTRUCT(BlueprintType)
struct ARKANSAS_API FRPGInteractableRequirements {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELogicalOperator LogicalOperator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UInteractableRequirement*> RPGRequirements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowInUI;
    
    FRPGInteractableRequirements();
};

