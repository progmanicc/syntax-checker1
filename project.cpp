#include <iostream>
#include <stack>
#include <fstream>


using namespace std;
bool balanced(string expression);
bool findPair(char leftSide, char rightSide);


int main()
{
    ifstream inData; //input file
    ofstream outData; //output file
    
    string values; //holds the file contents

    //get the file wrong.txt OR correct.txt
    inData.open("C:\\Users\\pip\\Desktop\\0_testPro\\wrong.txt");
    //outpuut file for testing
    //outData.open("C:\\Users\\pip\\Desktop\\0_testPro\\FileThatWasRead.txt");


    int counter = 0;
    
   //runs while not end of file
    while (!inData.eof())
    {
        inData >> values;
        //stores values in the output txt file
        //outData << values;
    }
    
    if (balanced(values))
    {
        cout << " no errors" << endl;
        cout << "Contents in file ---> " << values;
    }
        
    else
    {
        cout << "Syntax Errors" << endl;
        cout << "Contents in file ---> " << values;
    }
 
}

//reruens true is the expression is balanced
bool balanced(string expression)
{
    //stack of char
    stack<char> theStack;

    for (int i = 0; i < expression.length(); i += 1)
    {
        //if statemtns that ignore all other chars only focuses on {[()]}
        if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
            theStack.push(expression[i]);
        else if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')')
        {
            //if the stack is empty OR the expression does not have a matching symbol 
            //findpair takes the top value of stack and the next value in the expression
            if (theStack.empty() || !findPair(theStack.top(), expression[i]))
                return false;
            theStack.pop();
        }
    }

    return theStack.empty() ? true:false;
}

//returns false 
bool findPair(char leftSide, char rightSide)
{
    if (leftSide == '{' && rightSide == '}')
        return true;
    else if (leftSide == '[' && rightSide == ']')
        return true;
    else if (leftSide == '(' && rightSide == ')')
        return true;
   

    return false;
}
