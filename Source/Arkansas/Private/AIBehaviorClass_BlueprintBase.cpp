#include "AIBehaviorClass_BlueprintBase.h"
#include "BehaviorTree\BehaviorTreeTypes.h"

UAIBehaviorClass_BlueprintBase::UAIBehaviorClass_BlueprintBase() {
    this->bNeedsRestartOnResume = true;
    this->TickDeltaTime = 0.00f;
    this->bRestartClassOnResume = true;
    this->BehaviorStartResultSet = false;
    this->BehaviorStartResult = false;
    this->bBehaviorPaused = false;
}

void UAIBehaviorClass_BlueprintBase::K2_SetBlackboardKeyValueAsVector(const FBlackboardKeySelector Key, FVector VectorValue) {
}

void UAIBehaviorClass_BlueprintBase::K2_SetBlackboardKeyValueAsString(const FBlackboardKeySelector Key, const FString& StringValue) {
}

void UAIBehaviorClass_BlueprintBase::K2_SetBlackboardKeyValueAsRotator(const FBlackboardKeySelector Key, FRotator RotatorValue) {
}

void UAIBehaviorClass_BlueprintBase::K2_SetBlackboardKeyValueAsObject(const FBlackboardKeySelector Key, UObject* ObjectValue) {
}

void UAIBehaviorClass_BlueprintBase::K2_SetBlackboardKeyValueAsName(const FBlackboardKeySelector Key, FName NameValue) {
}

void UAIBehaviorClass_BlueprintBase::K2_SetBlackboardKeyValueAsInt(const FBlackboardKeySelector Key, int32 IntValue) {
}

void UAIBehaviorClass_BlueprintBase::K2_SetBlackboardKeyValueAsFloat(const FBlackboardKeySelector Key, float FloatValue) {
}

void UAIBehaviorClass_BlueprintBase::K2_SetBlackboardKeyValueAsEnum(const FBlackboardKeySelector Key, uint8 EnumValue) {
}

void UAIBehaviorClass_BlueprintBase::K2_SetBlackboardKeyValueAsClass(const FBlackboardKeySelector Key, UClass* ClassValue) {
}

void UAIBehaviorClass_BlueprintBase::K2_SetBlackboardKeyValueAsBool(const FBlackboardKeySelector Key, bool BoolValue) {
}

void UAIBehaviorClass_BlueprintBase::K2_SetBehaviorStartResult(const bool bResult) {
}

bool UAIBehaviorClass_BlueprintBase::K2_IsInBehaviorTree() const {
    return false;
}

bool UAIBehaviorClass_BlueprintBase::K2_IsBlackboardKeyVectorValueSet(const FBlackboardKeySelector Key) const {
    return false;
}

bool UAIBehaviorClass_BlueprintBase::K2_IsBlackboardKeySet(const FBlackboardKeySelector Key) const {
    return false;
}

bool UAIBehaviorClass_BlueprintBase::K2_IsBehaviorPaused() const {
    return false;
}

FString UAIBehaviorClass_BlueprintBase::K2_GetRuntimeDescription_Implementation() const {
    return TEXT("");
}

float UAIBehaviorClass_BlueprintBase::K2_GetLatestDeltaTime() const {
    return 0.0f;
}

int32 UAIBehaviorClass_BlueprintBase::K2_GetDebugLevel() const {
    return 0;
}

AIndianaAiController* UAIBehaviorClass_BlueprintBase::K2_GetController() const {
    return NULL;
}

AIndianaAiCharacter* UAIBehaviorClass_BlueprintBase::K2_GetCharacter() const {
    return NULL;
}

FVector UAIBehaviorClass_BlueprintBase::K2_GetBlackboardKeyValueAsVector(const FBlackboardKeySelector Key) const {
    return FVector{};
}

FString UAIBehaviorClass_BlueprintBase::K2_GetBlackboardKeyValueAsString(const FBlackboardKeySelector Key) const {
    return TEXT("");
}

FRotator UAIBehaviorClass_BlueprintBase::K2_GetBlackboardKeyValueAsRotator(const FBlackboardKeySelector Key) const {
    return FRotator{};
}

UObject* UAIBehaviorClass_BlueprintBase::K2_GetBlackboardKeyValueAsObject(const FBlackboardKeySelector Key) const {
    return NULL;
}

FName UAIBehaviorClass_BlueprintBase::K2_GetBlackboardKeyValueAsName(const FBlackboardKeySelector Key) const {
    return NAME_None;
}

int32 UAIBehaviorClass_BlueprintBase::K2_GetBlackboardKeyValueAsInt(const FBlackboardKeySelector Key) const {
    return 0;
}

float UAIBehaviorClass_BlueprintBase::K2_GetBlackboardKeyValueAsFloat(const FBlackboardKeySelector Key) const {
    return 0.0f;
}

uint8 UAIBehaviorClass_BlueprintBase::K2_GetBlackboardKeyValueAsEnum(const FBlackboardKeySelector Key) const {
    return 0;
}

UClass* UAIBehaviorClass_BlueprintBase::K2_GetBlackboardKeyValueAsClass(const FBlackboardKeySelector Key) const {
    return NULL;
}

bool UAIBehaviorClass_BlueprintBase::K2_GetBlackboardKeyValueAsBool(const FBlackboardKeySelector Key) const {
    return false;
}

AActor* UAIBehaviorClass_BlueprintBase::K2_GetBlackboardKeyValueAsActor(const FBlackboardKeySelector Key) const {
    return NULL;
}

UBehaviorTree* UAIBehaviorClass_BlueprintBase::K2_GetBehaviorTree() const {
    return NULL;
}

bool UAIBehaviorClass_BlueprintBase::K2_EvaluateCanAbort_Implementation() {
    return false;
}

void UAIBehaviorClass_BlueprintBase::K2_ClearBlackboardKeyValue(const FBlackboardKeySelector Key) {
}

bool UAIBehaviorClass_BlueprintBase::K2_CheckDebugLevel(int32 Level) const {
    return false;
}









