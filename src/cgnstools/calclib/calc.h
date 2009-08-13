#ifndef _CALC_H_
#define _CALC_H_

#include <stdio.h>
#include "vecsym.h"

extern int cgnsFile;

/*--- base data ---*/

extern int NumBases, cgnsBase;
extern char BaseName[33];
extern int CellDim, PhyDim;
extern int BaseClass, BaseUnits[5];

/*--- zone data ---*/

extern int NumZones, cgnsZone;
extern char ZoneName[33];
extern int ZoneType, ZoneDims[6];
extern int ZoneClass, ZoneUnits[5];
extern int GridClass, GridUnits[5];

/*--- solution data ---*/

extern int NumSolns, cgnsSoln;
extern char SolnName[33];
extern int SolnLocation;
extern int SolnDims[3], SolnRind[6];
extern int SolnClass, SolnUnits[5];

/*--- solution field data ---*/

typedef struct {
    int units[5];
    float exps[5];
} Units;

typedef struct {
    char name[33];
    int type;
    int id;
    int valid;
    int len;
    int datatype;
    int dataclass;
    int hasunits;
    int units[5];
    int hasconv;
    double dataconv[2];
    int hasexp;
    double exponent[5];
    VECDATA *vd;
} Variable;

/*----- variables -----*/

extern Variable *variables;
extern int NumVariables;

/*----- reference conditions -----*/

extern Variable *reference;
extern int NumReference;

/*----- mesh -----*/

extern Variable *coordinates;
extern int NumCoordinates;

/*----- external functions -----*/

#ifdef EXTERN_FUNCS
extern void add_funcs (
#ifdef PROTOTYPE
    void
#endif
);
#endif

/*----- functions -----*/

void cgnsCalcFatal (     /* terminate with error message */
#ifdef PROTOTYPE
    char *errmsg         /* error message */
#endif
);

void cgnsCalcError (     /* print error message */
#ifdef PROTOTYPE
    char *errmsg         /* error message */
#endif
);

void cgnsCalcReset (     /* reset calculator (symbol table) */
#ifdef PROTOTYPE
    void
#endif
);

int cgnsCalcInit (       /* load CGNS file and initialize */
#ifdef PROTOTYPE
    char *cgnsfile,      /* CGNS file */
    int modify,          /* set for modify mode */
    void (*errhandler)(  /* calculator error callback */
        int errnum,      /* error number */
        char *errmsg,    /* error message */
        int pos,         /* location in string */
        char *str        /* string being parsed */
    )
#endif
);

void cgnsCalcDone (      /* close CGNS file */
#ifdef PROTOTYPE
    void
#endif
);

int cgnsCalcBase (       /* set base for calculations */
#ifdef PROTOTYPE
    int base             /* base number */
#endif
);

int cgnsCalcZone (       /* set zone for calculations */
#ifdef PROTOTYPE
    int zone             /* zone number */
#endif
);

int cgnsCalcSoln (       /* set solution for calculations */
#ifdef PROTOTYPE
    int soln             /* solution number */
#endif
);

int cgnsCalcCheck (      /* parse command and check for errors */
#ifdef PROTOTYPE
    char *expression     /* expression to be parsed */
#endif
);

VECSYM *cgnsCalcCommand (/* parse command string and return results */
#ifdef PROTOTYPE
    char *expression     /* expression to be parsed */
#endif
);

Variable *cgnsCalcVarGet (/* return a variable */
#ifdef PROTOTYPE
    char *varname
#endif
);

void cgnsCalcVarList (   /* print variables */
#ifdef PROTOTYPE
    FILE *fp             /* output file (NULL gives stdout) */
#endif
);

void cgnsCalcSymList (   /* print list of symbols */
#ifdef PROTOTYPE
    FILE *fp             /* output file (NULL gives stdout) */
#endif
);

#endif  /* _CALC_H_ */

