#pragma once
#include "CoreMinimal.h"
#include "FakeGIActor.h"

#include "OwFakeGIActor.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API AOwFakeGIActor : public AFakeGIActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableTODColorCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableTODIntensityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFakeGILightVisibleInReflectionCaptures;
    
    AOwFakeGIActor(const FObjectInitializer& ObjectInitializer);

};

