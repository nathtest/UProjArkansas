#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <BodyIdle.h>
#include "SubStateData.generated.h"

class UAnimSequence;
class UAnimSequenceBase;
class UBodyIdleAsset;

USTRUCT(BlueprintType)
struct FSubStateData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBodyIdle DefaultIdle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBodyIdleAsset* DefaultIdleAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, UAnimSequenceBase*> FromSubStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* SequenceFromNeutral;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* SequenceToNeutral;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SkipStartForBodyIdle;
    
    ARKANSAS_API FSubStateData();
};

