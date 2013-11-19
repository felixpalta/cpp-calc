#pragma once

#include "../std_lib_facilities.h"
#include "common_types.h"

#include "grammar.h"

tValType getExpression(void);
tValType getTerm(void);
tValType getPrimary(void);
tValType getStatement(void);
tValType getDeclaration(void);

const tValType ERR_VALUE = 0.0;