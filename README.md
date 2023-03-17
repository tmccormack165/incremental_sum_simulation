# incremental sum simulation
a simple simulation that uses C++ string interpolation to align console messages from randomly generated data

# Description

This simulation generates random numbers and prints them to the console with right aligned-output. Each line has the string literal corresponding to its index.

## Input
```
Arguments:
1. argv[0] (str): the name of the executable
2. argv[1] (int): how many random numbers to generate
3. argv[2] (int): the lower bound for the random numbers
4. argv[3] (int): the upper bound for the random numbers
```

## Output
```
Adding Two Numbers    12179
Adding Three Numbers  13062
Adding Four Numbers   22693
Adding Five Numbers   32399
Adding Six Numbers    37357
Adding Seven Numbers  41034
Adding Eight Numbers  43503
Adding Nine Numbers   46127
Adding Ten Numbers    47917
```

# Usage

```
g++ main.cpp functions.cpp -o sim && ./sim 10 0 10000
```
**This execution will generate ten random numbers between zero and ten thousand and print each line as shown in the output section.**



