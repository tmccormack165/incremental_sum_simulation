#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "Functions.h"

using namespace std;



int main(int argc, char *argv[]){
    // declare integer variables and pointers
    int n, offset, random_number, current_sum, max_sum, offset_i, lower_bound, upper_bound;
    int* gdata;
    int* incremental_sums;

    if(argc > 2){
        n = stoi(argv[1]);
        lower_bound = stoi(argv[2]);
        upper_bound = stoi(argv[3]);
    }
    else{
        n = 5;
        lower_bound = 0, 
        upper_bound = 10000;
    }


    // declare string variables and pointers
    string* prompts;
    string prompt_i, max_str, offset_str, offset_i_str;
    string prompt_end = "d\n";

    // seed the random generator so that different numbers will be generated upon each execution
    srand(time(NULL));

    // n is how many random integers to generate, it is five unless command line arguments specify otherwise
    

    // allocate an array of integers of size n
    gdata = new int[n];
    // allocate an array of strings of size n
    prompts = new string[n];
    // allocate an array of ints to store the incremental sums
    incremental_sums = new int[n-1];

    // populate the prompts array
    // calculate which string literal has the longest name ex. length("Three") == 5
    int max_length = 0;
    for(int i = 1; i < n; i++){
        prompt_i = "Adding " + nameForNumber(i+1) + " Numbers  %";
        prompts[i] = prompt_i;
        if(prompt_i.length() > max_length){
            max_length = prompt_i.length();
        }
    }

    // generate random numbers
    for(int i = 0; i < n; i++){
        random_number = rand() % (upper_bound + 1); // we want the upper bound to be a possible value
        gdata[i] = random_number;
    }
   
    // calculate incremental sums
    current_sum = 0;
    for(int i = 0; i < n; i++){
        current_sum += gdata[i];
        if(i > 0){
            incremental_sums[i-1] = current_sum;
        }
    }
    
    // record the maximum incremental sum 
    // its index is n-2 because the length of the invremental_sums array is n-1
    // also, the last incremental sum will be the largest because the process is iterative
    max_sum = incremental_sums[n-2];
    // convert the largest incremental sum to a string
    max_str = to_string(max_sum);
    // record the length of  the maximum string, this will tell the prompts how many spaces to print
    offset = max_str.length();
    // convert the length of the maximum string (an int) to a string
    offset_str = to_string(offset);

    
    for(int i = 1; i < n; i++){
        // calculate the unique offset for index i
        offset_i = offset + max_length - prompts[i].length();
        // convert offset_i to string
        offset_i_str = to_string(offset_i);
        // update prompts[i] to contain the correct offset
        prompts[i] = prompts[i] + offset_i_str + prompt_end;
        printf(prompts[i].c_str(), incremental_sums[i-1]);
    }

    // free the allocated arrays to avoid memory leaks
    delete[] gdata;
    delete[] prompts;
    delete[] incremental_sums;



    return 0;
}



