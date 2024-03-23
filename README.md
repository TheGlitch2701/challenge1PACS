# Challenge1-PACS-23-24

This repository is for the 1st Challenge of the course at Politecnico di Milano "PACS 2023/2024" regarding the method of ***Gradient Descent***

## 1. Introduction

The goal of this challenge was to build from scratch the code for computing the Gradient Descent Method (GD).
Going into the specific, the goal was to implement the main body of GD, some rate rules related to the updating of the learning rate and to find the minimum of (at least) the following function:

 $$f(x,y) = x_0x_1 + 4x_0^4 + x_1^2 + 3x_0$$ 

but the code I developed is able to compute the minimum (if ever) of any (at least polynomial) function.

Moreover you can see the steps of the GD Method (unfortunately only for function in 2D) if you **firstly load the BOOST module**: ``module load boost`` and then type ``gnuplot plot_script/plot2D`` in your shell.

See **Section 2** for more details on the implementation.

See **Section 3** to see which results can be obtained with the function defined above.

See **Section 4** to see how to reproduce the results in Section 3.

## 2. Implementation

The project Is organised as follow:
- src
- include 
- lib
- doc
- GradientDescent.cpp
- Makefile

### 2.1 Libraries Used

To implement my version of the GD Method, I used the following libraries:

- **GetPot**: library used to read from ``data.txt`` all parameters the code will use;

- **muparserx**: library which lets the user to parse a string into a Mathematical Function if possible and allows to compute the value of this function on a specific point. The main difference, for my purpose, with the library muparser is that the first one lets me work with vectors.

### 2.2 Class Point

I started my process of development defining a Class called Point whose header file contains the following lines:

``

    class Point{ 
        private:
        unsigned int n = 2;
        std::vector<double> points = {0.,0.};

    public:
        Point(unsigned int,std::vector<double> &);
        Point(unsigned int);
        Point(Point &);
        
        void setPoints(const std::vector<double> &);
        void setPoint(const double &, size_t &);
        const std::vector<double>getPoints();
        const unsigned int getN();

        void print() const;
        double norm();
        double distance(Point &, Point &);
        } 

    Point operator-(Point &, Point &);
    Point operator*(double &, Point &); 

``

Its methods were introduced in order to make the computation during the GD Method easier.
In particular I want to focus on ``setPoint(const double &, size_t &)`` and ``setPoints(const std::vector<double> &)``:

- ``setPoints(const std::vector<double> &)`` was firstly introduced to change the points vector all at once, in order to be faster during computation;

- ``setPoint(const double &, size_t &)`` instead was introduced later because during the updating rule for the gradient of the function, it was necessary to change one component (*i.e. variable*) at a time.

### 2.3 Class muparserX_fun

This class was created mainly for the purpose of having a class which can comunicate with the library muparserx. 

In particular it's members are the following:

- ``m_k``: it's the number of variables used in the definition of the function

- ``m_s``: contains the expression of the function which has been parsed by the parser

- ``m_parser``: it's the actual parser from the library muparserx

- ``flag``: is a simple flag that I needed to introduce in order to avoid Segmentation Fault error. The error occurs because when calling ``operator()`` more than one time, after the first one it doesn't work anymore. So I created an if-statement which is execute once in which I define the Variable and the Expression according to the documentation of muparserx (https://beltoforion.de/en/muparserx/index.php)

### 2.4 GradientDescentSolver

You can find both the **Header File GradientDescentSolver.hpp** and the **Source File GradientDescentSolver.cpp** in which you can find all the methods to compute the Gradient Descent of our function.

In particular:

- ``Solver(Point &)``: contains the Gradient Descent Method

- ``exactGradientMethod(...)``: contains the updating steps if the user want to use the gradient defined by himself

- ``finiteDifferencesMethod(...)``: contains the updating steps if the user decided not to use the exact gradient but its approximation with Finite Differences Method

- ``inverseDecay(), exponentialDecay(), lineSearch()``: are simply three rules for the learning rate update *(See doc for further details)*

### 2.5 GradientDescent.cpp

This is the **main file** from which everything starts.

### 2.6 DATA.txt

This file was created to collect all the parameters needed by the Solver in order to do its work. Here I list all of them:

- ``dim``: it expresses how many variables are used to define the function to minimize;

- ``start``: it expresses the starting point of the GD Method. Need to be written between ``' '`` and with a **space** to separate each value;

- ``learning rate``: starting rate for the Gradient's update;

- ``max_it``: maximum number of iterations that the GD Method might perform;

- ``tol_res``: tolerance on the *Gradient Norm Convergence Criteria* *(See doc for further details)*;

- ``tol_step``: tolerance on the *Steps difference Norm Convergence Criteria* *(See doc for further details)*;

- ``rate_rule``: updating rule for the learning rate. Here's the possibility *(See doc for further details)*:
    - ``exponential decay``

    - ``inverse decay``

    - ``line search``

- ``mu``: coefficient used for the ***exponential decay*** and ***inverse decay*** update *(See doc for further details)*;

- ``sigma``: coefficient used for the ***line search*** update *(See doc for furter details)*;

