#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "EOnShieldPercentageTarget.h"
#include "ESpecialObsidianID.h"
#include "EventListener.h"
#include "OnShieldPercentage.generated.h"

class AActor;
class AIndianaCharacter;
class UHealthComponent;

UCLASS(Blueprintable, EditInlineNew)
class UOnShieldPercentage : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShieldPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOnShieldPercentageTarget ShieldTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpecialObsidianID CompanionID;
    
public:
    UOnShieldPercentage();

protected:
    UFUNCTION(BlueprintCallable)
    void OnShieldChanged(UHealthComponent* InHealthComponent, float PrevNormalizedShield, float CurrNormalizedShield);
    
    UFUNCTION(BlueprintCallable)
    AIndianaCharacter* GetShieldTargetActor(AActor* InActor) const;
    
};

