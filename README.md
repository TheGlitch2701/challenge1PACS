# Challenge1-PACS-23-24

This repository is for the 1st Challenge of the course at Politecnico di Milano "PACS 2023/2024" regarding the method of ***Gradient Descent***

## 1. Introduction

The goal of this challenge was to build from scratch the code for computing the Gradient Descent Method (GD).
Going into the specific, the goal was to implement the main body of GD, some rate rules related to the updating of the learning rate and to find the minimum of (at least) the following function:

`` SCRIVERE FUNZIONE DA MININIZZARE ``

but the code I developed is able to compute the minimum (if ever) of any (at least polynomial) function.

*See Section 2 for more details*

## 2. Implementation

The project Is organised as follow:
- src
- include 
- lib
- doc
- GradientDescent.cpp
- Makefile
- 

### 2.1 Libraries Used

To implement my version of the GD Method, I used the following libraries:

- **GetPot**: library used to read from ``data.txt`` all parameters the code will use;

- **muparserx**: library which lets the user to parse a string into a Mathematical Function if possible and allows to compute the value of this function on a specific point. The main difference, for my purpose, with the library muparser is that the first one lets me work with vectors.

### 2.2 Class Point

I started my process of development defining a Class called Point whose header file contains the following lines:

``Parte header file``

Its methods were introduced in order to make the computation during the GD Method easier.
In particular I want to focus on ``setPoint(double &, Point &)`` and ``setPoints()``:

- ``setPoints()`` was firstly introduced to change the points vector all at once, in order to be faster during computation;

- ``setPoint(double &, Point &)`` instead was introduced later because during the updating rule for the gradient of the function, it was necessary to change one component (*i.e. variable*) at a time.

### 2.3 DATA.txt

This file was created to collect all the parameters needed by the Solver in order to do its work. Here I list all of them:

- ``dim``: it expresses how many variables are used to define the function to minimize;

- ``start``: it expresses the starting point of the GD Method. Need to be written between ``' '`` and with a **space** to separate each value;

- ``learning rate``: starting rate for the Gradient's update;

- ``max_it``: maximum number of iterations that the GD Method might perform;

- ``tol_res``: tolerance on the *Gradient Norm Convergence Criteria* *(See doc for further details)*;

- ``tol_step``: tolerance on the *Steps difference Norm Convergence Criteria* *(See doc for further details)*;

- ``rate_rule``: updating rule for the learning rate. Here's the possibility *(See doc for further documentario)*:
    - ``exponential decay``

    - ``inverse decay``

    - ``line search``

- ``mu``: coefficient used for the ***exponential decay*** and ***inverse decay*** update *(See doc for further documentario)*;

- ``sigma``: coefficient used for the ***line search*** update *(See doc for furter documentario)*;

- ``fun``: the function to minimize. Need to be written between ``' '`` and each variable with the following rule ``x[i] i in {0, 1, 2, ..., N}``

- ``dfunx0, dfubx1 ...``: the derivative of *fun* w.r.t. *x0, x1, x2, ...*. Of course it is needed to write all of them singularly