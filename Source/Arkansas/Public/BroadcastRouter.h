#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "DeviceType.h"
#include "BroadcastRouter.generated.h"

class ADynamicEmitterVolume;
class UAkComponent;
class UObsidianIDComponent;

UCLASS(Blueprintable)
class ARKANSAS_API ABroadcastRouter : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDeviceType> DeviceTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* AkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObsidianIDComponent* IDComponent;
    
public:
    ABroadcastRouter(const FObjectInitializer& ObjectInitializer);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bShouldSaveGameState;

protected:
    UFUNCTION(BlueprintCallable)
    void RemoveActorFromDevice(AActor* Actor, ADynamicEmitterVolume* Volume);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<bool> GetSavedDevicesEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetEnabledByDeviceIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void EnableBroadcastRouterByDeviceIndex(bool bEnabled, int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void EnableBroadcastRouter();
    
    UFUNCTION(BlueprintCallable)
    void DisableBroadcastRouter();
    
protected:
    UFUNCTION(BlueprintCallable)
    void AddActorToDevice(AActor* Actor, ADynamicEmitterVolume* Volume);
    
};

