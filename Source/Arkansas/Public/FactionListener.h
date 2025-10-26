#pragma once
#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include <GameplayTagContainer.h>
#include "EventListener.h"
#include "Templates/SubclassOf.h"
#include "FactionListener.generated.h"

class UFactionData;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UFactionListener : public UEventListener {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFactionData> Faction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCheckAttitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETeamAttitude::Type> Attitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CreatureTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CreatureRoles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowInanimateObjects;
    
public:
    UFactionListener();

};

