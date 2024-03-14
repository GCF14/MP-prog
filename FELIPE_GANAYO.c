/*
	CCPROG2 MP1 SOURCE CODE

    Do not forget to encode your name, section and date of submission.
    
    LASTNAME1, FIRSTNAME1:       FELIPE, GERARD CHISTIAN         SECTION1: S11A
    LASTNAME2, FIRSTNAME2:       GANAYO, REINMAN GEOFFREY        SECTION2: S11A
    
    DATE SUBMITTED     :
		
	Rename this file using your last names in alphabetical order, for example CRUZ_TAN.c
		
	Make sure to compile your C source code with a -Wall directive.  
	   Example: CCPROG2> gcc -Wall LASTNAME1_LASTNAME2.c
	   
	Fix all warnings.  Do NOT run the program if you still have a warning.  You must have
	0 error, 0 warning before running the program.
	   
	Run the resulting a.exe file in the command line with input and output (I/O) redirection.
	   Example: a < SoGA_DATASET.TXT > OUTPUT_LASTNAME1_LASTNAME2.TXT

*/

#include <stdio.h>
#include <string.h>
/* Do NOT include other header files. */ 

/* 
	HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE POINT DEDUCTIONS!
	
	1. You must apply arrays and strings in MP Part 1 (MP1).
    2. Document your codes with SENSIBLE comments.
    3. Use double data type (not float) for all floating point 
       values/variables/functions/return type
    4. Do NOT use any global variables.
    5. Do NOT call printf() except inside the main() function.
    6. Do NOT use the following yet this MP.
        a. struct data type
	    b. file processing functions such as fopen(), fclose(), etc.
	7. Do NOT use library functions that were NOT discussed in our class.
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

    The following should be included as comments and appear BEFORE EACH function definition:
       a. Purpose: describe succintly what the function is supposed to accomplish.
       b. Parameters: describe succintly the nature/purpose of each parameter.
       c. Return type: if the function is not void, describe succintly what it will return as a result.          

    For functions that serve as answers to the questions, include the following as comments
    BEFORE the function definition itself:
       a. Question number, and the actual question.
       b. Thereafter, type the answer number, and the corresponding expected answer.
    
    For example: 
      Q1:  Which country has the lowest baseline life expectancy?
      A1:  Lesotho

    Document the body of the function by including comments alongside codes that you think
    may not be easy to understand to the person reading the codes. 
*/


int get_input(String territories[], double life_expectancy_factors[][15]) {
    int i = 0, j = 0;
    String temp_string;
    double temp_double;

    while (scanf("%s", temp_string) == 1) { // loop which gets territory names and stores them into a 1D String array
        strcpy(territories[i], temp_string);
        for (j = 0; j < 15; j++) {				// gets the base life expectancy and life expectancy factors of a given territory and stores them into a 2D double array
            if (scanf("%lf", &temp_double) == 1)	
                life_expectancy_factors[i][j] = temp_double;
        }
        i++;
    }
    
    return i;  // returns the number of rows read by the program
}


// Function which finds the index where the lowest double value is stored in an array
int find_min(double a[], int n) {		
    int i;
    int min = 0;					
    for (i = 0; i < n; i++) {	
        if (a[min] > a[i])
            min = i;
    }
    return min;	// returns the index where the lowest number is found
}


// Function which finds the index where the highest double value is stored in an array
int find_max(double a[], int n) {	
    int i;
    int max = 0;
    for (i = 0; i < n; i++) {
        if (a[max] < a[i])
            max = i;
    }

    return max; // returns the index where the highest number is fouund
}

// Function which finds the the sum of all numbers of an array of doubles 
double find_sum(double a[], int n) { 
    int i;
    double sum = 0;
    for (i = 1; i < n; i++) { // starts at 1 since it does not count the base life expectancy
        sum += a[i];
    }

    return sum;
}

