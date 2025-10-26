#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PoseSnapshot -FallbackName=PoseSnapshot
#include "OEICrowdAnimInstance.h"

#include "CrowdPersonalityAnims.h"
#include "TPVMinAnimInstance.h"
#include "CrowdAnimInstance.generated.h"

class UTPVPersonalitySet;

UCLASS(Blueprintable, NonTransient)
class ARKANSAS_API UCrowdAnimInstance : public UTPVMinAnimInstance, public IOEICrowdAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCrowdPersonalityAnims CrowdPersonalityAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float EyeStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector EyeLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HeadYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HeadPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HeadStrength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTPVPersonalitySet* DefaultPersonality;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTPVPersonalitySet* CurrentPersonality;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPoseSnapshot MergedSnapshot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSnapshotActive;
    
    UCrowdAnimInstance();


    // Fix for true pure virtual functions not being implemented
};

