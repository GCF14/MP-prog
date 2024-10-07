/*
CCPROG2 MP1 SOURCE CODE
Do not forget to encode your name, section and date of submission.

LASTNAME1, FIRSTNAME1: FELIPE, GERARD CHISTIAN
SECTION1: S11A
LASTNAME2, FIRSTNAME2: GANAYO, REINMAN GEOFFREY
SECTION2: S11A

DATE SUBMITTED : 03/15/2024
Rename this file using your last names in alphabetical order,
for example CRUZ_TAN.c
Make sure to compile your C source code with a -Wall directive.
Example: CCPROG2> gcc -Wall LASTNAME1_LASTNAME2.c

Fix all warnings. Do NOT run the program if you still have a warning. You must have
0 error, 0 warning before running the program.

Run the resulting a.exe file in the command line with input
and output (I/O) redirection.
Example: a < SoGA_DATASET.TXT >
OUTPUT_LASTNAME1_LASTNAME2.TXT
*/
#include <stdio.h>
#include <string.h>
/* Do NOT include other header files. */

/*
HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION
INCORRECT or CAUSE POINT DEDUCTIONS!
1. You must apply arrays and strings in MP Part 1 (MP1).
2. Document your codes with SENSIBLE comments.
3. Use double data type (not float) for all floating point
   values/variables/functions/return type.
4. Do NOT use any global variables.
5. Do NOT call printf() except inside the main() function.
6. Do NOT use the following yet this MP.
   a. struct data type.
   b. file processing functions such as fopen(), fclose(), etc.
7. Do NOT use library functions that were NOT discussed in
   our class.
*/
#define MAX_CHAR 36
#define MAX_TERRITORY 500
#define MAX_COLUMNS 16
#define NUMBER_OF_CASES 3

/*
You may declare any typedef that you need below this comment.
*/
typedef char String[MAX_CHAR];

/*
Define any function that you need below this comment.
The following should be included as comments and appear BEFORE
EACH function definition:
a. Purpose: describe succintly what the function is supposed to accomplish.
b. Parameters: describe succintly the nature/purpose of each parameter.
c. Return type: if the function is not void, describe succintly what it will return as a result.
For functions that serve as answers to the questions, include
the following as comments BEFORE the function definition itself:
a. Question number, and the actual question.
b. Thereafter, type the answer number, and the corresponding expected answer.

For example:
Q1: Which country has the lowest baseline life expectancy?
A1: Lesotho
Document the body of the function by including comments
alongside codes that you think may not be easy to understand to the person reading the codes.
*/

// Example function definition
/*
Q1: Which country has the lowest baseline life expectancy?
A1: Lesotho
Purpose: This function finds the country with the lowest baseline life expectancy.
Parameters:
- territories[]: An array of territory names.
- life_expectancy[]: An array of life expectancy values corresponding to the territories.
- count: The number of territories in the arrays.
Return type: The name of the territory with the lowest life expectancy.
*/

/* Purpose: To get the input from the user and store it into a
   2D array and a 1D array
   Parameters:
   1. territories[] - 1D array of strings that will contain the territory names
   2. life_expectancy_factors[][] - 2D array of doubles that will contain all the life expectancy factors and base life expectancy
   Return type: int (number of rows read by the program to get MAX_ROW)
*/
int get_input(String territories[], double life_expectancy_factors[][15]) {
    int i = 0, j = 0;
    String temp_string;
    double temp_double;

    while (scanf("%s", temp_string) == 1) { // loop which gets territory names and stores them into a 1D String array
        strcpy(territories[i], temp_string);
        for (j = 0; j < 15; j++) { // gets the base life expectancy and life expectancy factors of a given territory and stores them into a 2D double array
            if (scanf("%lf", &temp_double) == 1)
                life_expectancy_factors[i][j] = temp_double;
        }
        i++;
    }
    return i; // returns the number of rows read by the program
}

/* Purpose: Finds the index where the lowest double value is stored in an array
   Parameters:
   1. a[] - 1D array of doubles that will contain the life expectancy factors
   2. n - int that will contain the number of rows read by the program to get MAX_ROW
   Return type: int (index where the lowest number is found)
*/
int find_min(double a[], int n) {
    int i;
    int min = 0;
    for (i = 0; i < n; i++) {
        if (a[min] > a[i])
            min = i;
    }
    return min; // returns the index where the lowest number is found
}

