#pragma once

#include "tokenClass.h"


Token getToken(void);

tValType getExpression(void);
tValType getTerm(void);
tValType getPrimary(void);

const tValType ERR_VALUE = 0.0;

const tKindType NUMBER = '8';
const tKindType SUM = '+';
const tKindType SUB = '-';
const tKindType MUL = '*';
const tKindType DIV = '/';
const tKindType MODULO = '%';
const tKindType OPEN_BRACE = '(';
const tKindType CLOSE_BRACE = ')';