#pragma once
#include "CoreMinimal.h"
#include "LevelSequencePlayer.h"
#include "CineCombatSequencePlayer.generated.h"

UCLASS(Blueprintable)
class UCineCombatSequencePlayer : public ULevelSequencePlayer {
    GENERATED_BODY()
public:
    UCineCombatSequencePlayer(const FObjectInitializer& ObjectInitializer);

};

