#pragma once
#include "CoreMinimal.h"
#include "LevelSequenceActor.h"

#include "CineCombatSequenceActor.generated.h"

class UCineCombatCameraParams;

UCLASS(Blueprintable)
class ACineCombatSequenceActor : public ALevelSequenceActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCineCombatCameraParams* CameraParams;
    
public:
    ACineCombatSequenceActor(const FObjectInitializer& ObjectInitializer);

};

