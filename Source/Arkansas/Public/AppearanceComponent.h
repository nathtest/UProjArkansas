#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RuntimeFloatCurve -FallbackName=RuntimeFloatCurve
#include <GameplayTagContainer.h>
#include "AppearanceCustomizations.h"
#include "AppearanceInstance.h"
#include "BodyPart.h"
#include "ComponentDebugInterface.h"
#include "CustomPrimDataModRequest.h"
#include "EMeshTarget.h"
#include "MaterialParamDescription.h"
#include "MaterialParamScalarInterp.h"
#include "OverlayRequest.h"
#include "AppearanceComponent.generated.h"

class UAccessory;
class UAgeWrinkles;
class UAppearancePreset;
class UBeardAppearances;
class UBeardColor;
class UBodyAppearances;
class UBodyPartData;
class UBoneModifications;
class UBoneModificationsPreset;
class UBrows;
class UComplexion;
class UDirt;
class UEquipmentComponent;
class UEyeColor;
class UEyebrowAppearances;
class UEyebrowColor;
class UHairAppearances;
class UHairColor;
class UHeadAppearances;
class UMakeup;
class UMakeupCheeks;
class UMakeupCheeksColor;
class UMakeupEyeliner;
class UMakeupEyelinerColor;
class UMakeupEyeshadow;
class UMakeupEyeshadowColor;
class UMakeupLips;
class UMakeupLipsColor;
class UMaterialInstanceDynamic;
class UMeshComponent;
class UModAppearances;
class UMole;
class UObject;
class UPiercing;
class UPiercingColor;
class UProstheticArmLeft;
class UProstheticArmRight;
class UProstheticLegLeft;
class UProstheticLegRight;
class UScar;
class USkinTone;
class UTattoo;
class UTattooColor;
class UTexture;
class UWeapon;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAppearanceComponent : public UActorComponent, public IComponentDebugInterface {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 ForcedLODIndex;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 MinimumLODIndex;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAppearancePreset* AppearancePreset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag AppearanceGender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UHeadAppearances* DefaultHead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBodyAppearances* DefaultBody;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UModAppearances* AdditionalAppearanceMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableCustomization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAppearanceCustomizations Customization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowUnlimitedBoneMods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBoneModificationsPreset* BoneModPreset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBoneModificationsPreset* UglyStickBoneModPreset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UBoneModifications*, float> BoneModifications;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AppearanceTransitionParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBodyAppearances* CurrentBody;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BodyComponentTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UHeadAppearances* CurrentHead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UModAppearances* CurrentHelmet;
    
