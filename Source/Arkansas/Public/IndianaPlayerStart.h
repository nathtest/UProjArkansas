#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "GameFrameWork\PlayerStart.h"

#include "IndianaPlayerStart.generated.h"

class UCameraComponent;
class UCapsuleComponent;
class UPointOfInterestData;

UCLASS(Blueprintable)
class ARKANSAS_API AIndianaPlayerStart : public APlayerStart {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* LeftCompanion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* RightCompanion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraComponent* PreviewCam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPointOfInterestData* DestinationPointOfInterestData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPointOfInterestData* FastTravelDestinationPointOfInterestData;
    
public:
    AIndianaPlayerStart(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool GetCompanionSpawnLocation(const FString& CompanionCapsuleName, FVector& Location, FRotator& Rotation, bool bFeetLocation) const;
    
};

