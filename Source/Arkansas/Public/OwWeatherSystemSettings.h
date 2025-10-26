#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=OEIWeatherSystemRuntime -ObjectName=WeatherSystemSettings -FallbackName=WeatherSystemSettings
#include "WeatherSystemSettings.h"

#include "OwWeatherSystemSettings.generated.h"

UCLASS(Blueprintable, Config=Engine)
class ARKANSAS_API UOwWeatherSystemSettings : public UWeatherSystemSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxActiveCelestialLights;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxActiveCelestialShadowCasters;
    
    UOwWeatherSystemSettings();

};

