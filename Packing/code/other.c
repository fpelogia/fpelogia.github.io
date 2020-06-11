#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// gcc -O3 other.c -L/home/fpelogia/algencan/lib -lalgencan -lgfortran -lm -o algencan




void c_algencan(void *myevalf, void *myevalg, void *myevalh, void *myevalc,
  void *myevaljac, void *myevalhc, void *myevalfc, void *myevalgjac,
  void *myevalgjacp, void *myevalhl, void *myevalhlp, int jcnnzmax,
        int hnnzmax,double *epsfeas, double *epsopt, double *efstin,
  double *eostin, double *efacc, double *eoacc, char *outputfnm,
  char *specfnm, int nvparam,char **vparam, int n, double *x,
  double *l, double *u, int m, double *lambda, _Bool *equatn,
  _Bool *linear, _Bool *coded, _Bool checkder, double *f,
  double *cnorm, double *snorm, double *nlpsupn,int *inform);

double dist(double* x, int x1, int y1, int x2, int y2 ){
  return pow(pow(x[x1] - x[x2],2) + pow(x[y1] - x[y2],2) , 0.5);

}

/* ******************************************************************
   ****************************************************************** */

void myevalf(int n, double *x, double *f, int *flag) {
   *f = 0;
   *flag = 0;
}

/* ******************************************************************
   ****************************************************************** */

void myevalg(int n, double *x, double *g, int *flag) {
   *flag = -1;
   // *g = -1;
}

/* ******************************************************************
   ****************************************************************** */

void myevalh(int n, double *x, int *hrow, int *hcol, double *hval, int *hnnz,
       int lim, _Bool *lmem, int *flag) {
   *flag = -1;
   // *hrow = 0;
   // *hcol = 0;
   // *hval = 0;
}

/* ******************************************************************
   ****************************************************************** */

void myevalc(int n, double *x, int ind, double *c, int *flag) {

   *flag = 0;
   if ( ind == 0 ){
      *c = x[8] - (pow(x[0] - x[2],2) + pow(x[1] - x[3],2));
   }else if(ind ==1){
      *c = x[8] - (pow(x[0] - x[4],2) + pow(x[1] - x[5],2));
   }else if(ind ==2){
      *c = x[8] - (pow(x[0] - x[6],2) + pow(x[1] - x[7],2));
   }else if(ind ==3){
      *c = x[8] - (pow(x[2] - x[4],2) + pow(x[3] - x[5],2));
   }else if(ind ==4){
      *c = x[8] - (pow(x[2] - x[6],2) + pow(x[3] - x[7],2));
   }else if(ind ==5){
      *c = x[8] - (pow(x[4] - x[6],2) + pow(x[5] - x[7],2));
   }
   else
     *flag = -1;
}

/* ******************************************************************
   ****************************************************************** */

