#pragma once
#include "CoreMinimal.h"
#include "AnimNotifyState_TimedNiagaraEffect.h"

#include "AnimNotifyState_MappedTimedNiagaraEffect.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_MappedTimedNiagaraEffect : public UAnimNotifyState_TimedNiagaraEffect {
    GENERATED_BODY()
public:
    UAnimNotifyState_MappedTimedNiagaraEffect();

};

