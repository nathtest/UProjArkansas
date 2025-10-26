#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include <GameplayTagContainer.h>
#include "OEICrowdManager.h"

#include "CrimResponseDataLoaded.h"
#include "OwCrowdManager.generated.h"

UCLASS(Blueprintable, NonTransient)
class ARKANSAS_API AOwCrowdManager : public AOEICrowdManager {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FCrimResponseDataLoaded> StationaryCrimeResponseData;
    
    AOwCrowdManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    static void MarkProxiesAroundLocationUsable(FVector Location, float Radius, bool Usable);
    
    UFUNCTION(BlueprintCallable)
    static void MarkProxiesAroundCapsuleUsable(FVector Start, FVector End, float Radius, bool Usable);
    
    UFUNCTION(BlueprintCallable)
    static void MakeCrowdCharactersFleeFromLocation(FVector Location, float Radius);
    
    UFUNCTION(BlueprintCallable)
    static void MakeCrowdCharactersFleeFromCapsule(FVector Start, FVector End, float Radius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float K2_GetTimeSinceCrowdLastWitnessedCrime(bool& bValid);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float K2_GetTimeSinceCrowdLastDetectedPlayer(bool& bValid);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FGuid K2_GetCrowdLastWitnessedCrimeID();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector K2_GetCrowdLastDetectedPlayerLocation(bool& bValid);
    
};