void myevaljac(int n, double *x, int ind, int *jcvar, double *jcval,
         int *jcnnz, int lim, _Bool *lmem, int *flag) {

   *flag = -1;
   // *lmem = 0;

   // if ( ind == 0 ) {
   //   *jcnnz = 5;

   //   if( *jcnnz > lim ) {
   //     *lmem = 1;
   //     return;
   //   }

   //   jcvar[0] = 0;
   //   jcval[0] = -2.0 * x[0] + 2.0*x[2];

   //   jcvar[1] = 1;
   //   jcval[1] = -2.0 * x[1] + 2.0*x[3];

   //   jcvar[2] = 2;
   //   jcval[2] = -2.0 * x[2] + 2.0*x[0];

   //   jcvar[3] = 3;
   //   jcval[3] = -2.0 * x[3] + 2.0*x[1];

   //   jcvar[4] = 8;
   //   jcval[4] = 1.0 - (pow(x[0] - x[2],2) + pow(x[1] - x[3],2));

   // }
   // else if ( ind == 1 ) {
   //   *jcnnz = 5;

   //   if( *jcnnz > lim ) {
   //     *lmem = 1;
   //     return;
   //   }

   //   jcvar[0] = 0;
   //   jcval[0] = -2.0 * x[0] + 2.0*x[4];

   //   jcvar[1] = 1;
   //   jcval[1] = -2.0 * x[1] + 2.0*x[5];

   //   jcvar[2] = 2;
   //   jcval[2] = -2.0 * x[4] + 2.0*x[0];

   //   jcvar[3] = 3;
   //   jcval[3] = -2.0 * x[5] + 2.0*x[1];

   //   jcvar[4] = 8;
   //   jcval[4] = 1.0 - (pow(x[0] - x[4],2) + pow(x[1] - x[5],2));

   // }else if ( ind == 2 ) {
   //   *jcnnz = 5;

   //   if( *jcnnz > lim ) {
   //     *lmem = 1;
   //     return;
   //   }

   //   jcvar[0] = 0;
   //   jcval[0] = -2.0 * x[0] + 2.0*x[6];

   //   jcvar[1] = 1;
   //   jcval[1] = -2.0 * x[1] + 2.0*x[7];

   //   jcvar[2] = 2;
   //   jcval[2] = -2.0 * x[6] + 2.0*x[0];

   //   jcvar[3] = 3;
   //   jcval[3] = -2.0 * x[7] + 2.0*x[1];

   //   jcvar[4] = 8;
   //   jcval[4] = 1.0 - (pow(x[0] - x[6],2) + pow(x[1] - x[7],2));

   // }else if ( ind == 3 ) {
   //   *jcnnz = 5;

   //   if( *jcnnz > lim ) {
   //     *lmem = 1;
   //     return;
   //   }

   //   jcvar[0] = 0;
   //   jcval[0] = -2.0 * x[2] + 2.0*x[4];

   //   jcvar[1] = 1;
   //   jcval[1] = -2.0 * x[3] + 2.0*x[5];

   //   jcvar[2] = 2;
   //   jcval[2] = -2.0 * x[4] + 2.0*x[2];

   //   jcvar[3] = 3;
   //   jcval[3] = -2.0 * x[5] + 2.0*x[3];

   //   jcvar[4] = 8;
   //   jcval[4] = 1.0 - (pow(x[2] - x[4],2) + pow(x[3] - x[5],2));

   // }else if ( ind == 4 ) {
   //   *jcnnz = 5;

   //   if( *jcnnz > lim ) {
   //     *lmem = 1;
   //     return;
   //   }

   //   jcvar[0] = 0;
   //   jcval[0] = -2.0 * x[2] + 2.0*x[6];

   //   jcvar[1] = 1;
   //   jcval[1] = -2.0 * x[3] + 2.0*x[7];

   //   jcvar[2] = 2;
   //   jcval[2] = -2.0 * x[6] + 2.0*x[2];

   //   jcvar[3] = 3;
   //   jcval[3] = -2.0 * x[7] + 2.0*x[2];

   //   jcvar[4] = 8;
   //   jcval[4] = 1.0 - (pow(x[2] - x[6],2) + pow(x[3] - x[7],2));

   // }else if ( ind == 5 ) {
   //   *jcnnz = 5;

   //   if( *jcnnz > lim ) {
   //     *lmem = 1;
   //     return;
   //   }

   //   jcvar[0] = 0;
   //   jcval[0] = -2.0 * x[4] + 2.0*x[6];

   //   jcvar[1] = 1;
   //   jcval[1] = -2.0 * x[5] + 2.0*x[7];

   //   jcvar[2] = 2;
   //   jcval[2] = -2.0 * x[6] + 2.0*x[4];

   //   jcvar[3] = 3;
   //   jcval[3] = -2.0 * x[7] + 2.0*x[5];

   //   jcvar[4] = 8;
   //   jcval[4] = 1.0 - (pow(x[4] - x[6],2) + pow(x[5] - x[7],2));

   // }else{
   //     *flag = -1;
   // }
}

/* ******************************************************************
   ****************************************************************** */

void myevalhc(int n, double *x, int ind, int *hcrow, int *hccol, double *hcval,
        int *hcnnz, int lim, _Bool *lmem, int *flag) {
   *flag = -1;
}

/* *****************************************************************
   ***************************************************************** */

void myevalfc(int n, double *x, double *f, int m, double *c, int *flag) {

   *flag = -1;
}

/* *****************************************************************
   ***************************************************************** */

void myevalgjac(int n, double *x, double *g, int m, int *jcfun, int *jcvar,
    double *jcval, int *jcnnz, int lim, _Bool *lmem, int *flag) {

   *flag = -1;
}

/* *****************************************************************
   ***************************************************************** */

void myevalgjacp(int n, double *x, double *g, int m, double *p, double *q,
     char work, _Bool *gotj, int *flag) {

   *flag = -1;
}

/* *****************************************************************
   ***************************************************************** */

void myevalhl(int n, double *x, int m, double *lambda, double scalef,
        double *scalec, int *hlrow, int *hlcol, double *hlval,
        int *hlnnz, int lim, _Bool *lmem, int *flag) {

   *flag = -1;
}

/* *****************************************************************
   ***************************************************************** */

void myevalhlp(int n, double *x, int m, double *lambda, double scalef,
         double *scalec, double *p, double *hp, _Bool *goth, 
         int *flag) {

   *flag = -1;
}

/* ******************************************************************
   ****************************************************************** */

