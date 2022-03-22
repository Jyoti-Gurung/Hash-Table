/*
Author: Jyoti gurung
Date: 3/16/22
Description: Hash Table (Student database; add, remove and print info) and a Random Student Generator
*/
#include <iostream>

using namespace std;

//set up the functions
void add();
void print();
void remove();
void randomStudent();

int main() {

  //use a while loop that keeps on going until you quit the program (change of int action when you enter a certain #), a nested switch statement that links numbers to a certain action (add, remove etc)
  int action = -1;
  while (action != 0) {
    cout << endl << "1:ADD 2:PRINT 3:REMOVE 4:RANDOM STUDENT 5:QUIT" << endl;
    cin >> action;

    switch(action){
      case 1:
        add();
        break;
      case 2:
        cout << "Print";
        break;
      case 3:
        cout << "Remove";
        break;
      case 4:
        randomStudent();
        break;
      case 5:
        action = 0;
        break;
    }
    cout << endl;
  }

}

void add() {

  cout << endl << "Enter line by line: First Name, Last Name, Student ID & GPA!" << endl;
  char firstName[16];
  char lastName[16];
  int id;
  float gpa;
  cin >> firstName;
  cin >> lastName;
  cin >> id;
  cin >> gpa;
  
}

void print() {
  
}

void remove() {
  
}

void randomStudent() {

  int randomPick = rand() % 5;
  char firstNames[5][5] = {{'L','u','f','f','y'}, {'R','o','b','i','n'}, {'S','a','n','j','i'}, {'U','s','s','o','p'}, {'B','r','o','o','k'}};
  char lastNames[5][5] = {{'S','a','n',' ',' '}, {'K','u','n',' ',' '}, {'S','a','m','a',' '}, {'B','a','d',' ',' '}, {'J','u','i','c','e'}};
  char ids[5][6] = {{'3','6','5','5','6','7'}, {'4','5','6','0','6','6'}, {'6','6','6','4','6','7'}, {'4','2','0','6','4','3'}, {'1','2','6','3','1','2'}};
  char gpas[5][4] = {{'3','.','0','5'}, {'3','.','0','0'}, {'2','.','0','9'}, {'4','.','0','0'}, {'3','.','5','9'}};

  for (int i = 0; i < 5; i++) {
    cout << firstNames[randomPick][i];
  }
  randomPick = rand() % 5;
  cout << endl;
  for (int i = 0; i < 5; i++) {
    cout << lastNames[randomPick][i];
  }
  randomPick = rand() % 5;
  cout << endl;
  for (int i = 0; i < 6; i++) {
    cout << ids[randomPick][i];
  }
  randomPick = rand() % 5;
  cout << endl;
  for (int i = 0; i < 4; i++) {
    cout << gpas[randomPick][i];
  }
  
}