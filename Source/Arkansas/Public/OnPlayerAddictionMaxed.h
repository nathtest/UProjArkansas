#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "EPlayerAddictionMaxedType.h"
#include "EventListener.h"
#include "OnPlayerAddictionMaxed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UOnPlayerAddictionMaxed : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AddictionTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlayerAddictionMaxedType MaxedType;
    
public:
    UOnPlayerAddictionMaxed();

protected:
    UFUNCTION(BlueprintCallable)
    void OnPlayerAddictionMaxed(FGameplayTag TimerTag);
    
};

