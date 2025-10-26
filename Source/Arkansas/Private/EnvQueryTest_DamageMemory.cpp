#include "EnvQueryTest_DamageMemory.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

UEnvQueryTest_DamageMemory::UEnvQueryTest_DamageMemory() {
    this->TestPurpose = EEnvTestPurpose::Score;
    this->FilterType = EEnvTestFilterType::Maximum;
    this->ScoringEquation = EEnvTestScoreEquation::InverseLinear;
    this->DamageMemoryContext = UEnvQueryContext_Querier::StaticClass();
}


