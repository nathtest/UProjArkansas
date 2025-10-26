#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_PivotRotation.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API UAnimNotifyState_PivotRotation : public UAnimNotifyState {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* RotationCurve;
    
public:
    UAnimNotifyState_PivotRotation();

};

