/*
	CCPROG2 MP3 SOURCE CODE

    Do not forget to encode your name, section and date of submission.
    
    LASTNAME1, FIRSTNAME1:     FELIPE, GERARD CHISTIAN         SECTION1: S11A
    LASTNAME2, FIRSTNAME2:     GANAYO, REINMAN GEOFFREY        SECTION2: S11A
    
    DATE SUBMITTED     : March 31, 2024
		
	Rename this file using your last names in alphabetical order, for example CRUZ_TAN.c
		
	Make sure to compile your C source code with a -Wall directive.  
	   Example: CCPROG2> gcc -Wall LASTNAME1_LASTNAME2.c
	   
	Fix all warnings.  Do NOT run the program if you still have a warning.  You must have
	0 error, 0 warning before running the program.
	   
	DO NOT run your a.exe with input/output redirection anymore because MP3 is
   already supposed to be on text file processing.
   
   You should run your a.exe file simply as follows:
      Example: a 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// include your own header file
#include "FELIPE_GANAYO.h"   

/* Do NOT include other header files. */ 

/* 
	HARD REQUIREMENTS: NON-COMPLIANCE WILL MAKE YOUR SOLUTION INCORRECT or CAUSE POINT DEDUCTIONS!
	
	1. You must apply struct data type, and text file processing in MP Part 3 (MP3).
       a. Re-use the contents of your header file LASTNAME1_LASTNAME2.h.
       b. Follow the same hard requirements in MP2 on struct data type, and structure access using 
          * and ., and -> operators.
   2. Data should be read from SoGA_DATASET.txt using fscanf().
   3. The main() function should call the appropriate C function, and then call fprintf() to 
      write the answer to each question onto the OUTPUT_LASTNAME1_LASTNAME2.txt file. Numeric 
      answers with double data type must be written with 6 digits after the decimal point.  
   4. There should NOT be any printf() and scanf() statement in the entire source code, 
      not even in main(), and in the function that reads the SoGA data text file.  
   5. Document your codes with SENSIBLE comments.
   6. Use double data type (not float) for all floating point values/variables/functions/return type.
   7. Do NOT use any global variables.
   8. Do NOT use library functions that were NOT discussed in our class.
*/



/*
    ALL typedef declarations must be encoded in your header file.  
    All #define must be encoded in your header file.
    Do NOT place them in this file.
*/


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


/*  Purpose: Using file functions to access the Soga_DATASET to get the data and store it into an array of struct
    Parameters: 
                1. data[] - 1D array of structs that will contain the territory names and all life expectancy factors.
    Return type: int (number of rows read by the program to get MAX_ROW)

*/
 int get_input(struct dataTag data[]) {


	int index = 0;
	struct dataTag temp;
	
	FILE *fp; 
    fp = fopen("SoGA_DATASET.txt", "r");	// accessing (reading) the Soga_DATASET through file functions
    
	// using fscanf to store data
    while (fscanf(fp, "%s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf ", temp.territory_name, &temp.base_life_expectancy, &temp.air_pollution, &temp.ambient_PM, 
	&temp.ozone, &temp.household_air_pollution, &temp.environmental_occupational_hazards, &temp.occupational_hazards, &temp.unsafe_wash, &temp.metabolic_syndrome, &temp.dietary, 
	&temp.high_fasting_plasma_sugar, &temp.tobacco, &temp.smoking, &temp.secondhand_smoke, &temp.unsafe_sex) == 16) { // loop which gets territory names and stores them into a 1D String array
        
        data[index] = temp;
        index++;
    }
    
    fclose(fp); //closes the file pointer
    
    return index;  // returns the number of rows read by the program
} 

/* Q1:  Which territory has the highest change in life expectancy due to smoking that is not greater than <parameter_number> years?
   A1: 
       TEST CASE 1
       Bahamas 2.452218
       TEST CASE 2
       INVALID INPUT
       TEST CASE 3
       Global 2.5
*/

/*  Purpose: Finds the index where the highest double value that is less than or equal to tthe param_number is stored in the array of structs
    Parameters: 
                1. *data - a struct dataTag pointer that points to data[] which is an array of structs.
                2. n - int that will contain the number of rows read by the program
                3. param_number - a double variable that will contain the parameter number to be checked
    Return type: int (index where the highest value (that satisfies the parameters) is found)

*/
int Q1(struct dataTag *data, int n, double param_number) {
	int i;	
	
	// iniializes the values
	int max = -1;
	int found_max = 0; 

	
	
	if(param_number >= 0){  // checks if the given param_number is valid (non-negative number)
	
	//NOTE: We are not counting Global that is why it starts at index 1
		for (i = 1; i < n; i++) {
			if (!found_max){
				
				// finds first a value that satisfies the parameter (not greater than <parameter_number> years)
				if ((*(data + i)).smoking <= param_number){ // NOTE: Since the question states not greater than that means it is less than or equal to the param_number
					found_max = 1;
	        		max = i;
	    		}
			}
			
				//checks if it is higher than the current max_val while still satisfying the requirements (not greater than <parameter_number> years)
		        else if (found_max && (*(data + max)).smoking < (*(data + i)).smoking && (*(data + i)).smoking <= param_number){ 
		            max = i;
		    	}
    
		}
		
		return max; // returns the index where the highest number is found
	}
    else
    return -1;
	

}

