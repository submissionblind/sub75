#ifndef __cnf_h__
#define __cnf_h__

#include <stdio.h>
#include <stdbool.h>

#include "wdsat_utils.h"

/** original CNF module **/
#ifndef __LONG_OR_CLAUSES__

extern boolean_t cnf_assignment_buffer[__SIGNED_ID_SIZE__];
extern boolean_t *cnf_assignment;

// undo structures
extern int_t cnf_history[__ID_SIZE__];
extern int_t cnf_history_top;
extern int_t cnf_step[__ID_SIZE__];
extern int_t cnf_step_top;


// unit propagation stack
extern int_t cnf_up_stack[__ID_SIZE__];
extern int_t cnf_up_top_stack;


#define _cnf_set(_v, _tv) \
{ \
    cnf_assignment[_v] = (boolean_t) _tv; \
    cnf_assignment[-_v] = (boolean_t) _tv ^ (boolean_t) __TRUE__; \
}

#define _cnf_unset(_v) \
{ \
    cnf_assignment[_v] = cnf_assignment[-_v] = __UNDEF__; \
}

#define _cnf_is_true(_v) (cnf_assignment[_v] & (boolean_t) 1)
#define _cnf_is_false(_v) (!cnf_assignment[_v])
#define _cnf_is_undef(_v) (cnf_assignment[_v] & 2)

/// @def cnf_breakpoint
/// @brief set a breakpoint during resolution
#define _cnf_breakpoint cnf_step[cnf_step_top++] = cnf_history_top;

/// @def cnf_mergepoint
/// @brief merge last pushed context to previous one
#define _cnf_mergepoint cnf_step_top && --cnf_step_top

bool cnf_initiate_from_dimacs(void);
void cnf_fprint(void);
bool cnf_infer(void);
bool cnf_set_true(const int_t l);
void cnf_undo(void);
int_t cnf_last_assigned_breakpoint(int_t *up_stack);
int_t cnf_last_assigned(int_t *up_stack);
const int_t cnf_number_of_assigned_variables(void);
void cnf_occurrence(void);
int_t cnf_occurrence_binary(int_t l);
int_t cnf_occurrence_ternary(int_t l);
bool cnf_set_unitary(void);

/** END original CNF module **/







#else
/** alternative CNF module **/

extern int_t cnf_nb_of_vars;
extern boolean_t cnf_assignment_buffer[__SIGNED_ID_SIZE__];
extern boolean_t *cnf_assignment;

extern int_t cnf_clauses_value[__MAX_EQ__];

// undo structures
extern int_t cnf_history[__ID_SIZE__];
extern int_t cnf_history_top;
extern int_t cnf_step[__ID_SIZE__];
extern int_t cnf_step_top;
extern int_t cnf_clause_step[__ID_SIZE__];
extern int_t cnf_clause_step_top;
extern int_t cnf_history_clauses_value[__ID_SIZE__][__MAX_EQ__];
extern int_t cnf_history_clause_changed[__ID_SIZE__*__MAX_EQ__];
extern int_t cnf_history_clause_changed_top;


// unit propagation stack
extern int_t cnf_up_stack[__ID_SIZE__];
extern int_t cnf_up_top_stack;


#define _cnf_set(_v, _tv) \
{ \
cnf_assignment[_v] = (boolean_t) _tv; \
cnf_assignment[-_v] = (boolean_t) _tv ^ (boolean_t) __TRUE__; \
}

#define _cnf_unset(_v) \
{ \
cnf_assignment[_v] = cnf_assignment[-_v] = __UNDEF__; \
}

#define _cnf_is_true(_v) (cnf_assignment[_v] & (boolean_t) 1)
#define _cnf_is_false(_v) (!cnf_assignment[_v])
#define _cnf_is_undef(_v) (cnf_assignment[_v] & 2)

#define _cnf_cl_val(_c) (cnf_clauses_value[_c] >> (__MAX_EQ_SIZE_LEN__ + 1))
#define _cnf_cl_nb_lit(_c) ((cnf_clauses_value[_c] >> 1) & (__2_POW_MAX_EQ_SIZE_LEN__ - 1))
#define _cnf_cl_is_sat(_c) (cnf_clauses_value[_c] & 1)


/// @def cnf_breakpoint
/// @brief set a breakpoint during resolution
#define _cnf_breakpoint \
{ \
cnf_step[cnf_step_top++] = cnf_history_top; \
cnf_clause_step[cnf_clause_step_top++] = cnf_history_clause_changed_top; \
}

/// @def cnf_mergepoint
/// @brief merge last pushed context to previous one
#define _cnf_mergepoint \
{ \
cnf_step_top && --cnf_step_top; \
cnf_clause_step_top && --cnf_clause_step_top; \
}

bool cnf_initiate_from_dimacs(void);
void cnf_fprint(void);
bool cnf_infer(void);
bool cnf_set_true(const int_t l);
bool cnf_check_set(const int_t l);
void cnf_undo(void);
int_t cnf_last_assigned_breakpoint(int_t *up_stack);
int_t cnf_last_assigned(int_t *up_stack);
const int_t cnf_number_of_assigned_variables(void);
void cnf_cid_output(FILE* datas);
void cnf_initiate_from_datas(int_t *datas);
void cnf_occurrence(void);
void cnf_print_simplify(FILE *dimacs, int_t *shift);
void cnf_fprint_horn(void);
int_t cnf_occurrence_binary(int_t l);
int_t cnf_occurrence_ternary(int_t l);
bool cnf_set_unitary(void);

#endif
/** END alternative CNF module **/


#endif /* cnf_h */
