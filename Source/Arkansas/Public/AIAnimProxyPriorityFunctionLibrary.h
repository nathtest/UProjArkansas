#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include "AIAnimProxyFinishedScriptDelegateDelegate.h"
#include "AIAnimProxyPostMoveScriptDelegateDelegate.h"
#include "AIAnimProxyStartedScriptDelegateDelegate.h"
#include "EAIMovementState.h"
#include "EPriorityNodeValue.h"
#include "PriorityNodeFunctionLibrary.h"
#include "PriorityNodeHandle.h"
#include "AIAnimProxyPriorityFunctionLibrary.generated.h"

class AAnimationProxyActor;
class AIndianaAiController;

UCLASS(Blueprintable)
class ARKANSAS_API UAIAnimProxyPriorityFunctionLibrary : public UPriorityNodeFunctionLibrary {
    GENERATED_BODY()
public:
    UAIAnimProxyPriorityFunctionLibrary();

    UFUNCTION(BlueprintCallable)
    static FPriorityNodeHandle UseAnimationProxy(AIndianaAiController* Controller, EPriorityNodeValue Priority, AAnimationProxyActor* AnimationProxyActor, const FGameplayTag SlotKey, const bool bReserve, const bool bStartInWaiting, const bool bTeleport, const bool bTeleportOnMoveFail, const bool bInterruptOnMove, const bool bInfiniteDuration, const bool bAutoDeactivate, const EAIMovementState MovementState, FAIAnimProxyStartedScriptDelegate AnimProxyStarted, FAIAnimProxyFinishedScriptDelegate AnimProxyFinished, FAIAnimProxyPostMoveScriptDelegate AnimProxyPostMove, int32 NavigationFlags);
    
    UFUNCTION(BlueprintCallable)
    static FPriorityNodeHandle DisableAnimationProxyUse(AIndianaAiController* Controller, EPriorityNodeValue Priority);
    
};