// Function which finds the the average of all numbers of an array of doubles
double find_avg(double a[], int n) {
    int i;
    double sum = 0.0;

    for (i = 0; i < n; i++) {
        sum += a[i];
    }
    double avg;
    avg = (double) sum / n;

    return avg;
}

// Function to count numbers in an array higher than a given condition
int count_above_num(double arr[], int size, float condition) { 
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > condition) {
            count++;
        }
    }

    return count;
}

// Function to swap the String and double values of a given index
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


// Function to sort the list of terriories from A-Z
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



/*
int q3_binary_search(char input[], String temp_string[]) {
    int low, high, mid;

    low = 0;
    high = MAX_ROWS - 2;

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
*/



void mp_question_1(double a[][15], String s[], int row_val, double array_of_avg[]) {

    int i, j;
    double temp[row_val - 1];  // row_val - 1 because the global variable is not included  
	   
    int index = 0;  // for array_of_avg
    
    // column major loop where in each column (excluding the 1st row and column) 
    for(j = 1; j < 15; j++){	// loop starts at 1 because the 1st column because it is the column for base life expectancy
    	for (i = 1; i < row_val; i++) { // loop start at 1 because the 1st row are from the Global territory which is not included 
    	temp[i - 1] = a[i][j]; 
    	}
    	
    	 
    	
   		array_of_avg[index++] = find_avg(temp, row_val - 1); // updates the array with average values
	}
    
    
}

int mp_question_2(double a[][15], String s[], int n, int param_number) {

    int i, j = 0;
    double array_of_sum[n - 1]; // does not include values from the 1st Row (Global)
	
	
	if(param_number > 0){		// checks if the input if it is above 0 since life expectancy can never be 0 or a negative value
		
		for (i = 1; i < n; i++) { // excludes the Global variables
       		array_of_sum[j] = a[i][0] - find_sum(a[i], 15); // passes each row of the 2D array
        	j++;
  		  }

    //	int n = sizeof(array_of_sum) / sizeof(array_of_sum[0]);
    
	
		return count_above_num(array_of_sum, n - 1, param_number);
	}
    
    else 
	return -1; // the count above can return 0 so the else returns -1
}

