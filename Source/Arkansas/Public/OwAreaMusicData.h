#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIMusic -ObjectName=BackgroundMusic -FallbackName=BackgroundMusic
#include "OEIAreaMusicData.h"

#include "OwAreaMusicData.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API UOwAreaMusicData : public UOEIAreaMusicData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBackgroundMusic> NonCombatThreatMusicStateThresholds;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConsideredDangerousArea;
    
public:
    UOwAreaMusicData();

};

