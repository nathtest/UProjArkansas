#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "OEICrowdVolume.h"

#include "ConditionalCrowdValues.h"
#include "Templates/SubclassOf.h"
#include "OWCrowdVolume.generated.h"

class UTeamData;

UCLASS(Blueprintable)
class AOWCrowdVolume : public AOEICrowdVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTeamData> TeamDataForCrowdCharacters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConditionalCrowdValues> Conditionals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumberOfAnimProxiesInVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExpectedNumberOfCrowdNPCs;
    
    AOWCrowdVolume(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ContainsPoint(FVector Point, float Radius);
    
};

