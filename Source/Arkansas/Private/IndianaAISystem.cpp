#include "IndianaAISystem.h"

UIndianaAISystem::UIndianaAISystem(
    const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->TokenManager = NULL;
    this->SearchCoordinator = NULL;
}

int32 UIndianaAISystem::GetArkansasAIDebugLevel() {
    return 0;
}

FString UIndianaAISystem::GetArkansasAIDebugKeyword() {
    return TEXT("");
}

int32 UIndianaAISystem::GetAIDebugSearchLevel() {
    return 0;
}

int32 UIndianaAISystem::GetAIDebugNavLevel() {
    return 0;
}


