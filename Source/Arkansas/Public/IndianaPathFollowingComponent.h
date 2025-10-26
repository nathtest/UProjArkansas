#pragma once
#include "CoreMinimal.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIPossessable.h"
#include "ETraverseType.h"
#include "IndianaPathFollowingComponent.generated.h"

class ALadder;
class AReservableNavLink;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UIndianaPathFollowingComponent : public UPathFollowingComponent, public IAIPossessable {
    GENERATED_BODY()
public:
    UIndianaPathFollowingComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnNavLinkTraversalStarted(ETraverseType TraverseType, int32 NavLinkDirection, AReservableNavLink* ReservableNavLink, ALadder* ClimbLadder);
    
    UFUNCTION(BlueprintCallable)
    void OnCapsuleSizeChange();
    
    UFUNCTION(BlueprintCallable)
    void EndStationaryRotate();
    

    // Fix for true pure virtual functions not being implemented
};

