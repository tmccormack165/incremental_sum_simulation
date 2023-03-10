#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

float add(float x, float y);
float add(float a, float b, float c);

string digitName(int digit);
string teenName(int number);
string tensName(int number);
string intName(int number);

vector<string> ones {"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
vector<string> teens {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen","Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string nameForNumber (long number) {
    if (number < 10) {
        return ones[number];
    } else if (number < 20) {
        return teens [number - 10];
    } else if (number < 100) {
        return tens[number / 10] + ((number % 10 != 0) ? " " + nameForNumber(number % 10) : "");
    } else if (number < 1000) {
        return nameForNumber(number / 100) + " Hundred" + ((number % 100 != 0) ? " " + nameForNumber(number % 100) : "");
    } else if (number < 1000000) {
        return nameForNumber(number / 1000) + " Thousand" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : "");
    } else if (number < 1000000000) {
        return nameForNumber(number / 1000000) + " Million" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : "");
    } else if (number < 1000000000000) {
        return nameForNumber(number / 1000000000) + " Billion" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : "");
    }
    return "error";
}


int main(){
    int n, offset;
    int random_number, current_sum;
    int lower_bound = 0, upper_bound = 10000;
    int* gdata;
    int* incremental_sums;
    int max_sum;
    string* prompts;
    string prompt_i, max_str, offset_str;
    string prompt_end = "d\n";

    // seed the random generator so that different numbers will be generated upon each execution
    srand(time(NULL));
    //cout << "How many numbers to generate: ";
    //cin >> n;
    n = 5;

    gdata = new int[n];
    prompts = new string[n];
    incremental_sums = new int[n-1];

    // populate the prompts array
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
    
    

    max_sum = incremental_sums[n-2];
    max_str = to_string(max_sum);
    offset = max_str.length();
    offset_str = to_string(offset);

    int offset_i;
    string offset_i_str;
    for(int i = 1; i < n; i++){
        offset_i = offset + max_length - prompts[i].length();
        offset_i_str = to_string(offset_i);
        prompts[i] = prompts[i] + offset_i_str + prompt_end;
        printf(prompts[i].c_str(), incremental_sums[i-1]);
    }



    
    delete[] gdata;
    delete[] prompts;
    delete[] incremental_sums;



    return 0;
}

float add(float x, float y){
    float r;
    r = x + y;
    return r;
}

float add(float a, float b, float c){
    float r;
    r = a + b + c;
    return r;
}

/*

float get_max(float a, float b){
    float return_value;
    if(a > b){
        return_value = a;
    }
    else{
        return_value = b;
    }
    return return_value;
}

float double_add, triple_add, max_float;
    string max_float_str;
    //string printf_prompt_begin = "Adding Two Numbers:    %5.2f\n";
    string prompt_begin_2 = "Adding Two Numbers:  %";
    string prompt_begin_3 = "Adding Three Numbers:%";
    string offset_str;
    string prompt_end = ".2f\n";
    string final_prompt;
    string final_prompt_3;
    int offset;

    double_add = add(4.4, 5.5);

    triple_add = add(450.4, 6.6, 5.5);

    max_float = get_max(double_add, triple_add);
    max_float_str = to_string(max_float);
    offset = max_float_str.length();
    offset_str = to_string(offset);
    final_prompt = prompt_begin_2 + offset_str + prompt_end;
    final_prompt_3 = prompt_begin_3 + offset_str + prompt_end;

    
    
    
    // use printf for aligned output
    printf(final_prompt.c_str(), double_add);
    printf(final_prompt_3.c_str(), triple_add);
    return 0;
*/