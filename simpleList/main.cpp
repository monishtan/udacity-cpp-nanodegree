#include <iostream>
using namespace std;

void printMenu(string name);

int main(int arg_count, char *args[]){

    if(arg_count>1){
        string name(args[1]);
        printMenu(name);
    }
    else{
        cout << "Username not supplied...exiting the program" << endl;
    }

    return 0;
}

void printMenu(string name){
    int choice;

    cout << "***************************\n";
    cout << " 1 - Print List.\n"; 
    cout << " 2 - Add to List.\n"; 
    cout << " 3 - Delete from List.\n"; 
    cout << " 4 - Quit.\n"; 
    cout << " Enter your Choice:";

    cin >> choice;
    
    if(choice == 4){
       exit(0); 
    }
    else{
        cout << "Sorry choice not implemened yet.\n"; 
    }
}