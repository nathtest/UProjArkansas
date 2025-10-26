#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "EventListener.h"
#include "OnPartyChange.generated.h"

class AIndianaAiCharacter;

UCLASS(Blueprintable, EditInlineNew)
class UOnPartyChange : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumCompanions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
public:
    UOnPartyChange();

protected:
    UFUNCTION(BlueprintCallable)
    void OnPartyChanged(AIndianaAiCharacter* Companion, bool bAdded) const;
    
};

