#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlueprintBase.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=EBTNodeResult -FallbackName=EBTNodeResult
#include "OwBehaviorTreeServiceInterface.h"
#include "BTService_OwBlueprintBase.generated.h"

class AIndianaAiController;

UCLASS(Abstract, Blueprintable)
class UBTService_OwBlueprintBase : public UBTService_BlueprintBase, public IOwBehaviorTreeServiceInterface {
    GENERATED_BODY()
public:
    UBTService_OwBlueprintBase();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    EBTNodeResult::Type ReceiveResume(AIndianaAiController* AIController);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePause(AIndianaAiController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void AIDebugPrintTime(const FText Text, int32 Level, float Time);
    
    UFUNCTION(BlueprintCallable)
    void AIDebugPrint(const FText Text, int32 Level);
    

    // Fix for true pure virtual functions not being implemented
};

