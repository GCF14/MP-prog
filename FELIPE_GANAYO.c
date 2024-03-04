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
#define Max_Char 36

#define Max_Rows 203
#define Max_Columns 16

/*
    You may declare any typedef that you need below this comment.
*/
typedef char String[Max_Char]; 


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

void printCountryIndex(int index, String sMaxCountries[]) {
    int nNumOfCharacters = strlen(sMaxCountries[index]);
    int i;

    for (i = 0; i < nNumOfCharacters; i++) {
        printf("%c", sMaxCountries[index][i]);
    }

}

void Get_Input (String Territories[], double LifeExpectancy_Factors[][15]) {
		
		int i = 0, j = 0;
		String Temp_String;
    	double Temp_Double;
    	
		while (scanf(" %35s", Temp_String) == 1) {
    		strcpy(Territories[i], Temp_String);
				for (j = 0; j < 15; j++) {
					if (scanf("%lf", &Temp_Double) == 1) 
            		LifeExpectancy_Factors[i][j] = Temp_Double;
       		 	}
       	 	i++;
		}
		
	}

double FindAvg(double A[][15], int Column_Index) {
    int i;
    double sum = 0.0;

    for (i = 1; i < 203; i++) {
    //	printf("\nSAD = %lf\n", A[i][Column_Index]);
        sum += A[i][Column_Index];
    }
	double avg;
    avg = sum / 202;
	
    return avg;
}


int FindMin (double A[],int n) {
	int i;
	int min = 0;
	for (i = 0; i < n; i++){
		if (A[min] > A[i])
			min = i;
	}
	
	return min;
}

int FindMax(double A[],int n) {
	int i;
	int max = 0;
	for (i = 0; i < n; i++){
		if (A[max] < A[i])
			max = i;
	}
	
	return max;
}

double FindSum (double A[],int n) {
	int i;
	double sum = 0;
	for (i = 1; i < n; i++){
		sum += A[i];
	}
	
	return sum;
}

int countAbove_Num(double arr[], int size, float condition) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > condition) {
            count++;
        }
    }

    return count;
}

void swapElements(String arr[], double factors[], int index1, int index2) {
    String temp;
    double tempFactor;

    strcpy(temp, arr[index1]);
    strcpy(arr[index1], arr[index2]);
    strcpy(arr[index2], temp);

    tempFactor = factors[index1];
    factors[index1] = factors[index2];
    factors[index2] = tempFactor;
}

void SelectionSort(String Territories[], double LE_Factors[], int n) {
    int i, j, min;

    for (i = 0; i < n - 1; i++) {
        min = i; // min is the index of the lowest element

        for (j = i + 1; j < n; j++)
            if (LE_Factors[min] < LE_Factors[j])
                min = j;

        // Swap if needed
        if (i != min) {
            swapElements(Territories, LE_Factors, i, min);
        }
    }
}

void MP_Question_1 (double A[][15], String S[]) {
	
	int i;

	double ArrayOfAvg [14];
	double average;
	

		
		for (i = 0; i < Max_Rows; i++) {
        average = FindAvg(A, i + 1);
        ArrayOfAvg[i] = average;
    	}

	int max = FindMax (ArrayOfAvg, 14);
	int min = FindMin (ArrayOfAvg, 14);
	

	printf("\nMAX = %lf\n", ArrayOfAvg[max]);

	printf("\nMIN = %lf\n", ArrayOfAvg[min]);
	
	
}

void MP_Question_2 (double A[][15], String S[], float condition) {
	
	int i, j = 0;
	double ArrayOfSum [202];
	
	
	for (i = 1; i < 203; i++){
		ArrayOfSum[j]	=	A[i][0] - FindSum(A[i],15);
		j++;
	}
	
	int n = sizeof (ArrayOfSum) / sizeof (ArrayOfSum[0]); 
	int count = countAbove_Num(ArrayOfSum, n, condition);

	printf("\nTHERE ARE %d COUNTRIES ABOVE %.1f LIFE EXPECTANCY AFTER DEDUCTION\n", count, condition);

}


	
	
void MP_Question_5 (double A[][15], String S[]) {
	
	int i;
	double Baseline_LifeExpectancy[202];
	String Copy_Array[202];
	
	for(i = 0; i < 202; i++ ){
		Baseline_LifeExpectancy[i] = A[i+1][0];
		strcpy(Copy_Array[i],S[i+1]);
	}
	
	SelectionSort(Copy_Array, Baseline_LifeExpectancy, 202);
	
	for(i = 0; i < 10; i++ ){
		printCountryIndex(i, Copy_Array);
		printf("\t%.8lf\n", Baseline_LifeExpectancy[i]);
	}
	

}
int
main()
{
    /* Declare your own local variables. Describe the purpose of your local variables. */
    
    String Territories[Max_Rows]; 
    double LifeExpectancy_Factors[Max_Rows][15]; 
    
    
	Get_Input (Territories, LifeExpectancy_Factors);
    
    
   	float condition = 70;
    
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

	MP_Question_1 (LifeExpectancy_Factors, Territories);
	MP_Question_2 (LifeExpectancy_Factors, Territories, condition);
	MP_Question_5 (LifeExpectancy_Factors, Territories);
	

	return 0;
}
