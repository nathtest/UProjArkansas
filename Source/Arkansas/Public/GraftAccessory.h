#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "Accessory.h"
#include "GraftAccessory.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UGraftAccessory : public UAccessory {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GraftType;
    
public:
    UGraftAccessory();

};

