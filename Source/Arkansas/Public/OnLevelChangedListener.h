#pragma once
#include "CoreMinimal.h"
#include <EComparisonOperator.h>
#include "EventListener.h"
#include "OnLevelChangedListener.generated.h"

class UCharacterInfoComponent;

UCLASS(Blueprintable, EditInlineNew)
class UOnLevelChangedListener : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparisonOperator Operator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EventLevel;
    
public:
    UOnLevelChangedListener();

protected:
    UFUNCTION(BlueprintCallable)
    void OnLevelChanged(UCharacterInfoComponent* InCharacterInfoComponent, int32 Level);
    
};