/* Purpose: Finds the index where the highest double value is stored in an array
   Parameters:
   1. a[] - 1D array of doubles that will contain the life expectancy factors
   2. n - int that will contain the number of rows read by the program to get MAX_ROW
   Return type: int (index where the highest number is found)
*/
int find_max(double a[], int n) {
    int i;
    int max = 0;
    for (i = 0; i < n; i++) {
        if (a[max] < a[i])
            max = i;
    }
    return max; // returns the index where the highest number is found
}

/* Purpose: Finds the sum of all numbers of an array of doubles
   Parameters:
   1. a[] - 1D array of doubles that will contain the life expectancy factors
   2. n - int that will contain the number of rows read by the program to get MAX_ROW
   Return type: double (sum of all numbers in the array)
*/
double find_sum(double a[], int n) {
    int i;
    double sum = 0;
    for (i = 1; i < n; i++) { // starts at 1 since it does not count the base life expectancy
        sum += a[i];
    }
    return sum;
}

/* Purpose: Finds the average of all numbers of an array of doubles
   Parameters:
   1. a[] - 1D array of doubles that will contain the life expectancy factors
   2. n - int that will contain the number of rows read by the program to get MAX_ROW
   Return type: double (average of all numbers in the array)
*/
double find_avg(double a[], int n) {
    int i;
    double sum = 0.0;
    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    double avg = (double) sum / n;
    return avg;
}

/* Purpose: Counts the number of numbers in an array higher than a given condition
   Parameters:
   1. arr[] - 1D array of doubles that will contain the life expectancy factors
   2. size - int that will contain the number of rows read by the program to get MAX_ROW
   3. condition - float that will contain the condition to be checked
   Return type: int (number of numbers in the array higher than the condition)
*/
int count_above_num(double arr[], int size, float condition) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > condition) {
            count++;
        }
    }
    return count;
}

/* Purpose: Swaps the String and double values of a given index
   Parameters:
   1. arr[] - 1D array of strings that will contain the territory names
   2. factors[] - 1D array of doubles that will contain the life expectancy factors
   3. index1 - int that will contain the index of the first value to be swapped
   4. index2 - int that will contain the index of the second value to be swapped
   Return type: none
*/
void swap_elements(String arr[], double factors[], int index1, int index2) {
    String temp;
    double temp_factor;
    strcpy(temp, arr[index1]);
    strcpy(arr[index1], arr[index2]);
    strcpy(arr[index2], temp);
    temp_factor = factors[index1];
    factors[index1] = factors[index2];
    factors[index2] = temp_factor;
}

/* Purpose: Sorts the list of territories from A-Z
   Parameters:
   1. territories[] - 1D array of strings that will contain the territory names
   2. le_factors[] - 1D array of doubles that will contain the life expectancy factors
   3. n - int that will contain the number of rows read by the program to get MAX_ROW
   Return type: none
*/
void selection_sort(String territories[], double le_factors[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (le_factors[min] < le_factors[j])
                min = j;
        if (i != min) {
            swap_elements(territories, le_factors, i, min);
        }
    }
}

