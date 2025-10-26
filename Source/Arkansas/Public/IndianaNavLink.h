#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <AI/Navigation/NavAgentSelector.h>
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=NavRelevantInterface -FallbackName=NavRelevantInterface
#include <AI/Navigation/NavLinkDefinition.h>

#include "IndianaNavLink.generated.h"

class UNavLinkProfile;

UCLASS(Abstract, Blueprintable)
class ARKANSAS_API AIndianaNavLink : public AActor, public INavRelevantInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNavigationLink> NavLinks;
    
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavAgentSelector SupportedAgents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UNavLinkProfile*> NavLinkProfiles;
    
public:
    AIndianaNavLink(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

