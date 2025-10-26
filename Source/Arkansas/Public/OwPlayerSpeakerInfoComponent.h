#pragma once
#include "CoreMinimal.h"
#include <EOEIGender.h>
#include "OwSpeakerInfoComponent.h"
#include "OwPlayerSpeakerInfoComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOwPlayerSpeakerInfoComponent : public UOwSpeakerInfoComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOEIGender Gender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PlayerName;
    
public:
    UOwPlayerSpeakerInfoComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, Exec)
    void SetGenderDebug(EOEIGender GenderIn);
    
};

