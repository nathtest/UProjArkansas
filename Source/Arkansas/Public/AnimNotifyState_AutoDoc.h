#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_AutoDoc.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ARKANSAS_API UAnimNotifyState_AutoDoc : public UAnimNotifyState {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InhalerCharges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoDocStartTime;
    
public:
    UAnimNotifyState_AutoDoc();

};

