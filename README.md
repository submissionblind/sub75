# Supplements for submission 75
This repository contains:
* The source code of the WDSat solver, modified to include the new CNF module.
* Input files used for benchmarks.

The ```mq_benchmarks``` folder contains the 100 instances for each parameter set used to obtain results in Table 4, in all three forms: CNF, CNF-XOR and ANF.

The ```mq_benchmarks``` folder contains the 100 instances for each parameter set used to obtain results in Table 5, in ANF form.

CNF files start with ```CNF``` and end with ```.dimacs```. CNF-XOR files start with ```m``` and end with ```.dimacs```. ANF files start with ```m```and end with ```.anf```. For each instance, there is also a file ending with ```.sol``` that holds the correct solution to the Boolean polynomial system that the instance was derived from. 

## Instructions from WDSat documentation:
### Dependencies
WDSat is built from scratch and has no particular dependencies, apart from the essential tools. 

### Compiling in Linux and Mac OS
```bash
make
```
in the ```src``` folder wil create the ```wdsat_solver``` executable in the root folder.

### Command-line arguments
```
-i file    : where file is the input file
-x : to enable Gaussian Elimination
-g mvc    : where mvc is a string of comma-separated variables that defines statically the branching order
```

### Configuration
The core structures in the different WDSat modules are statically allocated and, currently, several constants need to be set manually in the ```config.h``` file.
* When __\_\_XG_ENHANCED\_\___ is defined, the XORGAUSS-extended module is used for Gaussian Elimination and the input instance has to be in ANF form. (see input forms section)
* When __\_\_FIND_ALL_SOLUTIONS\_\___ is defined, the solver outputs all solutions instead of stopping after the first solution is found, and outputs UNSAT at the end. 
* __\_\_MAX_ANF_ID\_\___ defines the maximum number of unary variables, i.e. variables in the ANF form. Always add +1 to the actual value.
* __\_\_MAX_DEGREE\_\___ defines the maximum degree of the Boolean polynomial systems from which SAT instances are derived. Always add +1 to the actual value.
* __\_\_MAX_ID\_\___ defines the maximum number of variables in the CNF-XOR form, but has to be set even when the given input is in ANF. For goof performance, it is important to set this constant to the exact value. If the estimation is badly made, the solver will alert you at the beginning and will give you the correct value for the current instance. 
* __\_\_MAX_BUFFER_SIZE\_\___ is complicated to estimate. Start with 5000 and increase if not enough (execution will stop immediately, with an appropriate error message).
* __\_\_MAX_EQ\_\___ defines the maximum number of OR-clauses. 
* __\_\_MAX_EQ_SIZE\_\___ defines the maximum size of OR-clauses. Always add +1 to the actual value. This value always corresponds to (__\_\_MAX_DEGREE\_\___ + 1).
* __\_\_MAX_XEQ\_\___ defines the maximum number of XOR-clauses. 
* __\_\_MAX_XEQ_SIZE\_\___ defines the maximum size of XOR-clauses. Be careful, since the size of XOR-clauses can increase when Gaussian Elimination is performed. Try to estimate, or at worst, set to __\_\_MAX_ID\_\___. When this value is underestimated, execution fails, but not necessarily straightaway. 

## Modification to the source code
We have defined the costant __\_\_LONG_OR_CLAUSES\_\___ in ```config.h```. When this constant is defined, the new CNF module is used. We have also added configuration blocks for all parameters used in the paper. The current configuration is for MQ systems with parameters m=50 and n=25, using the XG-ext module. For instance, without any modification to the configuration file, the following execution can be made:

``` ./wdsat_solver -i mq_benchmarks/m50n25_seed0.mq.anf -x ```

This would output the solution followed by the number of conflicts.

Our addition to the ```cnf.c``` code starts on line 376. At our addition to the ```cnf.h``` file starts on line 72.

