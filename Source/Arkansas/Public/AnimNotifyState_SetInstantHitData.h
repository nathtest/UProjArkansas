#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_SetInstantHitData.generated.h"

class UInstantHitData;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimNotifyState_SetInstantHitData : public UAnimNotifyState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UInstantHitData> InstantHitData;
    
public:
    UAnimNotifyState_SetInstantHitData();

};

