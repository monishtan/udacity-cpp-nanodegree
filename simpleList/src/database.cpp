#include "include/database.h"

void Database::write(vector<vector<string>> mainList){
    ofstream db;
    db.open("db/lists.sl");

    if(db.is_open()){
        for(int i=0; i<mainList.size(); i++){
            for(int j=0; j<mainList[i].size(); j++){
                if(j==0){
                    db << "#" << mainList[i][j] << "\n";
                }
                else {
                    db << mainList[i][j] << "\n";
                }
            }
            db << "%\n";
        }
    }
    else{
        cout << "Cannot open file for writing.\n";
    }

    db.close();
}

vector<vector<string>> Database::read(){
    string line;
    ifstream db;
    db.open("db/lists.sl");

    vector<string> userList;

    if(db.is_open()){
        while(getline(db,line,'\n')){
            if(line.front()=='#'){
                cout << "Found a Hashtag: " << line << "\n";
                line.erase(line.begin());
                userList.push_back(line);
            }
            else if(line.front()=='%'){
                cout << "Found a Percentage: " << line << "\n";
                mainList.push_back(userList);
                userList.clear();
            } else {
                cout << "Found an item: " << line << "\n";
                userList.push_back(line);
            }
        }
    }
    else{
        cout << "Cannot open file for reading.";
    }

    db.close();

    return mainList;

}

