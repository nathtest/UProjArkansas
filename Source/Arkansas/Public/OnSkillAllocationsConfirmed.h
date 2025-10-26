#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "EventListener.h"
#include "OnSkillAllocationsConfirmed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UOnSkillAllocationsConfirmed : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumInvestedSkills;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
public:
    UOnSkillAllocationsConfirmed();

protected:
    UFUNCTION(BlueprintCallable)
    void OnSkillAllocationsConfirmed(int32 NumTotalSkillsInvestedIn) const;
    
};

