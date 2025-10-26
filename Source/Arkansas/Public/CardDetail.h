#pragma once
#include "CoreMinimal.h"
#include <LocString.h>
#include "ETossballTeam.h"
#include "Templates/SubclassOf.h"
#include "CardDetail.generated.h"

class USpell;

USTRUCT(BlueprintType)
struct FCardDetail {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString PlayerName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString TeamName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETossballTeam Team;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocString PlayerDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USpell> CardStatusBonus;
    
    ARKANSAS_API FCardDetail();
};