int main(int argc, char const *argv[]) {
  _Bool  checkder;
  int    hnnzmax,hnnzmax1,hnnzmax2,hnnzmax3,i,jcnnzmax,inform,m,n,nvparam,ncomp;
  double cnorm,efacc,efstin,eoacc,eostin,epsfeas,epsopt,f,nlpsupn,snorm;
  
  char   *specfnm, *outputfnm, **vparam;
  _Bool  coded[11],*equatn,*linear;
  double *l,*lambda,*u,*x;

  n = 8;
  m = 6;
  
  /* Memory allocation */
  x      = (double *) malloc(n * sizeof(double));
  l      = (double *) malloc(n * sizeof(double));
  u      = (double *) malloc(n * sizeof(double));
  lambda = (double *) malloc(m * sizeof(double));
  equatn = (_Bool  *) malloc(m * sizeof(_Bool ));
  linear = (_Bool  *) malloc(m * sizeof(_Bool ));
  
  if (     x == NULL ||      l == NULL ||      u == NULL ||
      lambda == NULL || equatn == NULL || linear == NULL ) {
    
    printf( "\nC ERROR IN MAIN PROGRAM: It was not possible to allocate memory.\n" );
    exit( 0 );
    
  }

  /* Initial point */
  //for(i = 0; i < n; i++) x[i] = 0.0;

  if(argc < 1){
    printf( "\nC ERROR IN MAIN PROGRAM: Not enough input data.\n" );
  }else{
    x[0] = atof(argv[3]);
    x[1] = atof(argv[4]);

    x[2] = atof(argv[5]);
    x[3] = atof(argv[6]);

    x[4] = atof(argv[7]);
    x[5] = atof(argv[8]);

    x[6] = atof(argv[9]);
    x[7] = atof(argv[10]);



    /* Lower and upper bounds */
    l[0] = 1.0; u[0] = atof(argv[1]) - 1.0;
    l[1] = 1.0; u[1] = atof(argv[2]) - 1.0;
    l[2] = 1.0; u[2] = atof(argv[1]) - 1.0;
    l[3] = 1.0; u[3] = atof(argv[2]) - 1.0;
    l[4] = 1.0; u[4] = atof(argv[1]) - 1.0;
    l[5] = 1.0; u[5] = atof(argv[2]) - 1.0;
    l[6] = 1.0; u[6] = atof(argv[1]) - 1.0;
    l[7] = 1.0; u[7] = atof(argv[2]) - 1.0;
  }




  /* For each constraint i, set equatn[i] = 1. if it is an equality
     constraint of the form c_i(x) = 0, and set equatn[i] = 0 if it is
     an inequality constraint of the form c_i(x) <= 0. */
  equatn[0] = 0;
  equatn[1] = 0;
  equatn[2] = 0;
  equatn[3] = 0;
  equatn[4] = 0;
  equatn[5] = 0;

  /* For each constraint i, set linear[i] = 1 if it is a linear
     constraint, otherwise set linear[i] = 0 */
  linear[0] = 0;
  linear[1] = 0;
  linear[2] = 0;
  linear[3] = 0;
  linear[4] = 0;
  linear[5] = 0;
  
  
  /* Lagrange multipliers approximation. */
  for( i = 0; i < m; i++ ) lambda[i] = 0.0;
  
  /* In this C interface evalf, evalg, evalh, evalc, evaljac and
     evalhc are present. evalfc, evalgjac, evalhl and evalhlp are
     not. */
  
  coded[0]  = 1; /* fsub     */
  coded[1]  = 0; /* gsub     */
  coded[2]  = 0; /* hsub     */
  coded[3]  = 1; /* csub     */
  coded[4]  = 0; /* jacsub   */
  coded[5]  = 0; /* hcsub    */
  coded[6]  = 0; /* fcsub    */
  coded[7]  = 0; /* gjacsub  */
  coded[8]  = 0; /* gjacpsub */
  coded[9]  = 0; /* hlsub    */
  coded[10] = 0; /* hlpsub   */
 
  /* Upper bounds on the number of sparse-matrices non-null
     elements */
  jcnnzmax = 30;
  // hnnzmax1 = 0;
  // hnnzmax2 = 1;
  // hnnzmax3 = 6;
  // hnnzmax  = hnnzmax1 + hnnzmax2 + hnnzmax3;

  /* Check derivatives? */
  checkder = 0;

  /* Parameters setting */
  epsfeas = 1.0e-08;
  epsopt  = 1.0e-08;
  efstin  = sqrt( epsfeas );
  eostin  = pow( epsopt, 1.5 );
  efacc   = sqrt( epsfeas );
  eoacc   = sqrt( epsopt );

  outputfnm = "algencan.out";
  specfnm   = "";

  nvparam = 2;
  
  /* Allocates VPARAM array */
  vparam = ( char ** ) malloc( nvparam * sizeof( char * ) );

  /* Set algencan parameters */
  //vparam[0] = "ITERATIONS-OUTPUT-DETAIL 10";  
  vparam[0] = "SOLUTION-FILENAME SOLUTION.TXT";
  vparam[1] = "IGNORE-OBJECTIVE-FUNCTION";

  /* Optimize */
  c_algencan(&myevalf,&myevalg,&myevalh,&myevalc,&myevaljac,&myevalhc,&myevalfc,
       &myevalgjac,&myevalgjacp,&myevalhl,&myevalhlp,jcnnzmax,hnnzmax,
       &epsfeas,&epsopt,&efstin,&eostin,&efacc,&eoacc,outputfnm,specfnm,
       nvparam,vparam,n,x,l,u,m,lambda,equatn,linear,coded,checkder,
       &f,&cnorm,&snorm,&nlpsupn,&inform);

  /* Memory deallocation */
  free(x     );
  free(l     );
  free(u     );
  free(lambda);
  free(equatn);
  free(linear);
}
