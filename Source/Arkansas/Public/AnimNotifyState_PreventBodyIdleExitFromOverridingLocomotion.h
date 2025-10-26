#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_PreventBodyIdleExitFromOverridingLocomotion.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_PreventBodyIdleExitFromOverridingLocomotion : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UAnimNotifyState_PreventBodyIdleExitFromOverridingLocomotion();

};

