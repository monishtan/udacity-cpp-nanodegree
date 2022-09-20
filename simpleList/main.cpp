#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_menu(string name);
void print_list();
void add_item();
void delete_item();

vector<string> list;
string name;

int main(int arg_count, char *args[]){

    if(arg_count>1){
        name = string(args[1]);
        print_menu(name);
    }
    else{
        cout << "Username not supplied...exiting the program" << endl;
    }

    return 0;
}

void print_menu(string name){
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
    else if(choice == 2){
        add_item();
    }
    else if(choice == 3){
        delete_item();
    }
    else if(choice == 1){
        print_list();
    }
    else{
        cout << "Sorry choice not implemened yet.\n"; 
    }
}

void print_list(){
    cout<< "\n\n\n\n";
    cout<< "**** Printing List ****\n";

    for(int i=0; i<list.size(); i++){
        cout<< list[i] << "\n";
    }

    cout<< "\nM - Menu \n";
    char choice;
    cin>> choice;

    if(choice == 'M' || choice == 'm'){
        print_menu(name);
    }
    else{
        cout<< "Invalid choice. Quitting...\n\n";
    }
}


void add_item(){
    cout<< "\n\n\n\n";
    cout<< "**** Add Item ****\n";
    cout<< "Type an item and press enter: ";

    string item;
    cin >> item;

    list.push_back(item);

    cout<<"Successfully added item to the list \n\n\n";
    cin.clear();

    print_menu(name);
}

void delete_item(){
    cout<< "**** Delete Item ****\n";
    cout<< "Select an item index number to delete: \n";

    if(list.size()){
        for(int i=0; i<list.size(); i++){
            cout<< i << ": " << list[i] << endl;
        }
    } 
    else{
        cout<< "No items to delete.\n";
    }

    int index;
    cin>> index;

    print_menu(name);
}