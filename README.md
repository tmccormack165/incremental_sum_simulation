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
Adding Two Numbers     5099
Adding Three Numbers  13494
Adding Four Numbers   22197
Adding Five Numbers   22423
Adding Six Numbers    27955
Adding Seven Numbers  32321
Adding Eight Numbers  39206
Adding Nine Numbers   47012
Adding Ten Numbers    49905
```

# Usage

```
g++ overloading.cpp -o ov && ./ov 10 0 10000
```
**This execution will generate ten random numbers between zero and ten thousand and print each line as shown in the output section.



