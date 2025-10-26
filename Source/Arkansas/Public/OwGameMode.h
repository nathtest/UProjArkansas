#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Templates/SubclassOf.h"
#include "OwGameMode.generated.h"

class AIndianaPlayerCharacter;
class APlayerStart;

UCLASS(Blueprintable, NonTransient)
class AOwGameMode : public AGameMode {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AIndianaPlayerCharacter> CustomPlayerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerStart* CustomPlayerStart;
    
public:
    AOwGameMode(const FObjectInitializer& ObjectInitializer);

};

