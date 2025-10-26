#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include <LocString.h>
#include "ERestrictedAreaState.h"
#include "FactionDataRequirementPair.h"
#include "LogicalExpression.h"
#include "Templates/SubclassOf.h"
#include "RestrictedArea.generated.h"

class AMapFloorVolume;
class ARestrictedAreaSign;
class ARestrictedAreaVolume;
class UObsidianIDComponent;
class UTeamData;

UCLASS(Blueprintable)
class ARKANSAS_API ARestrictedArea : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicalExpression EnabledGlobalVariableExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFactionDataRequirementPair RankRequirement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UTeamData>> IgnoredTeams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString UiDisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AMapFloorVolume> MapFloor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARestrictedAreaVolume*> ContainedVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERestrictedAreaState CurrentAreaState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARestrictedAreaSign*> RestrictedAreaSigns;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MPCName;
    
public:
    ARestrictedArea(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetRestrictedAreaState(ERestrictedAreaState NewState);
    
    UFUNCTION(BlueprintCallable)
    void SetRestrictedAreaAccess(bool bOverrideAccessIn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool PassesRequirement() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEnabled() const;
    
    UFUNCTION(BlueprintCallable)
    ERestrictedAreaState GetRestrictedAreaState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHighestRankRequirement() const;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;
    
};

