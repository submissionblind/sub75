
//enable the XG-ext module (must use anf as input)
#define __XG_ENHANCED__

//use alternative CNF module because MAX size of clauses > 4
#define __LONG_OR_CLAUSES__

//find all solutions instead of only one
//#define __FIND_ALL_SOLUTIONS__


//outputs some intermediate results for fixing errors
//#define __DEBUG__


/*** static allocation ***/
/// these params should be modified in order to manage
/// more models.

/** MQ : n=25 m=50 **/
#ifdef __XG_ENHANCED__
#define __MAX_ANF_ID__ 26 // make it +1
#define __MAX_DEGREE__ 3 // make it +1
#endif
#define __MAX_ID__ 325
#define __MAX_BUFFER_SIZE__ 10000
#define __MAX_EQ__ 950
#define __MAX_EQ_SIZE__ 4 //make it +1
#define __MAX_XEQ__ 50
#define __MAX_XEQ_SIZE__ 900
#define __MAX_EQ_SIZE_LEN__ 2 // (floor[log2(__MAX_DEGREE__)] + 1
 #define __2_POW_MAX_EQ_SIZE_LEN__ 4


/** MQ : n=30 m=60 **/
/*#ifdef __XG_ENHANCED__
#define __MAX_ANF_ID__ 31 // make it +1
#define __MAX_DEGREE__ 3 // make it +1
#endif
#define __MAX_ID__ 465
#define __MAX_BUFFER_SIZE__ 15000
#define __MAX_EQ__ 1310
#define __MAX_EQ_SIZE__ 4 //make it +1
#define __MAX_XEQ__ 60
#define __MAX_XEQ_SIZE__ 1100
#define __MAX_EQ_SIZE_LEN__ 2 // (floor[log2(__MAX_DEGREE__)] + 1
 #define __2_POW_MAX_EQ_SIZE_LEN__ 4*/

/** MP : d=3 n=20 m=40 **/
/*#ifdef __XG_ENHANCED__
#define __MAX_ANF_ID__ 21 // make it +1
#define __MAX_DEGREE__ 4 // make it +1
#endif
#define __MAX_ID__ 1350
#define __MAX_BUFFER_SIZE__ 80000
#define __MAX_EQ__ 5131
#define __MAX_EQ_SIZE__ 5 //make it +1
#define __MAX_XEQ__ 40
#define __MAX_XEQ_SIZE__ 6000
#define __MAX_EQ_SIZE_LEN__ 3 // (floor[log2(__MAX_DEGREE__)] + 1
 #define __2_POW_MAX_EQ_SIZE_LEN__ 8
*/

/** MP : d=3 n=25 m=50 **/
/*#ifdef __XG_ENHANCED__
#define __MAX_ANF_ID__ 26 // make it +1
#define __MAX_DEGREE__ 4 // make it +1
#endif
#define __MAX_ID__ 2625
#define __MAX_BUFFER_SIZE__ 100000
#define __MAX_EQ__ 10101
#define __MAX_EQ_SIZE__ 5 //make it +1
#define __MAX_XEQ__ 50
#define __MAX_XEQ_SIZE__ 11000
#define __MAX_EQ_SIZE_LEN__ 3 // (floor[log2(__MAX_DEGREE__)] + 1
 #define __2_POW_MAX_EQ_SIZE_LEN__ 8
*/

/** MP : d=4 n=15 m=30 **/
/*#ifdef __XG_ENHANCED__
#define __MAX_ANF_ID__ 16 // make it +1
#define __MAX_DEGREE__ 5 // make it +1
#endif
#define __MAX_ID__ 1940
#define __MAX_BUFFER_SIZE__ 100000
#define __MAX_EQ__ 8961
#define __MAX_EQ_SIZE__ 6 //make it +1
#define __MAX_XEQ__ 30
#define __MAX_XEQ_SIZE__ 2000
#define __MAX_EQ_SIZE_LEN__ 3 // (floor[log2(__MAX_DEGREE__)] + 1
#define __2_POW_MAX_EQ_SIZE_LEN__ 8
*/

/** MP : d=4 n=18 m=36 **/
/*#ifdef __XG_ENHANCED__
#define __MAX_ANF_ID__ 19 // make it +1
#define __MAX_DEGREE__ 5 // make it +1
#endif
#define __MAX_ID__ 4047
#define __MAX_BUFFER_SIZE__ 150000
#define __MAX_EQ__ 19024
#define __MAX_EQ_SIZE__ 6 //make it +1
#define __MAX_XEQ__ 36
#define __MAX_XEQ_SIZE__ 4050
#define __MAX_EQ_SIZE_LEN__ 3 // (floor[log2(__MAX_DEGREE__)] + 1
 #define __2_POW_MAX_EQ_SIZE_LEN__ 8
*/


/*** END static allocation ***/
