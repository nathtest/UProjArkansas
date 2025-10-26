#pragma once
#include "CoreMinimal.h"
#include <GameplayTagContainer.h>
#include <MovieSceneObjectBindingID.h>
#include "MovieSceneAnimProxyPayload.generated.h"

USTRUCT(BlueprintType)
struct ARKANSAS_API FMovieSceneAnimProxyPayload {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AnimProxyTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneObjectBindingID AnimProxyInteractableBinding;
    
public:
    FMovieSceneAnimProxyPayload();
};

