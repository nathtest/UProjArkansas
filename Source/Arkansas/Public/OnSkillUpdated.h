#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "ESkill.h"
#include "EventListener.h"
#include "OnSkillUpdated.generated.h"

class UCharacterInfoComponent;

UCLASS(Blueprintable, EditInlineNew)
class UOnSkillUpdated : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkill ListenSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCompare;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SkillValue;
    
public:
    UOnSkillUpdated();

protected:
    UFUNCTION(BlueprintCallable)
    void OnSkillUpdated(UCharacterInfoComponent* InCharacterInfoComponent, ESkill Skill, int32 NewValue);
    
};

