#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct 
{
    int nEqs;
    char **odeEqs;
    int *odeICs;
    int nSubs;
    char **parametersSub;
    char independentVariable;
    char derivativeIdentifier;
} odeSys;

typedef struct
{
    char *derivativeSub;
    char timeStepName;
    double timeStep;
    char abscissaIdentifier;
    char independentVariable;
    char derivativeIdentifier;
} finiteDifferenceMethod;

typedef struct
{
    int nEqs;
    double *algEqs;
} algSys;

void printOdeSys( odeSys sysToPrint );
void odeNumericalConverter( odeSys symbolicSys, finiteDifferenceMethod method, algSys *numericSys );
void getParameterSubValues( char *str, char *name, double *value );
void setParameterSubValues( odeSys *sys, char *sub );
void numToString( char *castedValue, double *source );
void applySubValues( odeSys *symbolicSys );
void replaceSubstring( char *fullStr, char *origStr, char *replacementString, char *fullStrNew, size_t charDiff );
void setOde( odeSys *sys, char *sub );