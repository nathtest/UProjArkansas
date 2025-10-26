#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AnimationCompleteSignatureDelegate.h"
#include "EWidgetOpenState.h"
#include "OnAttentionEventDelegate.h"
#include "IndianaUserWidget.generated.h"

class AIndianaUI;
class UAkStateValue;
class UIndianaWidgetComponent;

UCLASS(Blueprintable, EditInlineNew)
class UIndianaUserWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAttentionEvent OnAttentionEventReceived;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAttentionEvent OnAttentionEventLost;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AssetKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* ActiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkStateValue* InactiveStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopOnlyGameInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRecordFocusHistory;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UIndianaWidgetComponent* OwnerWidgetComponent;
    
public:
    UIndianaUserWidget();

    UFUNCTION(BlueprintCallable)
    void StartMinimize();
    
    UFUNCTION(BlueprintCallable)
    void StartMaximize();
    
    UFUNCTION(BlueprintCallable)
    void StartIntro();
    
    UFUNCTION(BlueprintCallable)
    void SetDefaultUserFocus();
    
    UFUNCTION(BlueprintCallable)
    void RestoreOrSetDefaultUserFocus();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnStartOutroCb();
    
    UFUNCTION(BlueprintCallable)
    void OnStartMinimizeCb();
    
    UFUNCTION(BlueprintCallable)
    void OnStartMaximizeCb();
    
    UFUNCTION(BlueprintCallable)
    void OnStartIntroCb();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnOutro(const FAnimationCompleteSignature& AnimationCompleteCallback);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnMinimize(const FAnimationCompleteSignature& AnimationCompleteCallback);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnMaximize(const FAnimationCompleteSignature& AnimationCompleteCallback);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnIntro(const FAnimationCompleteSignature& AnimationCompleteCallback);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputDeviceChanged(bool bUsingGamepad);
    
    UFUNCTION(BlueprintCallable)
    void OnFinalizeOutroCb();
    
    UFUNCTION(BlueprintCallable)
    void OnFinalizeMinimizeCb();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFinalizeMinimize();
    
    UFUNCTION(BlueprintCallable)
    void OnFinalizeMaximizeCb();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFinalizeMaximize();
    
    UFUNCTION(BlueprintCallable)
    void OnFinalizeIntroCb();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnCounterZero();
    
    UFUNCTION(BlueprintCallable)
    void OnCounterNonZero();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCancelShutdown();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCancelMinimize();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ObjectRefHasReferencers() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsShuttingDown(bool bIncludeTransitioning) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMinimized(bool bIncludeTransitioning) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMaximized(bool bIncludeTransitioning) const;
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EWidgetOpenState GetOpenState() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AIndianaUI* GetIndianaUI() const;
    
};

