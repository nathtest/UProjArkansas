#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include <LocString.h>
#include "EInteractionType.h"
#include "InteractPayload.h"
#include "InteractionDescription.h"
#include "InteractionInterface.generated.h"

class AIndianaCharacter;

UINTERFACE(Blueprintable, MinimalAPI)
class UInteractionInterface : public UInterface {
    GENERATED_BODY()
};

class IInteractionInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FLocString GetInteractLocString() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<EInteractionType> GetInteractions(const FInteractionDescription& Description, float InteractDistance) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    EInteractionType GetInteraction(const FInteractionDescription& Description, const FInteractPayload& Payload, float InteractDistance) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanInteract(AIndianaCharacter* Initiator, const FInteractPayload& Payload) const;
    
};

