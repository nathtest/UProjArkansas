#pragma once
#include "CoreMinimal.h"
#include <EQuestType.h>
#include "IndianaUserWidget.h"
#include "QuestIconImage.generated.h"

class UImage;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ARKANSAS_API UQuestIconImage : public UIndianaUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EQuestType, float> QuestTypeIndexes;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseStaticInits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowAsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowAsArea;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowAsCompact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowAsPulsing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActiveParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AreaParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CompactParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CompleteParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FailedParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InvalidParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OptionalParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PulsingParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TravelParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName QuestTypeParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float QuestIconOverrideValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* QuestIcon;
    
public:
    UQuestIconImage();

    UFUNCTION(BlueprintCallable)
    void SetIsTravel(bool bIsTravel);
    
    UFUNCTION(BlueprintCallable)
    void SetIsPulsing(bool bIsPulsing);
    
    UFUNCTION(BlueprintCallable)
    void SetIsOptional(bool bIsOptional);
    
    UFUNCTION(BlueprintCallable)
    void SetIsInvalid(bool bIsInvalid);
    
    UFUNCTION(BlueprintCallable)
    void SetIsFailed(bool bIsFailed);
    
    UFUNCTION(BlueprintCallable)
    void SetIsComplete(bool bIsComplete);
    
    UFUNCTION(BlueprintCallable)
    void SetIsCompact(bool bIsCompact);
    
    UFUNCTION(BlueprintCallable)
    void SetIsArea(bool bIsArea);
    
    UFUNCTION(BlueprintCallable)
    void SetIsActive(bool bIsActive);
    
};

