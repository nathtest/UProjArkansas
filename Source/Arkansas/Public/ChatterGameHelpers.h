#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include <ChatterEventReference.h>
#include "ChatterGameHelpers.generated.h"

class AActor;

UCLASS(Blueprintable)
class UChatterGameHelpers : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UChatterGameHelpers();

protected:
    UFUNCTION(BlueprintCallable)
    static void PlayChatterEventReference(AActor* Speaker, const FChatterEventReference& ChatterEventReference, int32 Param1, int32 Param2, int32 Param3, int32 Param4);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsChatterEventPlaying(AActor* Speaker, const FGuid& ChatterEvent);
    
};