/*
void mp_question3(String input, String territories[], double life_expectancy_factors[][15]) {
    int i, j, min, index, k;
    double temp;
    double temp_array[MAX_ROWS][14];
    String switch_factors[14];
    String temp_string[MAX_ROWS], switch_string;
    
    String factors[14] = {"Air pollution", "Ambient PM", "Ozone", "Household Air Pollution", "Environmental/Occupational Hazards", 
                        "Occupational Hazards", "Unsafe Wash", "Metabolic Syndrome", "Dietary", "High Fasting Plasma Sugar", "Tobacco",
                        "Smoking", "Secondhand Smoke", "Unsafe Sex"};

    // Assigns the strings of territories to temp_string 
    // Assigns life expectancy factors to temp_array and ensures it is at its corresponding row
    // Exclude the Base Life Expectancy when transferring values to temp_array
    for(i = 0; i < MAX_ROWS; i++) {
        strcpy(temp_string[i], territories[i]);
        for(j = 0; j < 14; j++) {
            temp_array[i][j] = life_expectancy_factors[i][j + 1];
        }   
    }

    // Assigns factors in switch_factors to sort it with the values later
    for(i = 0; i < 14; i++) {
        strcpy(switch_factors[i], factors[i]);
    }

    // Selection sort for the temp_string array
    // Assigns the values to their new spots in temp_array since temp_string has changed
    for(i = 0; i < MAX_ROWS - 1; i++) {
        min = i;
        for(j = i + 1; j < MAX_ROWS; j++) {
            if(strcmp(temp_string[min], temp_string[j]) > 0) {
                min = j;
            }
        }

        if (i != min) {
            strcpy(switch_string, temp_string[i]);
            strcpy(temp_string[i], temp_string[min]);
            strcpy(temp_string[min], switch_string);

            for(k = 0; k < 15; k++) {
                temp = temp_array[i][k];
                temp_array[i][k] = temp_array[min][k];
                temp_array[min][k] = temp;
            }
        }
    }

    // Binary Search for temp_string to get the index where the country is located in temp_string array after sorting it
    index = q3_binary_search(input, temp_string);

    // Selection sort on the factors
    // Assign the factor's labels to their right positions since the positions of factors will change
    for(i = 0; i < 13; i++) {
        min = i;
        for(j = i + 1; j < 14; j++) {
            if(temp_array[index][min] > temp_array[index][j]) {
                min = j;
            }
        }

        if(i != min) {
            temp = temp_array[index][i];
            temp_array[index][i] = temp_array[index][min];
            temp_array[index][min] = temp;

            strcpy(switch_string, switch_factors[i]);
            strcpy(switch_factors[i], switch_factors[min]);
            strcpy(switch_factors[min], switch_string);
        }
    }

    // Prints the factors and their values from highest to lowest
    printf("Ranked Highest to Lowest\n\n");
    for(i = 13, j = 1; i >= 0; i--, j++) {
        printf("%2d. %lf - %s\n", j, temp_array[index][i], switch_factors[i]);
    }
}


void mp_question4(String input, String territories[], double life_expectancy_factors[][15]) {
    int i, index;
    double life_expectancy;

    // Uses Linear Search to find the index of the row where the input is located in the territories and life_expectancy_factors array
    printf("Territory: %s\n", input);
    for(i = 0; i < MAX_ROWS; i++) {
        if(strcmp(input, territories[i]) == 0) {
            printf("Base Life Expectancy: %lf\n\n", life_expectancy_factors[i][0]);
            life_expectancy = life_expectancy_factors[i][0];
            index = i;
            break;
        }
    }

    // For loop that continuously subtracts the value of the base life expectancy with the factors of change in life expectancy
    for(i = 1; i <= 14; i++) {
        life_expectancy -= life_expectancy_factors[index][i];
    }

    printf("(After subtracting it with all the factors)\n");
    printf("Life Expectancy: %lf\n", life_expectancy);
}
*/
int mp_question_5(double a[][15], String s[], int param_number, double baseline_life_expectancy[], String copy_array[], int rows) {

    int i;
    
	
    for (i = 0; i < rows; i++) {
        baseline_life_expectancy[i] = a[i][0]; // transfers the base life expectancy from a the 2D array of values to 1D
        strcpy(copy_array[i], s[i]); // makes a copy array of the territory namees
    }

    selection_sort(copy_array, baseline_life_expectancy, rows); // calls the selection sort function to sort the array from A-Z 

	if(param_number > 0 && param_number <= rows) //checks if the param_number is above 0 and less than the total number of territories
	return param_number;
	else
	return 0;
}

