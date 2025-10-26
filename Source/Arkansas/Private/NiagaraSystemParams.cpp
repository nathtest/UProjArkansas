#include "NiagaraSystemParams.h"

FNiagaraSystemParams::FNiagaraSystemParams() {
    this->ParamToEdit = ENiagaraSystemParamType::Integer;
    this->Int = 0;
    this->_float = 0.00f;
    this->Object = NULL;
    this->Boolean = false;
}

