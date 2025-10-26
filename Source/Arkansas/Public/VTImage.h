#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Box2f -FallbackName=Box2f
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateBrush -FallbackName=SlateBrush
#include "Components/Widget.h"
#include "VTImage.generated.h"

class UTexture2D;

UCLASS(Blueprintable, MinimalAPI)
class UVTImage : public UWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWidget::FOnPointerEvent OnMouseButtonDownEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Texture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBox2f TextureUVRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VTDisplayScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D VTDisplayOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAbsoluteVTDisplayOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseNormalizedVTDisplayOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D VTDefaultSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D DesiredSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ColorAndOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClipVTToWidgetSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequestVTTilesOnTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush Brush;
    
public:
    UVTImage();

    UFUNCTION(BlueprintCallable)
    void SetVTDisplayScale(float InScale);
    
    UFUNCTION(BlueprintCallable)
    void SetVTDisplayOffset(const FVector2D& InOffset);
    
    UFUNCTION(BlueprintCallable)
    void SetVTDefaultSize(const FVector2D& InSize);
    
    UFUNCTION(BlueprintCallable)
    void SetUseNormalizedVTDsiplayOFfset(bool bInUseNormalizedVTDsiplayOFfset);
    
    UFUNCTION(BlueprintCallable)
    void SetUseAbsoluteVTDsiplayOFfset(bool bInUseAbsoluteVTDsiplayOffset);
    
    UFUNCTION(BlueprintCallable)
    void SetTextureUVRegion(const FBox2f& InUVRegion);
    
    UFUNCTION(BlueprintCallable)
    void SetTexture(UTexture2D* InTexture);
    
    UFUNCTION(BlueprintCallable)
    void SetRequestVTTilesOnTick(bool bInRequestVTTilesOnTick);
    
    UFUNCTION(BlueprintCallable)
    void SetOpacity(float InOpacity);
    
    UFUNCTION(BlueprintCallable)
    void SetDesiredSize(const FVector2D& InSize);
    
    UFUNCTION(BlueprintCallable)
    void SetColorAndOpacity(FLinearColor InColorAndOpacity);
    
    UFUNCTION(BlueprintCallable)
    void SetClipVTToWidgetSize(bool bClip);
    
};

