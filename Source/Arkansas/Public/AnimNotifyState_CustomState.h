#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_CustomState.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API UAnimNotifyState_CustomState : public UAnimNotifyState {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CustomState;
    
public:
    UAnimNotifyState_CustomState();

};

