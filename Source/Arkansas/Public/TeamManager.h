#pragma once
#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "Templates/SubclassOf.h"
#include "TeamManager.generated.h"

class UBaseTeamData;
class UFactionData;
class UTeamData;

UCLASS(Blueprintable)
class UTeamManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UTeamData>, UTeamData*> TeamMap;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, TSubclassOf<UTeamData>> TeamsByLookupHash;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UTeamData>, uint32> TeamsLookupHashes;
    
public:
    UTeamManager();

    UFUNCTION(BlueprintCallable)
    static void BPSetRelationship(TSubclassOf<UBaseTeamData> SourceTeamData, TSubclassOf<UBaseTeamData> OtherTeamData, TEnumAsByte<ETeamAttitude::Type> Relationship, bool bMutual);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<ETeamAttitude::Type> BPGetRelationship(TSubclassOf<UTeamData> SourceTeamData, TSubclassOf<UTeamData> OtherTeamData);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<UFactionData> BPGetFactionDataFromTeam(const TSubclassOf<UTeamData>& TeamData);
    
};

