#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ENavLinkDirection -FallbackName=ENavLinkDirection
#include <AI/Navigation/NavAgentSelector.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=NavLinkId -FallbackName=NavLinkId
#include "NavLinkCustomInterface.h"

#include "CustomNavLinkBase.generated.h"

class UNavLinkProfile;

UCLASS(Abstract, Blueprintable)
class UCustomNavLinkBase : public UObject, public INavLinkCustomInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UNavLinkProfile>> NavLinkProfilePtrs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Left;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Right;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavAgentSelector SupportedAgents;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavLinkId NavLinkId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ENavLinkDirection::Type> Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoubleJumpRestricted;
    
public:
    UCustomNavLinkBase();


    // Fix for true pure virtual functions not being implemented
};