/* Q2: What is the sum of the loss of life expectancy due to metabolic syndrome, dietary factors, and fasting plasma sugar for <parameter_territory_name>?
   A2: 
        TESTCASE 1
The sum of metabolic syndrome, dietary factors, and fasting plasma sugar for Singapore is: 5.495778
        TESTCASE 2
INVALID INPUT
        TESTCASE 3
The sum of metabolic syndrome, dietary factors, and fasting plasma sugar for China is: 7.732115
*/

/* Purpose: To find the sum of metabolic syndrome, dietary factors, and fasting plasma sugar for a given territory
   Parameters: 
                1. key - a String variable that will contain the territory name to be checked
                2. MAX_ROW - an int variable that will contain the number of rows read by the program
                3. data[] - 1D array of structs that will contain the territory names and all life expectancy factors.
   Return type: double (sum of metabolic syndrome, dietary factors, and fasting plasma sugar for the given territory)
*/
double Q2(String key, int MAX_ROW, data_struct *ptr)
{
   int i, index, found = -1;
   double sum;

   for(i = 0; i < MAX_ROW; i++) {
      if(strcmp(key, (ptr + i)->territory_name) == 0) {
         index = i;
         found = 1;
      }
   }

    if(found != 1) {
        return found;
    } else {

        sum = 0;
        //change this sum into a sum algorithm
        sum = (ptr + index)->metabolic_syndrome + (ptr + index)->dietary + (ptr + index)->high_fasting_plasma_sugar;

        return sum;
   }

}

