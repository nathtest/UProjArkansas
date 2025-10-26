#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "InteractionEventBase.h"
#include "LogicalExpression.h"
#include "RPGInteractableRequirements.h"
#include "InteractionEvent.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API UInteractionEvent : public UInteractionEventBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRPGInteractableRequirements RPGRequirements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString InteractString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicalExpression LogicalExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanOnlyBeUsedOnce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartUsed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequiresFrontFacing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequiresBackFacing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableCanOnlyUseOnceOnExecute;
    
public:
    UInteractionEvent();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEventEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEventBegin();
    
};

