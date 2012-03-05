//Elsa Gonsiorowski
//October 7, 2011
//Rensselaer Polytechnic Institute


//Settings for individual gates


#ifndef _gates_model_h
#define _gates_model_h

#include "ross.h"
#include "run_config.h"

//define logic type and value
typedef int BOOL;
typedef int LOGIC;
#define TRUE (1)
#define FALSE (0)
#define X (-1)
#define Z (2)

#define LOGIC_NOT(x) ((x) + 1) % 2

//message types
#define SOURCE_MSG (0)
#define SETUP_MSG (1)
#define LOGIC_CARY_MSG (2)
#define LOGIC_CALC_MSG (3)
#define SINK_MSG (4)

//sim settings
#define MESSAGE_PAD (0.4)

//Model structs
typedef struct pair_t {
    int gid;
    int value;
} pair;

typedef struct vector_t {
    int size;
    pair array[];
} *vector;

typedef struct {
    int type;
    pair data;
} message;

typedef int (*gate_func)(vector input, vector output);

extern gate_func function_array[];

typedef struct {
    
    //gate specific information
    int gate_type;
    
    //variables for linking gates
    vector inputs;
    vector outputs;
    
    int received_events;
    int calc;
    int stat_output_change;
    
} gate_state;

//Command Line Arguments
extern unsigned int source_interval;
extern unsigned int sink_interval;

//Global vars accessed by main and driver
extern tw_lptype gates_lps[];
extern char global_input[][LINE_LENGTH+1];

//Custom Mapping functions
void gates_custom_mapping(void);
tw_lp * gates_mapping_to_lp(tw_lpid lpid);
tw_peid gates_map(tw_lpid gid);


#endif