/* Purpose: Apply Binary Search on a given input to temp_string which contains the list of territory names which are sorted
   Parameters:
   1. input - string that will contain the input to be searched
   2. temp_string[] - Sorted 1D array of strings that will contain the territory names
   3. MAX_ROW - int that will contain the number of rows read by the program to get MAX_ROW
   Return type: int (index where the input is found), if not found then return -1
*/
int q3_binary_search(char input[], String temp_string[], int MAX_ROW) {
    int low, high, mid;
    low = 0;
    high = MAX_ROW - 2;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (strcmp(input, temp_string[mid]) == 0) {
            return mid;
        } else if (strcmp(input, temp_string[mid]) < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

/* Q1: After averaging each LE factor (excluding values from Global), which LE factor has the highest and lowest average?
   A1: Highest Average = LE Ozone - 0.023670
*/
/* Purpose: Answers question number one by finding the average of each life expectancy factor and finding the highest and lowest average
   Parameters:
   1. a[][] - 2D array of doubles that will contain the life expectancy factors
   2. s[] - 1D array of strings that will contain the territory names
   3. row_val - int that will contain the number of rows read by the program to get MAX_ROW
   4. array_of_avg[] - 1D array of doubles that will contain the average of each life expectancy factor
   Return type: none
*/
void mp_question_1(double a[][15], String s[], int row_val, double array_of_avg[]) {
    int i, j;
    double temp[row_val - 1]; // row_val - 1 because the global variable is not included
    int index = 0; // for array_of_avg

    // column major loop where in each column (excluding the 1st row and column)
    for (j = 1; j < 15; j++) { // loop starts at 1 because the 1st column is for base life expectancy
        for (i = 1; i < row_val; i++) { // loop starts at 1 because the 1st row is from the Global territory which is not included
            temp[i - 1] = a[i][j];
        }
        array_of_avg[index++] = find_avg(temp, row_val - 1); // updates the array with average values
    }
}

/* Q2: How many territories would still have above <param_number> baseline life expectancy after deducting the impact of all changes in life expectancy factors?
   A2: 
   Test case 1
   The number of territories above 70 baseline life expectancy after deduction is: 20 territories
   Test case 2
   *Invalid* Try Again
   Test case 3
   The number of territories above 80 baseline life expectancy after deduction is: 1 territories
*/
/* Purpose: Answers question number two by counting the number of territories that would still have above a given baseline life expectancy after deducting the impact of all changes in life expectancy factors
   Parameters:
   1. a[][] - 2D array of doubles that will contain the life expectancy factors
   2. s[] - 1D array of strings that will contain the territory names
   3. n - int that will contain the number of rows read by the program to get MAX_ROW
   4. param_number - int that will contain the parameter number to be checked
   Return type: int (number of territories that would still have above a given baseline life expectancy after deducting the impact of all changes in life expectancy factors)
*/
int mp_question_2(double a[][15], String s[], int n, int param_number) {
    int i, j = 0;
    double array_of_sum[n - 1]; // does not include values from the 1st Row (Global)
    if (param_number > 0) { // checks if the input is above 0 since life expectancy can never be 0 or a negative value
        for (i = 1; i < n; i++) { // excludes the Global variables
            array_of_sum[j] = a[i][0] - find_sum(a[i], 15); // passes each row of the 2D array
            j++;
        }
        return count_above_num(array_of_sum, n - 1, param_number);
    } else {
        return -1; // the count above can return 0 so the else returns -1
    }
}

/* Q3: What is the ranking of change in life expectancy factors of <parameter_territory_name> from highest to lowest?
   A3: 
   Country: Philippines
   Ranked Highest to Lowest
   1. 6.165008 - Metabolic Syndrome
   2. 2.575556 - Tobacco
   3. 2.383616 - Environmental/Occupational Hazards
   4. 2.162167 - Dietary
   5. 2.159935 - Smoking
   6. 1.885343 - High Fasting Plasma Sugar
   7. 1.675681 - Air pollution
   8. 0.929484 - Household Air Pollution
   9. 0.691634 - Ambient PM
   10. 0.460448 - Secondhand Smoke
   11. 0.242926 - Unsafe WaSH
   12. 0.224457 - Occupational Hazards
   13. 0.164648 - Unsafe Sex
   14. 0.002370 - Ozone
   Country: China
   Ranked Highest to Lowest
   1. 4.716210 - Metabolic Syndrome
   2. 2.861276 - Environmental/Occupational Hazards
   3. 2.777920 - Tobacco
   4. 2.437863 - Smoking
   5. 2.028728 - Dietary
   6. 1.850731 - Air pollution
   7. 1.393518 - Ambient PM
   8. 0.987177 - High Fasting Plasma Sugar
   9. 0.386617 - Secondhand Smoke
   10. 0.352632 - Occupational Hazards
   11. 0.340365 - Household Air Pollution
   12. 0.090016 - Unsafe Sex
   13. 0.074187 - Ozone
   14. 0.017428 - Unsafe WaSH
   *Invalid* Try Again
*/
/* Purpose: Answers question 3 by checking if the input given is in the list of territories, then sort the strings using selection sort and use binary search to determine the index where the territory being looked for.
   Use selection sort to sort the values of life_expectancy_factors and assign to them their factor names
   Parameters:
   1. input - The input given be given to know what territory's life expectancy factors to sort
   2. territories[] - Contains the list of territories of the given data
   3. life_expectancy_factors[][] - Contains the life expectancy factors of each territory
   4. MAX_ROW - Number of rows scanned by the program from the given data
   5. temp_array[][] - Will be used to store the sorted life expectancy factors
   6. switch_factors[] - Will be used to store the names of the life expectancy factors
   7. *index - Will be used to determine the index of the territory once it has been sorted
   8. *result3 - Will be used to check whether the given input is in the given data or not
   Return type: none
*/
void mp_question3(String input, String territories[], double life_expectancy_factors[][15], int MAX_ROW, double temp_array[][15], String switch_factors[], int *index, int *result3) {
    int i, j, min, k;
    double temp;
    String temp_string[MAX_ROW], switch_string;
    String factors[15] = {
        "Base Life Expectancy", "Air pollution", "Ambient PM", "Ozone",
        "Household Air Pollution", "Environmental/Occupational Hazards",
        "Occupational Hazards", "Unsafe WaSH", "Metabolic Syndrome",
        "Dietary", "High Fasting Plasma Sugar", "Tobacco",
        "Smoking", "Secondhand Smoke", "Unsafe Sex"
    };
    /* Assigns the strings of territories to tempString
       Assign life expectancy factors to temp_array and make sure its at its corresponding row
       Make sure to not include the Base Life Expectancy when transferring the values to tempArray */
    for (i = 0; i < MAX_ROW; i++) {
        strcpy(temp_string[i], territories[i]);
        for (j = 0; j < 15; j++) {
            temp_array[i][j] = life_expectancy_factors[i][j];
        }
    }
    // Checks if the input is in the array of territories
    for (i = 0; i < MAX_ROW; i++) {
        if (strcmp(input, temp_string[i]) == 0) {
            *result3 = 1;
            break;
        }
    }
    // Checks if the input is not in the array of territories
    if (i == MAX_ROW) {
        *result3 = -1;
    }

    /* Assigns factors in switch_factors in order to sort it with the values later */
    for (i = 0; i < 15; i++) {
        strcpy(switch_factors[i], factors[i]);
    }
    /* Selection sort for the temp_string array. Assign the values to their new spots in
       temp_array since tempString has been changed, so the position of the life expectancy
       factors have to be changed as well */
    for (i = 0; i < MAX_ROW - 1; i++) {
        min = i;
        for (j = i + 1; j < MAX_ROW; j++) {
            if (strcmp(temp_string[min], temp_string[j]) > 0) {
                min = j;
            }
        }
        if (i != min) {
            strcpy(switch_string, temp_string[i]);
            strcpy(temp_string[i], temp_string[min]);
            strcpy(temp_string[min], switch_string);
            for (k = 0; k < 15; k++) {
                temp = temp_array[i][k];
                temp_array[i][k] = temp_array[min][k];
                temp_array[min][k] = temp;
            }
        }
    }

    /* Binary Search for temp_string in order to get the index where the country is located in tempString array after sorting it */
    *index = q3_binary_search(input, temp_string, MAX_ROW);
    /* Selection sort on the factors, then make sure to assign the factor's labels
       to their right positions since the positions of factors will change */
    for (i = 0; i < 14; i++) {
        min = i;
        for (j = i + 1; j < 15; j++) {
            if (temp_array[*index][min] > temp_array[*index][j]) {
                min = j;
            }
        }
        if (i != min) {
            temp = temp_array[*index][i];
            temp_array[*index][i] = temp_array[*index][min];
            temp_array[*index][min] = temp;
            strcpy(switch_string, switch_factors[i]);
            strcpy(switch_factors[i], switch_factors[min]);
            strcpy(switch_factors[min], switch_string);
        }
    }
}

/* Q4: What is the life expectancy of <parameter_territory_name> before and after subtracting it with all the change in life expectancy factors?
   A4:
   TESTCASE 1
   Territory: Philippines
   Base Life Expectancy: 71.798423
   (After subtracting it with all the factors)
   Life Expectancy: 50.075149
   TESTCASE 2
   Territory: China
   Base Life Expectancy: 77.582175
   (After subtracting it with all the factors)
   Life Expectancy: 57.267508
   TESTCASE 3
   Territory: Mars
   *Invalid* Try Again
*/
/* Purpose: Answer question 4 by finding the index of the territory and then subtracting the base life expectancy with the factors of change in life expectancy
   Parameters:
   1. input - The input given to know what territory's life expectancy factors to sort
   2. territories[] - Contains the list of territories of the given data
   3. life_expectancy_factors[][] - Contains the life expectancy factors of each territory
   4. MAX_ROW - Number of rows scanned by the program from the given data
   5. life_expectancy - The base life expectancy of the territory
   6. *index_BE - Will be used to determine the index of the territory once it has been sorted
   Return type: double (life expectancy of the territory after subtracting it with all the factors)
*/
double mp_question4(String input, String territories[], double life_expectancy_factors[][15], int MAX_ROW, double life_expectancy, int *index_BE) {
    int i;
    // Uses Linear Search to find the index of the row where the input is located in the territories and life_expectancy_factors array
    int found = 0;
    for (i = 0; i < MAX_ROW; i++) {
        if (strcmp(input, territories[i]) == 0) {
            life_expectancy = life_expectancy_factors[i][0];
            *index_BE = i; // assigns the index value
            found = 1;
        }
    }

    // Checks if the for loop has gone through all of the territories and no match for input
    if (found) {
        // For loop that continuously subtracts the value of the base life expectancy with the factors of change in life expectancy
        for (i = 1; i <= 14; i++) {
            life_expectancy -= life_expectancy_factors[*index_BE][i];
        }
        return life_expectancy;
    } else {
        return 0;
    }
}

/* Q5: Which are the top <parameter_number> with the highest baseline life expectancy? List them from highest to lowest.
   A5:
   TESTCASE 1
   1. Singapore 84.565300
   2. Japan 84.557851
   3. Iceland 83.891722
   4. Switzerland 83.863622
   5. Italy 83.032133
   TESTCASE 2
   *Invalid* Try Again
   TESTCASE 3
   1. Singapore 84.565300
   2. Japan 84.557851
   3. Iceland 83.891722
   4. Switzerland 83.863622
   5. Italy 83.032133
   6. Spain 83.012277
   7. Israel 82.902047
   8. Norway 82.829180
   9. South_Korea 82.826250
   10. Luxembourg 82.798953
*/
/* Purpose: Answer question 5 by sorting the list of territories from A-Z and then printing the top <parameter_number> with the highest baseline life expectancy
   Parameters:
   1. a[][] - 2D array of doubles that will contain the life expectancy factors
   2. s[] - 1D array of strings that will contain the territory names
   3. param_number - int that will contain the parameter number to be checked
   4. baseline_life_expectancy[] - 1D array of doubles that will contain the base life expectancy of each territory
   5. copy_array[] - 1D array of strings that will contain the territory names
   6. rows - int that will contain the number of rows read by the program to get MAX_ROW
   Return type: int (returns the number of how many territories will be printed in the main function)
*/
int mp_question_5(double a[][15], String s[], int param_number, double baseline_life_expectancy[], String copy_array[], int rows) {
    int i;

    for (i = 0; i < rows; i++) {
        baseline_life_expectancy[i] = a[i][0]; // transfers the base life expectancy from a the 2D array of values to 1D
        strcpy(copy_array[i], s[i]); // makes a copy array of the territory names
    }
    selection_sort(copy_array, baseline_life_expectancy, rows); // calls the selection sort function to sort the array from A-Z
    if (param_number > 0 && param_number <= rows) // checks if the param_number is above 0 and less than the total number of territories
        return param_number;
    else
        return 0;
}

int main() {
    /* Declare your own local variables. Describe the purpose of your local variables. */

    String territories[MAX_TERRITORY]; // where the territory names are stored
    double life_expectancy_factors[MAX_TERRITORY][15]; // where the base life expectancy and life expectancy factors are stored
    int MAX_ROW = get_input(territories, life_expectancy_factors); // gets the total number of

    int i, j, k; // it is for for-loop loops
    int question_num = 1;
    // For questions that need temporary arrays
    double array_of_avg[14]; // Q1
    double temp_array[MAX_ROW][15]; // Q3
    String switch_factors[15]; // Q3
    int index, result3 = 0; // Q3
    double life_expectancy = 0; // Q4
    int index_BE = 0; // Q4
    double baseline_life_expectancy[MAX_ROW]; // Q5
    String copy_array[MAX_ROW]; // Q5
    int q2_input[NUMBER_OF_CASES] = {70, -1, 80};
    String q3_input[NUMBER_OF_CASES] = {"Philippines", "China", "Mars"};
    String q4_input[NUMBER_OF_CASES] = {"China", "Philippines", "Mars"};
    int q5_input[NUMBER_OF_CASES] = {5, 500, 10};

    /* Call the function that answers a question. Thereafter, use printf() to print the question and the corresponding answer. For example:
       expectancy = Q1_Answer(territory, param_x, param_y); // where expectancy, territory, param_x and param_y are local variables.
       printf("Q1: Which territory has the lowest baseline life expectancy?\n");
       printf("A1: %s %lf\n", territory, expectancy);
       TEST CASES HARD REQUIREMENTS:
       You should have multiple test cases, i.e., functions calls to answer those
       Questions that involve parameter(s). There should be function calls with
       different actual parameter values. For questions that require searching
       (linear or binary search), there should be a test case, i.e.,
       a function call with a search key parameter that does not exist, i.e.,
       NOT FOUND scenario.
    */

    String factor_names[14] = {"Air pollution", "Ambient PM", "Ozone", "Household Air Pollution",
                                "Environmental/Occupational Hazards", "Occupational Hazards", "Unsafe WaH", "Metabolic Syndrome",
                                "Dietary", "High Fasting Plasma Sugar", "Tobacco", "Smoking", "Secondhand Smoke", "Unsafe Sex"};

    printf("\n===================================QUESTION %d===================================\n", question_num);
    printf("Q1: After averaging each LE factor (excluding values from Global), which LE factor has the highest and lowest average?\n");
    printf("A%d: \n", question_num++);
    mp_question_1(life_expectancy_factors, territories, MAX_ROW, array_of_avg); // updates the array_of_avg array
    // finds the min and max
    int max = find_max(array_of_avg, 14);
    int min = find_min(array_of_avg, 14);

    printf("\nHighest Average = %s \t-\t%lf\n", factor_names[max], array_of_avg[max]);
    printf("\nLowest Average = %s \t-\t%lf\n", factor_names[min], array_of_avg[min]);

    printf("\n===================================QUESTION %d===================================\n", question_num);
    printf("Q2: How many territories would still have above <parameter_number> baseline life expectancy after deducting the impact of all changes in life expectancy factors?\n");
    printf("A%d: \n", question_num++);
    for (i = 0; i < NUMBER_OF_CASES; i++) {
        printf("\tTESTCASE %d \n", i + 1);
        int count = mp_question_2(life_expectancy_factors, territories, MAX_ROW, q2_input[i]);
        if (count >= 0)
            printf("\nThe number of territories above %d baseline life expectancy after deduction is: %d territories\n", q2_input[i], count);
        else
            printf("*Invalid* Try Again\n");
    }
    
    printf("\n===================================QUESTION %d===================================\n", question_num);
    printf("Q3: What is the ranking of change in life expectancy factors of <name_of_territory> from highest to lowest?\n");
    printf("A%d: \n", question_num++);
    for (i = 0; i < NUMBER_OF_CASES; i++) {
        printf("\tTESTCASE %d \n", i + 1);
        mp_question3(q3_input[i], territories, life_expectancy_factors, MAX_ROW, temp_array, switch_factors, &index, &result3);
        if (result3 == 1) {
            printf("\nCountry: %s\n", q3_input[i]);
            printf("Ranked Highest to Lowest\n\n");
            for (k = 13, j = 1; k >= 0; k--, j++) {
                printf("%2d. %.6lf - %s\n", j, temp_array[index][k], switch_factors[k]);
            }
        } else {
            printf("\n*Invalid* Try Again\n");
            break;
        }
    }

    printf("\n===================================QUESTION %d===================================\n", question_num);
    printf("Q4: What is the life expectancy of <parameter_territory_name> before and after subtracting it with all the change in life expectancy factors?\n");
    printf("A%d: \n", question_num++);
    for (i = 0; i < NUMBER_OF_CASES; i++) {
        printf("\tTESTCASE %d \n", i + 1);
        printf("\nTerritory: %s\n", q4_input[i]);
        life_expectancy = mp_question4(q4_input[i], territories, life_expectancy_factors, MAX_ROW, life_expectancy, &index_BE);
        if (life_expectancy) {
            printf("Base Life Expectancy: %.6lf\n\n", life_expectancy_factors[index_BE][0]);
            printf("(After subtracting it with all the factors)\n");
            printf("Life Expectancy: %.6lf\n", life_expectancy);
        } else {
            printf("\n*Invalid* Try Again\n");
        }
    }

    printf("\n===================================QUESTION %d===================================\n", question_num);
    printf("Q5: Which are the top <parameter_number> with the highest baseline life expectancy? List them from highest to lowest.\n");
    printf("A%d: \n", question_num++);
    for (i = 0; i < NUMBER_OF_CASES; i++) {
        printf("\tTESTCASE %d \n", i + 1);
        int output = mp_question_5(life_expectancy_factors, territories, q5_input[i], baseline_life_expectancy, copy_array, MAX_ROW);
        if (output) {
            for (j = 0; j < output; j++) {
                printf("%d. ", j + 1);
                printf("%s\t\t %lf\n", copy_array[j], baseline_life_expectancy[j]);
            }
        } else {
            printf("*Invalid* Try Again\n");
        }
    }

    return 0; 
}

