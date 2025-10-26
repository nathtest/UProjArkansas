#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "GameplayTagAndEvent.generated.h"

class UAkAudioEvent;

USTRUCT(BlueprintType)
struct FGameplayTagAndEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag TagName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* Event;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FadeTime;
    
    ARKANSAS_API FGameplayTagAndEvent();
};

