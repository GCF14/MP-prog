/*
	CCPROG2 MP2 header file (.h source code)
    
    Do not forget to encode your name, section and date of submission.
    
    LASTNAME1, FIRSTNAME1:     FELIPE, GERARD CHISTIAN         SECTION1: S11A
    LASTNAME2, FIRSTNAME2:     GANAYO, REINMAN GEOFFREY        SECTION2: S11A
    
    DATE SUBMITTED     :
		
	Rename this file using your last names in alphabetical order, for example CRUZ_TAN.h
		
	Make sure to include your header file in your C source code for MP Part 2.  
*/

/*
    Encode below this comment the following:
    
    1. #define directives
    2. typedef alias(es)for your string(s)
    3. declaration of your user-defined struct data type(s)
    4. typedef alias(es) for your struct data type(s)

    You may have as many typedef as you deem necessary.

    This header should NOT include the codes for any function definitions.  Function definitions
    should be encoded in your C source file only.
*/

/* You have to put an inline comment for each struct member as part of the documentation. */
#define MAX_DATA 1000
#define MAX_CHAR 36

#define num_of_cases 3

typedef char String[MAX_CHAR];


		 
struct dataTag {
	
    String territory_name; // this is for the name of the territory
    double base_life_expectancy; // this is for the base life expectancy of the territory
    double air_pollution; // this is for the Air pollution life expectancy factor
    double ambient_PM; // this is for the Ambient PM life expectancy factor
    double ozone; // this is for the Ozone life expectancy factor
    double household_air_pollution; // this is for the HAP(Household Air Pollution) life expectancy factor
    double environmental_occupational_hazards; // this is for the Environmental Occupational Hazards life expectancy factor
    double occupational_hazards; // this is for the Occupational Hazards life expectancy factor
    double unsafe_wash; // this is for the Unsafe_WaSH life expectancy factor
    double metabolic_syndrome; // this is for the Metabolic Syndrome life expectancy factor
    double dietary; // this is for the Dietary life expectancy factor
    double high_fasting_plasma_sugar; // this is for the High Fasting Plasma Sugar life expectancy factor
    double tobacco; // this is for the Tobacco life expectancy factor
    double smoking; // this is for the Smoking life expectancy factor
    double secondhand_smoke; // this is for the Secondhand Smoke life expectancy factor
    double unsafe_sex; // this is for the Unsafe Sex life expectancy factor

};

typedef struct dataTag data_struct;


