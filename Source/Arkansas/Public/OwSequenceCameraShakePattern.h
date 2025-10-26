#pragma once
#include "CoreMinimal.h"
#include "SequenceCameraShake.h"
#include "OwSequenceCameraShakePattern.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ARKANSAS_API UOwSequenceCameraShakePattern : public USequenceCameraShakePattern {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLoopSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bApplyAsAbsolute;
    
    UOwSequenceCameraShakePattern(const FObjectInitializer& ObjectInitializer);

};

