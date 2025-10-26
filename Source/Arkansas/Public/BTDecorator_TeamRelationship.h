#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=BlackboardKeySelector -FallbackName=BlackboardKeySelector
#include "GenericTeamAgentInterface.h"
#include "BTDecorator_OwConditionalBase.h"
#include "BTDecorator_TeamRelationship.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API UBTDecorator_TeamRelationship : public UBTDecorator_OwConditionalBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetActorKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETeamAttitude::Type> TargetTeamRelationship;
    
public:
    UBTDecorator_TeamRelationship();

};

