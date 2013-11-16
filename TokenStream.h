#pragma once

#include "tokenClass.h"


Token getToken(void);

tValType getExpression(void);
tValType getTerm(void);
tValType getPrimary(void);

const tKindType SUM = '+';
const tKindType SUB = '-';
const tKindType MUL = '*';
const tKindType DIV = '/';
const tKindType MODULO = '%';