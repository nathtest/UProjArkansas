#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include <GameplayTagContainer.h>
#include "TutorialTriggerVolume.generated.h"

UCLASS(Blueprintable)
class ATutorialTriggerVolume : public ATriggerVolume {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tutorial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMarkTutorialCompleteTrigger;
    
public:
    ATutorialTriggerVolume(const FObjectInitializer& ObjectInitializer);

};