int
main()
{
    /* Declare your own local variables. Describe the purpose of your local variables. */
    
    String territories[MAX_TERRITORY];	// where the territory names are stored
    double life_expectancy_factors[MAX_TERRITORY][15]; // where the base life expectancy and life expectancy factors are stored

    int MAX_ROW = get_input(territories, life_expectancy_factors); // gets the total number of 
    
    int i, j; // it is for for-loop loops
    
  	int question_num = 1; 
  	
  	
  	// For questions that need temporary arrays 
  	double array_of_avg[14];	// Q1
  	double baseline_life_expectancy[MAX_ROW];	// Q5
	String copy_array[MAX_ROW];	// Q5
  	
    int q2_input[NUMBER_OF_CASES] = {70, -1, 80};
//	String q3_input[NUMBER_OF_CASES] = {"Philippines", "China", "Mars"};
//	String q4_input[NUMBER_OF_CASES] = {"Philippines", "China", "Mars"};
	int q5_input[NUMBER_OF_CASES] = {5, 500, 203};
    /* 
       Call the function that answers a question. Thereafter, use printf() to print the question 
       and the corresponding answer.  For example:

       expectancy = Q1_Answer(territory, param_x, param_y); // where expectancy, territory, param_x and param_y are local variables.

       printf("Q1: Which territory has the lowest baseline life expectancy?\n");
       printf("A1: %s %lf\n", territory, expectancy);       

       TEST CASES HARD REQUIREMENTS:
       You should have multiple test cases, i.e., functions calls to answer those 
       Questions that involve parameter(s).  There should be function calls with
       different actual paramete values.  For questions that require searching
       (linear or binary search), there should be a test case, i.e., a  function 
       call with a search key parameter that does not exist, i.e., NOT FOUND scenario.
    */
   	
   	 String factor_names[14] = {"Air pollution", "Ambient PM", "Ozone", "Household Air Pollution",
		 "Environmental/Occupational Hazards", "Occupational Hazards", "Unsafe WaH", "Metabolic Syndrome", 
		 "Dietary", "High Fasting Plasma Sugar", "Tobacco","Smoking", "Secondhand Smoke", "Unsafe Sex"};
                            
     
    printf("\n===================================QUESTION %d===================================\n", question_num);
    printf("Q1: After averaging each LE factor (excluding values from Global), which LE factor has the highest and lowest average?\n");
	printf("A%d: \n",question_num++);
	
   	mp_question_1(life_expectancy_factors, territories, MAX_ROW, array_of_avg);	// updates the array_of_avg array
   	// finds the min and max
    int max = find_max(array_of_avg, 14);
    int min = find_min(array_of_avg, 14);  
    
    printf("\nHighest Average  = %s \t-\t%lf\n", factor_names[max], array_of_avg[max]);
    printf("\nLowest Average   = %s \t-\t%lf\n", factor_names[min], array_of_avg[min]);
    
   
    
    printf("\n===================================QUESTION %d===================================\n", question_num);
    printf("Q2: How many territories would still have above <parameter_number> baseline life expectancy after deducting the impact of all changes in life expectancy factors?\n");
	printf("A%d: \n",question_num++);

	for(i = 0; i < NUMBER_OF_CASES; i++){
		 printf("\tTESTCASE %d \n", i+1);
		 int count = mp_question_2(life_expectancy_factors, territories, MAX_ROW, q2_input[i]);
		 if(count >= 0)
		 printf("\nThe number of territories above %d baseline life expectancy after deduction is: %d territories\n", q2_input[i], count);
		 else
		 printf("INVALID INPUT\n");
		 
	}
	
	printf("\n===================================QUESTION %d===================================\n", question_num);
	printf("Q3: What is the ranking of change in life expectancy factors of <name_of_territory> from highest to lowest?\n");
	printf("A%d: \n",question_num++);
    for(i = 0; i < NUMBER_OF_CASES; i++){
	//	 mp_question3(q3_input[i], territories, life_expectancy_factors);
	}
    
	printf("\n===================================QUESTION %d===================================\n", question_num);
	printf("Q4:  What is the life expectancy of <parameter_territory_name> before and after subtracting it with all the change in life expectancy factors?\n");
	printf("A%d: \n",question_num++);
    for(i = 0; i < NUMBER_OF_CASES; i++){
		// mp_question4(q4_input[i], territories, life_expectancy_factors);
	}
    
	
	

	printf("\n===================================QUESTION %d===================================\n", question_num);
	printf("Q5: Which are the top <parameter_number> with the highest baseline life expectancy? List them from highest to lowest.\n");
	printf("A%d: \n",question_num++);
	for(i = 0; i < NUMBER_OF_CASES; i++){
		printf("\tTESTCASE %d \n", i+1);
	int output = mp_question_5(life_expectancy_factors, territories, q5_input[i], baseline_life_expectancy, copy_array, MAX_ROW);
		if(output){
			for (j = 0; j < output; j++) {
    		printf("%d. ", j+1);
        	printf("%s\t\t %lf\n", copy_array[j], baseline_life_expectancy[j]);
    		}
		}
		else
		printf("INVALID INPUT\n");
	}
    
	

	return 0;
}