    UPROPERTY(EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAccessory* CurrentAccessories[8];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAppearanceInstance> AppearanceInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldCacheAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldCacheEquipmentAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UObject*> CachedAssetSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHelmetVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, bool> RuntimeSetVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FMaterialParamDescription, float> RuntimeSetScalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FMaterialParamDescription, FVector> RuntimeSetVectors;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FMaterialParamDescription, TWeakObjectPtr<UTexture>> RuntimeSetTextures;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FMaterialParamDescription, FMaterialParamScalarInterp> ActiveRuntimeScalarInterps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBodyPartData* BodyPartData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasLimbBreakConstraintSetup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoesntNeedGorecaps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMeshComponent*> AttachedGoreCaps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FOverlayRequest CurrentOverlayRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FOverlayRequest> OverlayRequests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FString> CPDtoRTPCMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCustomPrimDataModRequest> ActiveCustomPrimitiveDataMods;
    
public:
    UAppearanceComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TransitionToNextMatchingBodyAppearance();
    
    UFUNCTION(BlueprintCallable)
    void ShowMaterialSection(FName SlotName, bool bVisible);
    
    UFUNCTION(BlueprintCallable)
    void SetVectorParameterWeapon(FName Parameter, const FVector& Vector);
    
    UFUNCTION(BlueprintCallable)
    void SetVectorParameter(FName Parameter, const FVector& Vector);
    
    UFUNCTION(BlueprintCallable)
    void SetTattooColor(const UTattooColor* NewTattooColor);
    
    UFUNCTION(BlueprintCallable)
    void SetTattoo(const UTattoo* NewTattoo);
    
    UFUNCTION(BlueprintCallable)
    void SetSlotVectorParameterWeapon(FName SlotName, FName Parameter, const FVector& Vector);
    
    UFUNCTION(BlueprintCallable)
    void SetSlotVectorParameter(FName SlotName, FName Parameter, const FVector& Vector);
    
    UFUNCTION(BlueprintCallable)
    void SetSlotTextureParameter(FName SlotName, FName Parameter, UTexture* Texture);
    
    UFUNCTION(BlueprintCallable)
    void SetSlotScalarParameterWeapon(FName SlotName, FName Parameter, float Scalar);
    
    UFUNCTION(BlueprintCallable)
    void SetSlotScalarParameter(FName SlotName, FName Parameter, float Scalar);
    
    UFUNCTION(BlueprintCallable)
    void SetSkinTone(const USkinTone* NewSkinTone);
    
    UFUNCTION(BlueprintCallable)
    void SetScar(const UScar* NewScar);
    
    UFUNCTION(BlueprintCallable)
    void SetScalarParameterWeapon(FName Parameter, float Scalar);
    
    UFUNCTION(BlueprintCallable)
    void SetScalarParameter(FName Parameter, float Scalar);
    
    UFUNCTION(BlueprintCallable)
    void SetRightLegProsthetic(const UProstheticLegRight* NewProsthetic);
    
    UFUNCTION(BlueprintCallable)
    void SetRightArmProsthetic(const UProstheticArmRight* NewProsthetic);
    
    UFUNCTION(BlueprintCallable)
    void SetPiercingColor(const UPiercingColor* NewPiercingColor);
    
    UFUNCTION(BlueprintCallable)
    void SetPiercing(const UPiercing* NewPiercing);
    
    UFUNCTION(BlueprintCallable)
    void SetMole(const UMole* NewMole);
    
    UFUNCTION(BlueprintCallable)
    void SetMakeup(const UMakeup* NewMakeup);
    
    UFUNCTION(BlueprintCallable)
    void SetLipMakeupWeight(float NewLipMakeupWeight);
    
    UFUNCTION(BlueprintCallable)
    void SetLipMakeupColor(const UMakeupLipsColor* NewMakeupColor);
    
    UFUNCTION(BlueprintCallable)
    void SetLipMakeup(const UMakeupLips* NewMakeup);
    
    UFUNCTION(BlueprintCallable)
    void SetLeftLegProsthetic(const UProstheticLegLeft* NewProsthetic);
    
    UFUNCTION(BlueprintCallable)
    void SetLeftArmProsthetic(const UProstheticArmLeft* NewProsthetic);
    
    UFUNCTION(BlueprintCallable)
    void SetHairColor(const UHairColor* NewColor);
    
    UFUNCTION(BlueprintCallable)
    void SetHair(const UHairAppearances* NewHair);
    
    UFUNCTION(BlueprintCallable)
    void SetGender(const FGameplayTag& Gender);
    
    UFUNCTION(BlueprintCallable)
    void SetFrecklesWeight(float NewFrecklesWeight);
    
    UFUNCTION(BlueprintCallable)
    void SetFrecklesSpread(float NewFrecklesSpread);
    
    UFUNCTION(BlueprintCallable)
    void SetEyeshadowMakeupWeight(float NewEyeshadowMakeupWeight);
    
    UFUNCTION(BlueprintCallable)
    void SetEyeshadowMakeupColor(const UMakeupEyeshadowColor* NewMakeupColor);
    
    UFUNCTION(BlueprintCallable)
    void SetEyeshadowMakeup(const UMakeupEyeshadow* NewMakeup);
    
    UFUNCTION(BlueprintCallable)
    void SetEyesDarkCirclesSize(float NewEyesDarkCirclesSize);
    
    UFUNCTION(BlueprintCallable)
    void SetEyelinerMakeupWeight(float NewEyelinerMakeupWeight);
    
    UFUNCTION(BlueprintCallable)
    void SetEyelinerMakeupColor(const UMakeupEyelinerColor* NewMakeupColor);
    
    UFUNCTION(BlueprintCallable)
    void SetEyelinerMakeup(const UMakeupEyeliner* NewMakeup);
    
    UFUNCTION(BlueprintCallable)
    void SetEyeColor(const UEyeColor* NewColor);
    
    UFUNCTION(BlueprintCallable)
    void SetEyebrows(const UEyebrowAppearances* NewEyebrows);
    
    UFUNCTION(BlueprintCallable)
    void SetEyebrowColor(const UEyebrowColor* NewColor);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicWeakSpot(FGameplayTag BodyPart, bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetDirtWeight(float NewDirtWeight);
    
    UFUNCTION(BlueprintCallable)
    void SetDirt(const UDirt* NewDirt);
    
    UFUNCTION(BlueprintCallable)
    void SetDefaultHead(const UHeadAppearances* Head);
    
    UFUNCTION(BlueprintCallable)
    void SetDefaultBody(const UBodyAppearances* Body);
    
    UFUNCTION(BlueprintCallable)
    void SetComplexionWeight(float NewComplexionWeight);
    
    UFUNCTION(BlueprintCallable)
    void SetComplexion(const UComplexion* NewComplexion);
    
    UFUNCTION(BlueprintCallable)
    void SetCheekMakeupWeight(float NewCheekMakeupWeight);
    
    UFUNCTION(BlueprintCallable)
    void SetCheekMakeupColor(const UMakeupCheeksColor* NewMakeupColor);
    
    UFUNCTION(BlueprintCallable)
    void SetCheekMakeup(const UMakeupCheeks* NewMakeup);
    
    UFUNCTION(BlueprintCallable)
    void SetBrows(const UBrows* NewBrows);
    
    UFUNCTION(BlueprintCallable)
    void SetBoneModificationPresets(const UBoneModificationsPreset* Presets);
    
    UFUNCTION(BlueprintCallable)
    void SetBoneModification(const UBoneModifications* Modifications, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetBeardColor(const UBeardColor* NewColor);
    
    UFUNCTION(BlueprintCallable)
    void SetBeard(const UBeardAppearances* NewBeard);
    
    UFUNCTION(BlueprintCallable)
    void SetAgeWrinkles(const UAgeWrinkles* NewAgeWrinkles);
    
    UFUNCTION(BlueprintCallable)
    void SetAge(float NewAge);
    
    UFUNCTION(BlueprintCallable)
    void RemoveBoneModification(const UBoneModifications* Modifications);
    
    UFUNCTION(BlueprintCallable)
    void RefreshFullAppearance();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnWeaponEquipped(UEquipmentComponent* EquipmentComp, UWeapon* EquippedWeapon);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void InvalidateOldBoneModifications() const;
    
    UFUNCTION(BlueprintCallable)
    void InterpolateScalarParameterCurve(FName Parameter, const FRuntimeFloatCurve& Curve);
    
    UFUNCTION(BlueprintCallable)
    void InterpolateScalarParameterConstant(FName Parameter, float InterpDestination, float InterpSpeed, bool bFromCurrentValue, float StartValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasLegsProsthetic() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasActiveScalarParameterInterpolate(FName Parameter) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetWeakSpotFromBone(const FName& BoneName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetWeakSpot(FGameplayTag BodyPart) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetFirstWeakSpotSocketName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UHeadAppearances* GetDefaultHead() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetBreakBoneName(FGameplayTag BodyPartTag, FName& BoneName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetBreakBoneAndSocketNames(FGameplayTag BodyPartTag, FName& BoneName, FName& AttachedSocket, FName& DetachedSocket) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSet<FName> GetBreakableBoneNames() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTag GetBodyType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSet<FGameplayTag> GetBodyPartTags() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FBodyPart> GetBodyPartsArray() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTag GetBodyPart(const FName& BoneName, const FVector& ImpactLocation) const;
    
protected:
    UFUNCTION(BlueprintCallable, Exec)
    void DebugTargetVertexColors();
    
    UFUNCTION(BlueprintCallable)
    void CreateAppearanceInstance(UBodyAppearances* NewBodyAppearance);
    
    UFUNCTION(BlueprintCallable)
    void ApplyOverlay_BP(UMaterialInstanceDynamic* MaterialInstanceDynamic);
    
    UFUNCTION(BlueprintCallable)
    void ApplyCPD_BP(int32 Index, float Value, EMeshTarget MeshTarget);
    
public:
    UFUNCTION(BlueprintCallable)
    void ApplyAppearancePreset(const UAppearancePreset* Preset);
    

    // Fix for true pure virtual functions not being implemented
};

