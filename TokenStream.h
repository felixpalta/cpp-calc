#pragma once

#include "tokenClass.h"


Token getToken(void);

double getExpression(void);
double getTerm(void);
double getPrimary(void);

const char SUM = '+';
const char SUB = '-';
const char MUL = '*';
const char DIV = '/';
const char MODULO = '%';