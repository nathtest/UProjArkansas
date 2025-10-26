#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include "CelestialBody.h"

#include "OwCelestialBody.generated.h"

UCLASS(Blueprintable)
class ARKANSAS_API AOwCelestialBody : public ACelestialBody {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor m_AbsoluteColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_CanBeOccluded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor m_OccludedLightColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_OccludedLightMaxBrightness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_LightShaftOcclusionMaskDarkness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_LightShaftBloomScale;
    
public:
    AOwCelestialBody(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEvalutateTimeOfDay(float TimeOfDayNormalized);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetAbsoluteLightColor() const;
    
};

