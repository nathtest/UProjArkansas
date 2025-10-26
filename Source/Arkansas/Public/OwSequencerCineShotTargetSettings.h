#pragma once
#include "CoreMinimal.h"
#include <MovieSceneObjectBindingID.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=OEICinematics -ObjectName=OEICineShotTargetSettings -FallbackName=OEICineShotTargetSettings
#include "OEICineShotTargetSettings.h"

#include "OwSequencerCineShotTargetSettings.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ARKANSAS_API UOwSequencerCineShotTargetSettings : public UOEICineShotTargetSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneObjectBindingID TargetActorBinding;
    
    UOwSequencerCineShotTargetSettings();

};

