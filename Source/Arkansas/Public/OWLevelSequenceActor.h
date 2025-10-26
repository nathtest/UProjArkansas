#pragma once
#include "CoreMinimal.h"
#include "LevelSequenceActor.h"
#include "OWLevelSequenceActor.generated.h"

UCLASS(Blueprintable)
class AOWLevelSequenceActor : public ALevelSequenceActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnloadDataLayerWhenFinished;
    
public:
    AOWLevelSequenceActor(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnSequenceFinished();
    
};

