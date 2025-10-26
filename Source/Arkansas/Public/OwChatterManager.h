#pragma once
#include "CoreMinimal.h"
#include <ChatterEventReference.h>
#include "ChatterManager.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIFlowCharts -ObjectName=ChatterNavigator -FallbackName=ChatterNavigator
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIFlowCharts -ObjectName=ChatterNode -FallbackName=ChatterNode

#include "OwChatterManager.generated.h"

class AIndianaCharacter;

UCLASS(Blueprintable)
class UOwChatterManager : public UChatterManager {
    GENERATED_BODY()
public:
    UOwChatterManager();

protected:
    UFUNCTION(BlueprintCallable)
    static void StartRepeatingChatter(AIndianaCharacter* Speaker, const FChatterEventReference& ChatterEventReference, float IntervalMin, float IntervalMax, int32 Param1, int32 Param2, int32 Param3, int32 Param4);
    
    UFUNCTION(BlueprintCallable)
    void OnChatterNodeEntered(const FChatterNavigator& ChatterNavigator, const FChatterNode& ChatterNode);
    
    UFUNCTION(BlueprintCallable)
    static void EndRepeatingChatter(AIndianaCharacter* Speaker, const FChatterEventReference& ChatterEventReference);
    
};

