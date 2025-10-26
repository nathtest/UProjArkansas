#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AnimNotify -FallbackName=AnimNotify
#include <GameplayTagContainer.h>
#include "EAnimationAudioLoopType.h"
#include "Templates/SubclassOf.h"
#include "AnimNotify_AudioEvent.generated.h"

class UAnimationGameplayTagAudio;

UCLASS(Blueprintable, CollapseCategories)
class UAnimNotify_AudioEvent : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Event;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimationAudioLoopType LoopType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimationGameplayTagAudio> AnimationAudio;
    
    UAnimNotify_AudioEvent();

};

