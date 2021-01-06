/*****************************************************************
//
//  NAME:        Joshua Paino
//
//  HOMEWORK:    8
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 20, 2020
//
//  FILE:        homework8.cpp
//
//  DESCRIPTION:
//   Takes a user maximum float input value that represents Kelvin
//   and generates a conversion table of Kelvin vs Fahrenheit up to
//   to the user input in intervals of 50 Kelvin.
//
****************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int user_interface(void);
void convert(double, double &);
void print_table(int length);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Main method that will call the user_interface
//                 and print_table functions.
//                 
//
//  Parameters:    argc (int): represents the number of arguments
//                             that is being passed through.
//
//                 char (*argv[]): represents the arguements that is
//                                 being passed through in a string
//                                 array.
//
//  Return values:  0 : the functions user_interface and print_table
//                      have been called.
//                 -1 : the functions could not be called.
//
****************************************************************/

int main (int argc, char *argv[])
{
    
    int input = user_interface();

    print_table(input);

    return 0;
}

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   Interface that will request an integer from  
//                 the user that represents a Kelvin value.
//                 If the input is invalid, user must input again.
//                 Invalid Check variable will flag if there is 
//                 a char or an integer less than or equal to 0
//                 in the input.                                         
//
//  Parameters:    
//
//
//     	      	   
//     	       	       	       	    
//    
//
//  Return values:  input (int): the int value given by the user.
//     	       	       	
//                 
//
****************************************************************/

int user_interface(void)
{
    int input;
    int invalidCheck;
    
    cout << "Generate a table of Kelvin vs. Fahrenheit conversions." << endl;
    cout << "Length of table will be based on Kelvin temperature that you provide, presenting Kelvin values of increments of 50 Kelvin" << endl;

    cout << "Enter a maximum Kelvin output: " << endl;

    do
    {
        invalidCheck = 0;
  
        cin >> input;

        if (cin.fail())
        {
            invalidCheck = 1;
            cout << "NOT A NUMBER.  Enter a new value:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');       
        }
        else if (cin.good())
        {
            if (input <= 0)
            {
                 invalidCheck = 1;
                 cout << "INVALID INPUT.  Enter a new value:" << endl;
                 cin.clear();
            }
        }
    }
    while (invalidCheck == 1);
    
    return input;
}

/*****************************************************************
//
//  Function name: convert
//
//  DESCRIPTION:   Converts the double parameter representing
//                 a Kelvin value and converts it to Fahrenheit
//                 using the Kelvin to Fahrenheit formula.
//                 
//
//  Parameters:    kelvin (double): takes a kelvin value from the
//                                  the user to use in the formula.
//
//                 fahrenheit (double &): the product of the Kelvin
//                                        to farhrenheit formula. Value
//                                        alters via passing by reference.                 
//  
//  Return values: 
//                                       
//  
//                             
//
****************************************************************/

void convert(double kelvin, double & fahrenheit)
{   
    fahrenheit = 1.8 * (kelvin - 273.15) + 32;
}


/*****************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION: Produces table of Kelvin vs Fahrenheit that starts
//               at 0 and goes up to the Kelvin value given by the user.
//
//  Parameters: length (int): the user input value that will be used to
//                           identify how many values to generate.
//                 
//  Return values:  
//  
//                             
//
****************************************************************/

void print_table(int length)
{
    double startValue;
    double result;
    
    startValue = 0.00;
    result = 0.00;

    cout << "   KELVIN" << setw(25) << "FAHRENHEIT" << endl;

    for (startValue = 0.00; startValue <= length; startValue = startValue + 50) 
    {
        convert(startValue, result);

        cout.precision(2);
        cout << fixed << showpoint << setw(9) << startValue << setw(25) << result << endl;
    }
}
