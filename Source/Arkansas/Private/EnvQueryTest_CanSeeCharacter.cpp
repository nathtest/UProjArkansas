#include "EnvQueryTest_CanSeeCharacter.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

UEnvQueryTest_CanSeeCharacter::UEnvQueryTest_CanSeeCharacter() {
    this->FilterType = EEnvTestFilterType::Match;
    this->ScoringEquation = EEnvTestScoreEquation::Constant;
    this->EnemyContext = NULL;
    this->ObserverContext = UEnvQueryContext_Querier::StaticClass();
}


