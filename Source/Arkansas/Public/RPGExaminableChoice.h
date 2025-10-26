#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "LogicalExpression.h"
#include "RPGInteractableRequirements.h"
#include "RPGExaminableChoice.generated.h"

class UScriptEvent;

USTRUCT(BlueprintType)
struct ARKANSAS_API FRPGExaminableChoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString OptionalContextString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString ChoiceText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PageIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UScriptEvent*> ScriptEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRPGInteractableRequirements RPGInteractableRequirements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicalExpression LogicalExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideOnConditionalFailure;
    
    FRPGExaminableChoice();
};

