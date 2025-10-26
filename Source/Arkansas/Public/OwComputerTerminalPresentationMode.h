#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "OEICineShotPresentationMode.h"

#include "ComputerTerminalTransitionData.h"
#include "OwComputerTerminalPresentationMode.generated.h"

class UOEICineShotInterpolator;

UCLASS(Blueprintable)
class UOwComputerTerminalPresentationMode : public UOEICineShotPresentationMode {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComputerTerminalTransitionData DefaultTransitionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TerminalVerticalFieldOfView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FComputerTerminalTransitionData> PerAnimProxyTransitionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOEICineShotInterpolator* ShotInterpolator;
    
public:
    UOwComputerTerminalPresentationMode();

    UFUNCTION(BlueprintCallable)
    void OnAnimProxyStarted();
    
    UFUNCTION(BlueprintCallable)
    void OnAnimProxyPreStart();
    
    UFUNCTION(BlueprintCallable)
    void OnAnimProxyEnded();
    
};

