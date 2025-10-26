#pragma once
#include "CoreMinimal.h"
#include <SpeakerReference.h>
#include "ETerminalMonitorSpeaker.h"
#include "OwSpeakerInfoComponent.h"
#include "OwTerminalSpeakerInfoComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UOwTerminalSpeakerInfoComponent : public UOwSpeakerInfoComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FSpeakerReference, ETerminalMonitorSpeaker> MonitorSpeakers;
    
public:
    UOwTerminalSpeakerInfoComponent(const FObjectInitializer& ObjectInitializer);

};

