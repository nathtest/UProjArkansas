#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "EOnHealthPercentageTarget.h"
#include "ESpecialObsidianID.h"
#include "EventListener.h"
#include "OnHealthPercentage.generated.h"

class AActor;
class AIndianaCharacter;
class UHealthComponent;

UCLASS(Blueprintable, EditInlineNew)
class UOnHealthPercentage : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOnHealthPercentageTarget HealthTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpecialObsidianID CompanionID;
    
public:
    UOnHealthPercentage();

protected:
    UFUNCTION(BlueprintCallable)
    void OnHealthChanged(UHealthComponent* InHealthComponent, float PrevNormalizedHealth, float CurrNormalizedHealth, AActor* Instigator);
    
    UFUNCTION(BlueprintCallable)
    AIndianaCharacter* GetHealthTargetActor(AActor* InActor) const;
    
};

