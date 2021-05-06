#include <iostream>
#include <cassert>
#include <string>
using namespace std;


template <typename Elem> class Stack 
{ 
  private: 
    int maxSize; 
     
    Elem *listArray; 
  public: 
  int top; 
    Stack(int size = 255) 
  { 
    maxSize = size; 
    top = 0; 
    listArray = new Elem[size]; 
    }
  ~Stack() { delete [] listArray; } 
  void clear() {
     top = 0; 
     } 
  void push(const Elem& it) { 
    if(top == maxSize){
      cout<<"Stack is full"<<endl;
    }
    listArray[top++] = it; 
    }
  Elem pop() { 
    if(top == 0){
      cout<<"Stack is empty"<<endl;
    }
    return listArray[--top]; 
    }
  const Elem& topValue() const { 
    if(top == 0){
      cout<<"Stack is empty"<<endl;
    }
    return listArray[top-1]; }
  int length() const { 
    return top; 
  } 
  Elem elm(int i){
    return listArray[i];
  }
  
};

Stack<char> str;


void bottom(char t){
  if(str.top==0){
    str.push(t);
  }
  else{
    char temp=str.topValue();
    str.pop();
    bottom(t);
    str.push(temp);
  }
}

void reverse(){
  
  if(str.top==0){
    return;
  }
  char temp=str.topValue();
  str.pop();
  reverse();
  bottom(temp);
  

}



int main(){
  while(true){
    str.clear();
  string userInput;
  bool correct = true;
  cout<<"enter string: ";
  cin>>userInput;
  for(int i=0; i<userInput.size();i++){
    str.push(userInput[i]);
  }

  reverse();
  cout<<"In reverse: ";
  for(int i=0; i<userInput.size();i++){
    cout<<str.elm(i);
  }
    cout<<endl<<endl;
  }

}














