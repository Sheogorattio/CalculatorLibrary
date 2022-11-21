#pragma once

#ifndef CALC_API 
	#define CALC_API extern "C" __declspec(dllimport)
#endif

#include<iostream>

CALC_API double dAdd(double a, double b);
CALC_API double dSubstrct(double a, double b);
CALC_API double dMult(double a, double b);
CALC_API double dDiv(double a, double b);
CALC_API char chGetOperation(const char* str);
CALC_API double* dptrGetOperands(const char* str);
CALC_API void CalcBody();