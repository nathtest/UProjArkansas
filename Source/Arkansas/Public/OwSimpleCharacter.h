#pragma once
#include "CoreMinimal.h"
#include <VoiceOverComponentSetupData.h>
#include "OwBaseCharacter.h"
#include "OwSpeaker.h"
#include "OwSimpleCharacter.generated.h"

class UAkComponent;
class UInteractableComponent;
class UObsidianIDComponent;
class UOwSpeakerInfoComponent;
class USceneComponent;
class USkeletalMeshComponent;

UCLASS(Abstract, Blueprintable)
class ARKANSAS_API AOwSimpleCharacter : public AOwBaseCharacter, public IOwSpeaker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysAllowHighlight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* TPVMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVoiceOverComponentSetupData VoiceOverSetupData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* VoiceOverAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOwSpeakerInfoComponent* SpeakerInfoComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* DynamicFxInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* DynamicFxOutput;
    
public:
    AOwSimpleCharacter(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

