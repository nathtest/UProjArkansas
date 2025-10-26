#pragma once
#include "CoreMinimal.h"
#include "AnimNotifyState_TimedNiagaraEffect.h"

#include "AnimNotifyState_MappedTimedNiagaraEffectAdvanced.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_MappedTimedNiagaraEffectAdvanced : public UAnimNotifyState_TimedNiagaraEffectAdvanced {
    GENERATED_BODY()
public:
    UAnimNotifyState_MappedTimedNiagaraEffectAdvanced();

};

