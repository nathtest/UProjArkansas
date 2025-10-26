#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_AltIKToggle.generated.h"

UCLASS(Blueprintable, CollapseCategories, Deprecated, EditInlineNew, NotPlaceable)
class UDEPRECATED_AnimNotifyState_AltIKToggle : public UAnimNotifyState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseLeft;
    
public:
    UDEPRECATED_AnimNotifyState_AltIKToggle();

};

