#include "EnvQueryTest_EncounterSpace.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

UEnvQueryTest_EncounterSpace::UEnvQueryTest_EncounterSpace() {
    this->TestPurpose = EEnvTestPurpose::Filter;
    this->FilterType = EEnvTestFilterType::Match;
    this->ScoringEquation = EEnvTestScoreEquation::Constant;
    this->EncounterContext = UEnvQueryContext_Querier::StaticClass();
}


