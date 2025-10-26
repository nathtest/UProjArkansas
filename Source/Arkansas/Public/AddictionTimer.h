#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OnAddictionTimerEntersMaxedDelegate.h"
#include "OnAddictionTimerLeavesMaxedDelegate.h"
#include "Templates/SubclassOf.h"
#include "AddictionTimer.generated.h"

class UFlaw;

USTRUCT(BlueprintType)
struct FAddictionTimer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AddictionTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimerMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IncreasePerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFlaw> FlawClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAddictionTimerEntersMaxed OnAddictionTimerEntersMaxed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAddictionTimerLeavesMaxed OnAddictionTimerLeavesMaxed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentTimer;
    
public:
    ARKANSAS_API FAddictionTimer();
};

