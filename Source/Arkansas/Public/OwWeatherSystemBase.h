#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include "WeatherSystem.h"
#include "OwWeatherSystemBase.generated.h"

class ACelestialBody;
class AStaticMeshActor;
class UMaterialInterface;
class UTextureRenderTarget2D;
class UTextureRenderTarget2DArray;

UCLASS(Blueprintable)
class ARKANSAS_API AOwWeatherSystemBase : public AWeatherSystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugNativization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* CloudCombinedDensityRT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* CloudEdgeMapRT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* SkyDomeGradientRT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* FogInscatteringLatLongRT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* CelestialLightingLatLongRT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* CelestialLightingCloudsLatLongRT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* SunTwilightAndMoonLatLongAdditiveRT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* SkyCloudOcclusionLatLongRT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* SkyCloudOcclusionAccumulateLatLongRT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* SkyCloudOcclusionIncrementLatLong;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* CloudFakeLightingSliceAdditiveRT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2DArray* CloudFakeLightShadowsRTA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* WriteCombinedDensitiesToTargetMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* WriteCloudEdgesToTargetMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* WriteSkyDomeGradientsMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* WriteTwilightToSunMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* FinalColorSkyCloudContributionMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* TransferAdditiveLightingLatLongMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* WriteCelestialLightingCloudsLatLongMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* WriteMoonsToTargetLatLongMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* WriteFinalColorSkyCloudOcclusion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* TransferAdditiveSkyOcclusionToIntermediateLatLongMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* WriteSkyCloudOcclusionIncrementMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* AccumulateSkyCloudOcclusionToTargetLatLongMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* MasterWriteCloudFakeLightingToTargetArraySliceMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* WriteVolumeSkyOccToTargetArraySliceMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* TransferCloudFakeLightingFromAdditiveMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DaySkyDomeFogContributionMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor NightSkyDomeFogContributionMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor TwilightSkyDomeFogContributionMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumCloudLightingRenderSteps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumCloudSkyOccRenderSteps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumFogSkyOccRenderSteps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MacroTextureTilingDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FogSkyOcclusionRenderIndex;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_bUsePlayerPositionForExponentialHeightFogOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_SunVisibilityDiskAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_SunVisibilitySmoothing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor m_EclipseSkyLuminanceFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AStaticMeshActor* m_Starfield;
    
public:
    AOwWeatherSystemBase(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void WarmupSky(bool bSupportTwilightFakeLighting);
    
    UFUNCTION(BlueprintCallable)
    void UpdateWindOffset(float WindSpeed, float CloudWindSpeed, float WindIncrement);
    
    UFUNCTION(BlueprintCallable)
    void UpdateSunSpecularScale(float SunSpecularScale);
    
    UFUNCTION(BlueprintCallable)
    void UpdateShadowDistanceBySunAngle(float CloudShadowTraceDistance, float CloudShadowTraceDistanceTwilight);
    
    UFUNCTION(BlueprintCallable)
    void UpdateCommonMaterialParams(float TwilightSunInClouds, float TwilightSunInFog, float StarBrightnessDay, float StarBrightnessNight);
    
    UFUNCTION(BlueprintCallable)
    void UpdateAdditiveSkyDome(float SkyDomeIntensityNight, float SkyDomeIntensityDay, float SkyDomeIntensityEclipse, float SkyDomeIntensityTwilight, FLinearColor SkyDomeColorHorizonTwilight, FLinearColor SkyDomeColorHorizonDay, FLinearColor SkyDomeColorHorizonEclipse);
    
    UFUNCTION(BlueprintCallable)
    void ResizeDistanceSunRaysMesh(bool bSunRays, AStaticMeshActor* DistantSunRaysMesh, float SunRaysDistanceDayTime, float SunRaysDistanceTwilight);
    
    UFUNCTION(BlueprintCallable)
    void RenderLatLongTargetsFogSky();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEvalutateTimeOfDay(float TimeOfDayNormalized);
    
    UFUNCTION(BlueprintCallable)
    void MoonSwapLogic(FName MoonTransitionParameter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACelestialBody* GetSunCelestialBody() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACelestialBody* GetPrimarySunCelestialBody() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLightOcclusionPct() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLightOcclusionInfluence() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetInSpacePct() const;
    
    UFUNCTION(BlueprintCallable)
    void DrawTiny2DRenderTargets();
    
    UFUNCTION(BlueprintCallable)
    void DrawIncrementedRenderTargets(bool bSupportTwilightFakeLighting);
    
    UFUNCTION(BlueprintCallable)
    void CPPInitialSetupSteps();
    
};