- ``exact``: ``1`` uses the gradient input by the user while ``0`` uses the Finite Differences Method to approximate the value of the gradient;

- ``FDM_type``: if *exact = 0* the user may choose between:
    - ``CD``: Centered Differences Method

    - ``BD``: Backward Differences Method 

    - ``FD``: Forwars Differences Method 

- ``h``: constant used by the FDM to compute the value of the gradient;

- ``fun``: the function to minimize. Need to be written between ``' '`` and each variable with the following rule ``x[i] i in {0, 1, 2, ..., N}``

- ``dfunx0, dfubx1 ...``: the derivative of *fun* w.r.t. *x0, x1, x2, ...*. Of course it is needed to write all of them singularly

## 3. Results

Here I summarize the default value of some parameters of the ``data.txt file`` which I never change during my tests.

Then for every test I ran I'll wirte down the specific parameters that I changed.

### 3.1 Default Parameters

- ``dim = 2``

- ``start = '0 0'``

- ``max_it = 2000``

- ``tol_res = 1e-6``

- ``tol_step = 1e-6``

- ``learning_rate = 0.1``

- ``mu = 0.2``

- ``sigma = 0.45``

- ``h = 1e-6``

- $$f(x,y) = x_0x_1 + 4x_0^4 + x_1^2 + 3x_0$$

- $$\frac{df(x,y)}{dx_0} = x_1 + 16x_0^3 + 3$$

- $$\frac{df(x,y)}{dx_1} = x_0 +2x_1$$

### 3.2 TEST 1

**SPECIFIC PARAMETERS:**

    rate_rule = 'exponential decay' 
    exact = 1 (using user defined gradient)
    FDM_type : irrelevant since exact = 1

**Results:**

    Minimizing the function:

    x[0]*x[1] + 4*x[0]*x[0]*x[0]*x[0] + x[1]*x[1] + 3*x[0]

    using exponential decay and exact gradient.

    Gradient Descent converges in 53 iterations at the minimum: (-0.590551,0.295272)
    Value of the function in the last iteration: -1.37233


### TEST 2

**SPECIFIC PARAMETERS:**

    rate_rule = 'inverse decay' 
    exact = 1 (using user defined gradient)
    FDM_type : irrelevant since exact = 1

**Results:**

    Minimizing the function:

    x[0]*x[1] + 4*x[0]*x[0]*x[0]*x[0] + x[1]*x[1] + 3*x[0]

    using inverse decay and exact gradient.

    Gradient Descent converges in 53 iterations at the minimum: (-0.590551,0.295272)
    Value of the function in the last iteration: -1.37233

### TEST 3

**SPECIFIC PARAMETERS:**

    rate_rule = 'line search' 
    exact = 1 (using user defined gradient)
    FDM_type : irrelevant since exact = 1

**Results:**

    Minimizing the function:

    x[0]*x[1] + 4*x[0]*x[0]*x[0]*x[0] + x[1]*x[1] + 3*x[0]

    using line search and exact gradient.

    Gradient Descent converges in 53 iterations at the minimum: (-0.590551,0.295272)
    Value of the function in the last iteration: -1.37233

### TEST 4

**SPECIFIC PARAMETERS:**

    rate_rule = 'exponential decay' 
    exact = 0 (NOT using user defined gradient)
    FDM_type : 'CD'

**Results:**

    Minimizing the function:

    x[0]*x[1] + 4*x[0]*x[0]*x[0]*x[0] + x[1]*x[1] + 3*x[0]

    using exponential decay and Finite Differences Method for the Gradient: CD.

    Gradient Descent converges in 65 iterations at the minimum: (-0.590551,0.295271)
    Value of the function in the last iteration: -1.37233

### TEST 5

**SPECIFIC PARAMETERS:**

    rate_rule = 'inverse decay' 
    exact = 0 (NOT using user defined gradient)
    FDM_type : 'FD'

**Results:**

    Minimizing the function:

    x[0]*x[1] + 4*x[0]*x[0]*x[0]*x[0] + x[1]*x[1] + 3*x[0]

    using inverse decay and Finite Differences Method for the Gradient: FD.

    Gradient Descent converges in 65 iterations at the minimum: (-0.590551,0.295271)
    Value of the function in the last iteration: -1.37233

### TEST 6

**SPECIFIC PARAMETERS:**

    rate_rule = 'line search' 
    exact = 0 (NOT using user defined gradient)
    FDM_type : 'BD'

**Results:**

    Minimizing the function:

    x[0]*x[1] + 4*x[0]*x[0]*x[0]*x[0] + x[1]*x[1] + 3*x[0]

    using line search and Finite Differences Method for the Gradient: BD.

    Gradient Descent converges in 65 iterations at the minimum: (-0.59055,0.295272)
    Value of the function in the last iteration: -1.37233

## 4. How to reproduce the results

Simply goes into the main directory of the repository and from your shell type ``make`` and it will compile and run the code automatically.

In particular, if you wish to erase also the ``GradientDescent.exe`` file you can type ``make distclean`` before ``make``.