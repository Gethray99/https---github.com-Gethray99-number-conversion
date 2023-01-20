/*
  Name : Gethwan Suriyawansa
*/

#include <iostream>
#include<map>
#include<regex>
#include<fstream>
#include<string>
using namespace std;

//this will map the string character to a decimal value
map<char, int> change_to_int = 
{
    {'I', 1},{'i',1},{'V', 5},{'v',5},{'X', 10},{'x',10},{'L', 50},{'l',50},{'C', 100},{'c',100}
};


int convert_to_arabic(string roman) {
    int result = 0;

    for (int i = 0; i < roman.length(); i++) 
    {
        int current = change_to_int[roman[i]];
        int next = (i + 1 < roman.length()) ? change_to_int[roman[i + 1]] : 0; //this will check the next element in the string array 
        //and if its different than the previous roman value next will be higher than the current value 
        if (current < next) 
        {
            result = result + (next - current);
            i++; // this will increase the "i" variable value and end the for loop because when "next" get higher when 
            //its the last element in the roman number(if its a valid number)   
        }
        else 
        {
            result = result + current;
        }
    }
    return result;
}


bool roman_validity(string roman) 
{
    regex pattern("^C{0,1}(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$"); //this will use this pattern to check is the roman value is valid 
    /*mechanisum of regex is as follow 
    -> at the begining of the string C can occur 0 to 1 times since text file will only consist number to 100.
    -> X/L/XL/CX in any order these can occur 0 to 3 times
    -> V/I/IV/IX can be in any order and occur 0 to 3 times

    if these conditions are fulfiled then we can consider that number is a valid roman number
    
    */
    return regex_match(roman, pattern);
}

int main() {
    
    string buffer;
    string roman;
    
    
    ifstream file1("roman_numbers.txt");
    while (!file1.eof())
    {
        getline(file1, buffer);
        roman = buffer;
        cout << roman << " = ";
        transform(roman.begin(), roman.end(), roman.begin(), ::toupper); //this will convert all string characters to uppercase
        if (roman_validity(roman)) {

            (convert_to_arabic(roman) < 100 ? cout << convert_to_arabic(roman) : cout << "Higher than 100"); 
            cout << endl;

        }
        else {
            cout << "error"<< endl;
        }


    } 

    

 
    return 0;
}