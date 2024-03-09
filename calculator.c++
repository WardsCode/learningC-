#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

double adding (queue<double>& stack) {
  double sum_stack = 0;
  while (!stack.empty()) {
      sum_stack += stack.front();
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
    if (new_number==0){
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

void record (double text_line){
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
  queue<double> stack;
  while (selection == 0){
    stack = empty_stack(stack);
    cout << "\n Please select the number of the operation you'd like to perform: \n";
    cout << " 1-Suma \n 2-Resta \n 3-Multiplicacion \n 4-Division \n 5-Close tool \n Enter the digit: ";
    cin >> selection;

    if (selection == 1 )
    { 
      stack = stacker(stack);
      result = adding(stack);
      cout << "The answer is: "  <<  result << "\n";
      record (result);
    }
    else if(selection == 2){
      stack = stacker(stack);
      result = subtract(stack);
      cout << "The answer is: "  <<  result << "\n";
    }
    else if (selection == 3){
      stack = stacker(stack);
      result = multiply(stack);
      cout << "The answer is: "  <<  result << "\n";
    }
    else if (selection == 4){
      stack = stacker(stack);
      result = divition(stack);
      cout << "The answer is: "  <<  result << "\n";
    }
    else if (selection == 5){
      cout << "Thanks for using this tool. Have a nice day.";
      break;
    }
    else{
      cout << "Error, Please select the correct options \n";
    }
  selection = 0;

  }
  return 0;
}