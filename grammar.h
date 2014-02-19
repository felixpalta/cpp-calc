#pragma once

#include "common_types.h"


tValType getExpression(void);
tValType getTerm(void);
tValType getPrimary(void);
tValType getStatement(void);
tValType getDeclaration(void);

const tValType ERR_VALUE = 0.0;