#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIFlowCharts -ObjectName=Speaker -FallbackName=Speaker
#include "Speaker.h"

#include "OEIVoiceOverActor.generated.h"

UINTERFACE()
class OEIVOICEOVER_API UOEIVoiceOverActor : public USpeaker {
    GENERATED_BODY()
};

class OEIVOICEOVER_API IOEIVoiceOverActor : public ISpeaker {
    GENERATED_BODY()
public:
};

