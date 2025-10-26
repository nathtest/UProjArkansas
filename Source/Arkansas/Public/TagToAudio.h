#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "TagToAudio.generated.h"

class UAkAudioEvent;

USTRUCT(BlueprintType)
struct FTagToAudio {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag PrimaryItemSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* AudioEvent;
    
    ARKANSAS_API FTagToAudio();
};