/* Purpose: To find the index of the input in the array of structs using binary search
   Parameters: 
                1. input - a String variable that will contain the territory name to be checked
                2. temp_data[] - 1D array of structs that will contain the territory names and all life expectancy factors.
                3. MAX_ROW - an int variable that will contain the number of rows read by the program
   Return type: int (index of the territory name in the array of structs)
*/
int Q3_binary_search(String input, data_struct temp_data[], int MAX_ROW) {
    int low, high, mid;

    low = 0;
    high = MAX_ROW - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (strcmp(input, temp_data[mid].territory_name) == 0) {
            return mid; 
        } else if (strcmp(input, temp_data[mid].territory_name) < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

/* Q3: Does <parameter_territory_name> have a negligible change in life expectancy due to ozone (less than 0.01)?
   A3: 
        TESTCASE 1
YES
        TESTCASE 2
INVALID INPUT
        TESTCASE 3
NO
*/

/* Purpose: Uses selection sort to sort the array of structs in alphabetical order and then uses binary search to find the index of 
   the input in the array of structs
   Parameters: 
                1. input - The territory name inputted by the user
                2. temp_data[] - 1D array of structs that will contain the territory names and all life expectancy factors.
                3. MAX_ROW - an int variable that will contain the number of rows read by the program
   Return type: int (index of the territory name in the array of structs)
*/
void Q3(int MAX_ROW, data_struct data[], String input, int *index, data_struct temp_data[])
{
   int min, i, j;
   data_struct temp;

   for(i = 0; i < MAX_ROW; i++) {
      temp_data[i] = data[i];
   }

   for(i = 0; i < MAX_ROW - 1; i++) {
      min = i;
      for(j = i + 1; j < MAX_ROW; j++) {
         if(strcmp(temp_data[min].territory_name, temp_data[j].territory_name) > 0){
            min = j;
         }
      }

      if(i != min) {
         temp = temp_data[i];
         temp_data[i] = temp_data[min];
         temp_data[min] = temp;
      }
   }

   /*Apply binary search to find the index of key*/
   *index = Q3_binary_search(input, temp_data, MAX_ROW);

}

/* Q4: What is the average change in life expectancy due to air pollution for the top <parameter_number> territories with the highest
       baseline life expectancy? List the respective territories.
   A4: 
         TESTCASE 1
Average is: 0.316243
1. Singapore
2. Japan
3. Iceland
4. Switzerland
5. Italy
        TESTCASE 2
INVALID INPUT
        TESTCASE 3
Average is: 0.317137
1. Singapore
2. Japan
3. Iceland
*/

/* Purpose: Sorts the array then gets the average of the air pollution of the territories with highest base life expectancy
   Parameters: 
                1. input - An int variable that will contain the number of territories to show
                2. MAX_ROW - An int variable that will contain the number of rows read by the program
                3. data[] - 1D array of structs that will contain the territory names and all life expectancy factors.
                4. temp[] - 1D array of structs that will contain the territory names and all life expectancy factors.
   Return type: double (average of the air pollution of the top input number of territories with highest base life expectancy)
*/
double Q4(int input, int MAX_ROW, data_struct data[], data_struct temp[])
{
   int i, j, max;
   data_struct temp2;
   double sum = 0;

   
   if (input > MAX_ROW || input <= 0) {
        return -1;
   } else {
        for(i = 0; i < MAX_ROW; i++) {
            temp[i] = data[i];
        }

        //sorts the structs
        for(i = 0; i < MAX_ROW - 1; i++) {
            max = i;
            for(j = i + 1; j < MAX_ROW; j++) {
                if(temp[max].base_life_expectancy < temp[j].base_life_expectancy) {
                    max = j;
                }
            }

            if(i != max) {
                temp2 = temp[i];
                temp[i] = temp[max];
                temp[max] = temp2;

            }
        }

        //get the sum of air pollution of the top input number of territories with highest base life expectancy
        for(i = 0; i < input; i++) {
            sum += temp[i].air_pollution;
        }

        //returns the average of the air pollution of the top input number of territories with highest base life expectancy
        return sum / input;

        }

}

/* Q5: What is the minimum change in life expectancy due to environmental/occupational hazards that is greater than 3% of 
       the respective territories' baseline life expectancy?
   A5: 
        South_Africa    2.175128

*/

/*  Purpose: Finds the index where the lowest double value that is less than or equal to tthe param_number is stored in the array of structs
    Parameters: 
                1. data[] - 1D array of struct dataTag that will contain the territory name and all life expectancy factors.
                2. n - int that will contain the number of rows read by the program
    Return type: int (index where the lowest value (that satisfies the parameters) is found)

*/

int Q5(struct dataTag data[], int n) {
	
	int i;
	
	// initializes the values
	int min = 0;
	int found_min = 0;
	double life_expectancy_3percent[n];
	
		// stores the 3 percent of the base life expectancy of each territory to an array
		for(i = 0; i < n; i++){	
			life_expectancy_3percent[i] = data[i].base_life_expectancy * 0.03;
		}
		
		//NOTE: We are not counting Global that is why it starts at index 1
		for (i = 1; i < n; i++) {	// loop checks if the data satisfies the requirements (greater than 3% of the respective territories' baseline life expectancy)
		
			// finds first a value that satisfies the parameter (greater than 3% of the respective territories' baseline life expectancy)
			if (!found_min && data[i].environmental_occupational_hazards > life_expectancy_3percent[i]){
			
	            min = i;
	            found_min = 1; // found the first value that satisfies the parameters
	    	}
	    	//checks if it is higher than the current max_val while still satisfying the requirements (not greater than <parameter_number> years)
	        else if (found_min && (data[min].environmental_occupational_hazards > data[i].environmental_occupational_hazards) && data[i].environmental_occupational_hazards > life_expectancy_3percent[i]){
	        	min = i;
			}
	            
	    }
    
    return min; // returns the index where the highest number is fouund

}

   

int
main()
{
    /* Declare your own local variables. Describe the purpose of your local variables. */
    
    data_struct data[MAX_DATA]; // stores the data from the dataset
    int MAX_ROWS = get_input(data); // saves number of rows of dataset
	int question_num = 1; // counter for the question number
	
	
	int i, j; // it is for looping
	
	data_struct *ptr = data; // pointer to the array of structs
	
    double Q1_test_cases[num_of_cases] = {2.5, -23.0, 3.0}; // test cases for Q1
   
    
    String Q2_test_cases[num_of_cases] = {"Singapore", "MARS", "Philippines"}; // test cases for Q2
    double sum; // sum of factors for Q2
    
    int index = 0; // Saves index for Q3
    String Q3_test_cases[num_of_cases] = {"Bahamas", "MARS", "China"}; // test cases for Q3
    data_struct temp_data[MAX_ROWS]; // Sorted array for Q3
    
    data_struct temp[MAX_ROWS]; // Sorted array for Q4
    double average = 0; // Average for Q4
    int Q4_test_cases[num_of_cases] = {5, 0, 3}; // test cases for Q4
    
    /* 
       Call the function that answers a question. Thereafter, use fprintf() NOT printf()
       to output the the question and the corresponding answer onto OUTPUT_LASTNAME1_LASTNAME2.TXT.
       
       expectancy = Q1_Answer(territory, param_x, param_y); // where expectancy, territory, param_x and param_y are local variables.

       fprintf(fp, "Q1: Which territory has the lowest baseline life expectancy?\n");
       fprintf(fp, "A1: %s %lf\n", territory, expectancy);       
    

      You should have multiple test cases, i.e., functions calls to answer those 
      Questions that involve parameter(s).  
    */

	FILE *fp;
    fp = fopen("OUTPUT_FELIPE_GANAYO.txt", "w"); // making a file to print the output of the program
    
    // used fprinf
    fprintf(fp,"\n===================================QUESTION %d===================================\n", question_num);
    fprintf(fp,"Q1: Which territory has the highest change in life expectancy due to smoking that is not greater than <parameter_number> years?\n");
	fprintf(fp,"A%d: \n",question_num++);
	
	
    for(i = 0; i < num_of_cases; i++){
    	fprintf(fp,"\tTESTCASE %d \n", i+1);
    	int Q1_answer = Q1(ptr, MAX_ROWS, Q1_test_cases[i]);
    	
    	if(Q1_answer != -1)
    	fprintf(fp,"%s\t%.6lf\n", data[Q1_answer].territory_name, data[Q1_answer].smoking);
    	
    	else
    	fprintf(fp,"INVALID INPUT\n");
	}
	
	fprintf(fp,"\n===================================QUESTION %d===================================\n", question_num);
    fprintf(fp,"Q2: What is the sum of the loss of life expectancy due to metabolic syndrome, dietary factors, and fasting plasma sugar for <parameter_territory_name>?\n");
	fprintf(fp,"A%d: \n",question_num++);

    for(i = 0; i < num_of_cases; i++) {
        fprintf(fp,"\tTESTCASE %d \n", i+1);
        if(Q2(Q2_test_cases[i], MAX_ROWS, ptr) != -1) {
            sum = Q2(Q2_test_cases[i], MAX_ROWS, ptr);
            fprintf(fp,"The sum of metabolic syndrome, dietary factors, and fasting plasma sugar for %s is: ", Q2_test_cases[i]);
            fprintf(fp,"%.6lf\n\n", sum);
        } else {
            fprintf(fp,"INVALID INPUT\n");
        }
    }
    


    fprintf(fp,"\n===================================QUESTION %d===================================\n", question_num);
    fprintf(fp,"Q3: Does <parameter_territory_name> have a negligible change in life expectancy due to ozone (less than 0.01)?\n");
	fprintf(fp,"A%d: \n",question_num++);

    for(i = 0; i < num_of_cases; i++) {
        fprintf(fp,"\tTESTCASE %d \n", i+1);
        Q3(MAX_ROWS, data, Q3_test_cases[i], &index, temp_data);
        if(index != -1) {
            if(temp_data[index].ozone < 0.01) {
                fprintf(fp,"YES\n\n");
            } else {
                fprintf(fp,"NO\n\n");
            }
        } else {
            fprintf(fp,"INVALID INPUT\n\n");
        }
    }

    fprintf(fp,"\n===================================QUESTION %d===================================\n", question_num);
    fprintf(fp,"Q4: What is the average change in life expectancy due to air pollution for the top <parameter_number> territories with the highest baseline life expectancy?\n");
	fprintf(fp,"A%d: \n",question_num++);

    for(i = 0; i < num_of_cases; i++) {
        fprintf(fp,"\tTESTCASE %d \n", i+1);
        if(Q4(Q4_test_cases[i], MAX_ROWS, data, temp) == -1) {
            fprintf(fp,"INVALID INPUT\n");
        } else {
            average = Q4(Q4_test_cases[i], MAX_ROWS, data, temp);
            fprintf(fp,"Average is: %.6lf\n", average);
            for(j = 0; j < Q4_test_cases[i]; j++) {
                fprintf(fp,"%d. %s\n", j + 1, temp[j].territory_name);
            }
        }
    }
	
	
    fprintf(fp,"\n===================================QUESTION %d===================================\n", question_num);
    fprintf(fp,"Q5: What is the minimum change in life expectancy due to environmental/occupational hazards that is greater than 3 percent of the respective territories' baseline life expectancy?\n");
	fprintf(fp,"A%d: \n",question_num++);
	
    int Q5_answer = Q5(data, MAX_ROWS);
    fprintf(fp,"%s\t%lf\n", data[Q5_answer].territory_name, data[Q5_answer].environmental_occupational_hazards);
    
    
	fclose(fp); // closes the file pointer
   /* Don't forget to call fclose() before the return statement! */


	return 0;
}
