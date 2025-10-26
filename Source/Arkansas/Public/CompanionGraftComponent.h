#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include <GameplayTagContainer.h>
#include "Templates/SubclassOf.h"
#include "CompanionGraftComponent.generated.h"

class UCompanionAbility;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCompanionGraftComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, TSubclassOf<UCompanionAbility>> CompanionAbilityMap;
    
public:
    UCompanionGraftComponent(const FObjectInitializer& ObjectInitializer);

};

