#pragma once

#include "../std_lib_facilities.h"
#include "tokenClass.h"

#include "grammar.h"

tValType getExpression(void);
tValType getTerm(void);
tValType getPrimary(void);

const tValType ERR_VALUE = 0.0;