/*
Author: Jyoti gurung
Date: 3/16/22
Description: Hash Table (Student database; add, remove and print info) and a Random Student Generator
*/
#include <iostream>
#include <cstring>
#include <array>

using namespace std;

//Node set up for student data
struct Node {
  char *firstname;
  char *secondname;
  int id;
  double gpa;
  Node *next;
};

//set up the functions
void add();
void print();
void remove();
void randomStudent();

int main() {

//set up the hash tables and make em null
srand(time(NULL));  
Node** hashtable;
hashtable = new Node* [151];
for (int i = 0; i< 151; i++) {
  hashtable[i] = NULL;//making whole table null;
}

Node** hashtable2;
hashtable2 = new Node*[302];
for (int i = 0; i< 302; i++) {
  hashtable2[i] = NULL;//making whole table null;
}

int collisioncount;
  
  //use a while loop that keeps on going until you quit the program (change of int action when you enter a certain #), a nested switch statement that links numbers to a certain action (add, remove etc)
  int action = -1;
  while (action != 0) {
    cout << endl << "1:ADD 2:PRINT 3:REMOVE 4:RANDOM STUDENT 5:QUIT" << endl;
    cin >> action;

    switch(action){
      case 1:
        cout << "Add";
        break;
      case 2:
        cout << "Print";
        break;
      case 3:
        cout << "Remove";
        break;
      case 4:
        cout << "Random Student";
        break;
      case 5:
        action = 0;
        break;
    }
    cout << endl;

  //add student
  if (action == 1) {
  
    cout << endl << "Enter line by line: First Name, Last Name, Student ID & GPA!" << endl;
    char firstName[16];
    char lastName[16];
    int id;
    float gpa;
    cin >> firstName;
    cin >> lastName;
    cin >> id;
    cin >> gpa;
  
    int num = 0;
    int length = strlen(firstName);
        
    for (int i = 0; i < length; i++) {
      num = num + firstName[i];
    }
    
    num = num % 100;
    Node* head = new Node();
    head->firstname = firstName;
    head->secondname = lastName;
    head->id = id;
    head->gpa = gpa;
    head->next = NULL;
  
    if(hashtable[num] == NULL) {
      hashtable[num] = head;
      cout<<"done" << endl;
    }
    else {
    	collisioncount++;
    	Node* temp = hashtable[num];
    	while(temp != NULL) {
    	  if (temp->next == NULL) {
    	    temp->next = head;
    	    break;
    	  }
    	  temp = temp->next;
    	}
    }
    
    Node* temp = hashtable[num];
    while(temp != NULL) {
  	  temp = temp->next;
    }
    
    if(collisioncount > 3) {
    	for(int i = 0; i < 151; i++) {
    	  hashtable2[i*2] = hashtable[i];
    	}
    }
  }

  //print students
  if (action == 2) {
  
    if(collisioncount > 3) {
    	for(int i = 0; i < 302; i++) {
    	  Node* temp = hashtable2[i];
    	  while(temp != NULL) {
    	    cout<< temp->firstname << endl;
    	    cout<< temp->secondname<< endl;
    	    cout<< temp->id << endl;
    	    cout<< temp->gpa<< endl;
    	    temp = temp->next;
    	  }
    	}
    }
    else {
    	for(int i = 0; i < 151; i++) {
    	  if(hashtable[i] != NULL) {
    	    Node* temp = hashtable[i];
    	    while(temp != NULL) {
    	      cout<<temp->firstname << endl;
    	      cout<< temp->secondname<<endl;
    	      cout<< temp->id << endl;
    	      cout<< temp->gpa << endl;
    	      temp = temp->next;
    	    }
    	  }
      }
    }

    }

    //remove student
    if (action == 3) {
      
    }
  
    //add a random student
    if (action == 4) {
      
    }
    
  }
  
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