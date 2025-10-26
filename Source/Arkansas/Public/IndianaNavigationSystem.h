#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "NavigationSystem.h"
#include "EOccupationChannel.h"
#include "IndianaNavigationSystem.generated.h"

class AActor;
class UAnimationProxyData;
class UNavLinkProfile;

UCLASS(Blueprintable, NonTransient, Config=Engine)
class ARKANSAS_API UIndianaNavigationSystem : public UNavigationSystemV1 {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxNavAgentRadiusDiff;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxNavAgentHeightDiff;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxNavAgentStepDiff;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UnusableAgents;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CompanionAgents;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNavLinkProfile> DefaultNavLinkProfile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAnimationProxyData*> PruneNavMeshAnimProxyDataStore;
    
public:
    UIndianaNavigationSystem();

    UFUNCTION(BlueprintCallable)
    static void UnregisterArea(AActor* Source, EOccupationChannel Channel);
    
    UFUNCTION(BlueprintCallable)
    static bool TraceOccupation(AActor* Source, EOccupationChannel Channel, const FVector& Start, const FVector& End);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterArea(AActor* Source, EOccupationChannel Channel, const FVector& Location, const FVector& Extents, const FRotator& Transform);
    
};

