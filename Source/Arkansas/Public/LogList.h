#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "GenericCollapsableList.h"
#include "LogList.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ULogList : public UGenericCollapsableList {
    GENERATED_BODY()
public:
    ULogList();

protected:
    UFUNCTION(BlueprintCallable)
    void AddNewFoundLog(FLocString ExaminableName, FLocString ExaminableDescription);
    
};

