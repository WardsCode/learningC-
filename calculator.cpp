#include <iostream>
#include <queue>
#include <fstream>          //Here we add the libraries needed for our code to work
#include <string>

using namespace std;

//Lets create the functions for our operations.

double adding (queue<double>& stack) {
  double sum_stack = 0;
  while (!stack.empty()) {
      sum_stack += stack.front();       //adding loops to summ all numbers in the queque, starting for the FIFO
      stack.pop();
  }
  
  return sum_stack;
};

double subtract (queue<double>& stack) {
  double sub_stack = stack.front();
  stack.pop();
  while (!stack.empty()) {
    sub_stack -= stack.front();
    stack.pop();
  }
  return sub_stack;
};

double multiply (queue<double>& stack) {
  double mult_stack = stack.front();
  stack.pop();
  while (!stack.empty()) {
      mult_stack *= stack.front();
      stack.pop();
  }
  
  return mult_stack;
};

double divition (queue<double>& stack) {
  double div_stack = stack.front();
  stack.pop();
  while (!stack.empty()) {
      div_stack /= stack.front();
      stack.pop();
  }
  
  return div_stack;
};

queue<double> stacker (queue<double> stack){
  int counter = 0;
  int new_number = -1;
  
  while (new_number != 0 )
  {
    counter ++;
    cout << "Add number " << counter << " and finish with 0 for an answer \n";
    cin >> new_number;
    if (new_number == 0){
      break;
    }
    else{
      stack.push(new_number);
    }   
  };

  return stack;

};

queue<double> empty_stack (queue<double> stack){
  while (!stack.empty()) {
    stack.pop();
  }
  return stack;
};

void record (double text_line){                   //AS a strech exercise, this will add the result into a text file. Can be use for history
  auto str = to_string(text_line);
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "last result: " << text_line;
  myfile.close();
}


int main() {
  double result;
  cout << "Welcome to the C++ small calculator \n";
  int selection = 0; 
  queue<double> stack;          //Here we create a Queue - Ignore the name of it. it was a stack before and I found that a Queue works better. 
  while (selection == 0){
    stack = empty_stack(stack);
    cout << "\n Please select the number of the operation you'd like to perform: \n";
    cout << " 1- Add \n 2-Substract \n 3-Multiply \n 4-Division \n 5-Close tool \n Enter the digit: ";
    cin >> selection;

    if (selection == 1 )
    { 
      stack = stacker(stack);               //here we add all numebres needed for the operation, 
      result = adding(stack);               //once all numbers are input, we add them
      cout << "The answer is: "  <<  result << "\n";    //we print the answer to the console
      record (result);                      //record the result in the text file
    }
    else if(selection == 2){
      stack = stacker(stack);
      result = subtract(stack);
      cout << "The answer is: "  <<  result << "\n";
      record (result);
    }
    else if (selection == 3){
      stack = stacker(stack);
      result = multiply(stack);
      cout << "The answer is: "  <<  result << "\n";
      record (result);
    }
    else if (selection == 4){
      stack = stacker(stack);
      result = divition(stack);
      cout << "The answer is: "  <<  result << "\n";
      record (result);
    }
    else if (selection == 5){
      cout << "Thanks for using this tool. Have a nice day.";
      break;
    }
    else{
      cout << "Error, Please select the correct options \n";          //in case the user selectes a wrong option, this messague will appear
    }
  selection = 0;

  }
  return 0;
}