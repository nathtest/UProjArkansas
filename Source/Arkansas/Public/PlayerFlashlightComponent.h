#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "Components/SpotLightComponent.h"
#include "ArmorOffset.h"
#include "EArmorSlot.h"
#include "OnPlayerFlashlightChangeDelegate.h"
#include "Templates/SubclassOf.h"
#include "PlayerFlashlightComponent.generated.h"

class AActor;
class UItem;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ARKANSAS_API UPlayerFlashlightComponent : public USpotLightComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerFlashlightChange OnPlayerFlashlightChange;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> P3PFlashlightClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName P3PFlashlightAttachSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector P3PFlashlightOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FArmorOffset> P3PFlashlightArmorOffsets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* P3PFlashlight;
    
public:
    UPlayerFlashlightComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ToggleFlashlight();
    
    UFUNCTION(BlueprintCallable)
    void SetFlashlightState(bool bIsOn);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPlayerPerspectiveChanged(bool bInThirdPersonPerspective);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerItemEquipped(UItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerConversationChange(AActor* Participant, const FGuid& NavigatorID, bool bEntered);
    
    UFUNCTION(BlueprintCallable)
    void OnArmorUnequipped(EArmorSlot ArmorSlot);
    
};

