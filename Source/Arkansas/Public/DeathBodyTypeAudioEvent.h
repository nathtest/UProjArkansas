#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "DeathBodyTypeAudioEvent.generated.h"

class UAkAudioEvent;

USTRUCT(BlueprintType)
struct FDeathBodyTypeAudioEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag DeathAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* AudioEvent;
    
    ARKANSAS_API FDeathBodyTypeAudioEvent();
};

