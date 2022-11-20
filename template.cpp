#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <stdexcept>

using namespace std;

//prototype of generic functions
template <typename T> T multiply(T n1, T n2);
template <typename T> T divide(T numerator, T denominator);

//prototype of generic functions
template <class type> type add(type num1, type num2); // prototype: template function
template <typename T> T subtract(T num1, T num2); // prototype: template function

int main ()
{
    cout<<"test on int data type. \n";
  int num1, num2, answer;

  cout << "Please enter integer 1 : ";
  cin >> num1;
  cout << "Please enter integer 2 : ";
  cin >> num2;

  answer = add(num1, num2);
  cout << "The sum of " << num1 << " & " << num2 << " = " << answer<<endl;

  answer = subtract(num1, num2);
  cout << "The difference of " << num1 << " & " << num2 << " = " << answer<<endl;

  answer = multiply(num1, num2);
  cout << "The multiplication of " << num1 << " * " << num2 << " = " << answer;

  try
  {
     answer = divide(num1, num2);
     cout << "\nThe quotient of " << num1 << " / " << num2 << " = " << answer;
  }
  catch(const runtime_error& e)
  {
      cout<<"\nException thrown as "<<e.what()<<endl;
  }                                  //.what() print out error message



  cout<<"\n\n***** test on double data type. \n";
  double dnum1, dnum2, danswer;
  // test by changing float to int or double. Do you have any other change in the program?
  cout << "Please enter double type data 1 : ";
  cin >> dnum1;
  cout << "Please enter double type data 2 : ";
  cin >> dnum2;

  danswer = multiply(dnum1, dnum2);
  cout << "The multiplication of " << dnum1 << " * " << dnum2 << " = " << danswer;


  try
  {
     danswer = divide(dnum1, dnum2);
     cout << "\nThe quotient of " << dnum1 << " / " << dnum2 << " = " << danswer;
  }
  catch(const runtime_error& e)
  {
      cout<<"\nException thrown as "<<e.what()<<endl;
  }

  return 0;
}


//define generic functions
// function's class/template parameter:T    return type:T
template <typename T> T multiply(T n1, T n2)
{
    T result = n1*n2;
    return result;
}

template <typename T> T divide(T numerator, T denominator)
{
       T result;

       if(static_cast<double>(denominator) != 0.0)
       {
           result = numerator/denominator;
           return result;
       }
       else
       {
           throw runtime_error("divided by 0 error!");  //keyword throw followed by an operand of the type of exception
       }       // override the .what() error message
}

//define generic functions
// class/template parameter:type    return:type function_name:add
template <class type> type add(type num1, type num2)
{

  type result = num1 + num2;
  return result;
}

template <typename T> T subtract(T num1, T num2)
{

  T result = num1 - num2;
  return result;
}


// Add two more functions for multiplication and division in the code and submit it as this modules assessment code to instructor
