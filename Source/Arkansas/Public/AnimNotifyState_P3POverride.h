#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "P3PAnimOverrideSettings.h"
#include "AnimNotifyState_P3POverride.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_P3POverride : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FP3PAnimOverrideSettings Settings;
    
    UAnimNotifyState_P3POverride();

};

