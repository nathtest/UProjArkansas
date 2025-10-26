#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "EForcedFirstPersonFlag.h"
#include "IgnoreForcePerspectiveTriggerBox.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API AIgnoreForcePerspectiveTriggerBox : public ATriggerBox {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EForcedFirstPersonFlag FlagToIgnore;
    
public:
    AIgnoreForcePerspectiveTriggerBox(const FObjectInitializer& ObjectInitializer);

};

