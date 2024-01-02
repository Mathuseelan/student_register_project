#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;
int createid();
int deleteid();
int editid();
int viewlist();

int select()
{
    int choice;
    cout << "Hello!" << endl; 
    cout << "1. Create New student ID" << endl;
    cout << "2. Delete a student ID" << endl;
    cout << "3. Edit a student ID" << endl;
    cout << "4. View full student's list" << endl;
    cout << "5. Stop the process!! to see te results" << endl << endl;
    cout << "Enter 1 - 5 for your choice" << endl; 
    cin >> choice;
    
    switch(choice)
    {
        case 1:{
            cout << endl;
            createid();
            break;
        }
        case 2:{
            cout << endl;
            deleteid();
            break;
            
        }
        case 3:{
            cout << endl;
            editid();
            
            break;
            
        }
        case 4:{
            cout << endl;
            viewlist();
            break;
            
        }
        case 5:{
            cout << "You're done !! Bye" <<endl;
            break;
            
        }
        default:
        cout << "Invalid choice!" << endl;
    
    }
    return 0;
    
}


int createid()
{
    string name,address;
    int rollno;
    
    cin.ignore();
    
    cout << "Enter Name: " << endl;
    getline(cin,name); 
    
    cout << "Enter address: " << endl;
    getline(cin,address);
    
    cout << "Enter Roll: " << endl;
    cin >> rollno;
    
    fstream myFile;
    myFile.open("stdregister.txt",ios::out | ios::app);
    myFile << endl;
    myFile <<"Roll no: " << rollno << endl << "Name: " << name <<  endl <<"Address: " << address << endl;
    myFile.close();
    cout << endl << "Student ID created successfully" << endl;
    select();
    return 0;
    
}

int deleteid()
{
    cout << "Enter the roll number of the student to delete: " << endl;
    int rollnumberToDelete;
    cin >> rollnumberToDelete;

    ifstream temp_file;
    temp_file.open("stdregister.txt");
    vector<string> lines;
    string line;

    while (getline(temp_file, line))
    {
        int found = line.find("Roll no: ");
        if (found != string::npos)
        {  
           int rollnum = stoi(line.substr(found + 8));
            if (rollnum == rollnumberToDelete)
            {
                getline(temp_file, line);
                getline(temp_file, line);
                getline(temp_file, line); 
                continue;
            }
        }
        lines.push_back(line);
    }
    temp_file.close();

    ofstream temp_file2;
    temp_file2.open("stdregister.txt");
    for (int i=0;i<lines.size();i++)
    {
        temp_file2 << lines[i] << endl;
    }
    temp_file2.close();

    cout << "Student with Roll number " << rollnumberToDelete << " deleted successfully." << endl;
    select();
    return 0;
}

int editid()
{
    int rollNumberToEdit;
    cout << " Enter the Roll no of the student to edit" << endl;
    cin >> rollNumberToEdit;
    ifstream tempfile("stdregister.txt");
    vector<string> lines;
    string line;
    
    int rollno;
    cout << "Enter the correct Roll no: "<< endl;
    cin >> rollno;
    
    cin.ignore();

    string name;
    cout << "Enter the correct Name: " << endl;
    getline(cin,name);
    
    string address;
    cout << "Enter the correct Address: "<<endl;
    getline(cin,address);

    while (getline(tempfile, line))
    {
        int found = line.find("Roll no: ");
        if (found != string::npos)
        {  
            int rollnum = stoi(line.substr(found + 8));
            if (rollnum == rollNumberToEdit)
            {
                 getline(tempfile, line);
                 getline(tempfile, line);
                
                lines.push_back("Roll no: " + to_string(rollno));
                lines.push_back("Name: " + name);
                lines.push_back("Address: " + address);
                continue;
            }
        }
        
        lines.push_back(line);
    }
    tempfile.close();
        
    ofstream tempfile2;
    tempfile2.open("stdregister.txt");
    for (int i=0;i<lines.size();i++)
    {
        tempfile2 << lines[i] << endl;
    }
    tempfile2.close();
    select();
    
    return 0;
}

int viewlist()
{
    cout << "Full students list showing!!" << endl;
    fstream viewFile;
    viewFile.open("stdregister.txt",ios::in | ios::app);
    string full_list;
    
    while (getline(viewFile,full_list)){
        cout << full_list << endl;
    }
    
    viewFile.close();
    cout << endl<< "Full students list Showed successfully" << endl << endl;
    select();
    return 0;
    
}
int main()
{
    select();
    return 0;
}