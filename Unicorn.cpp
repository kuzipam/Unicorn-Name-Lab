#include <iostream>
#include <string>
#include <exception>
#include<set>

using namespace std;

class Unique_corn{
    public:
    string name;

    //Using a static set to store all the names of the unicorn. Sets dont allow duplicates so its very helpful in this situation.
    static set<string> usedNames;
    
    //Constructor for the Unicorn class that throws an error when an instance with the same name is made.
    Unique_corn(const string& n):name(n){
        //Using the invalid argument exception to throw an error when a duplicate name is tried to be created.
        if(usedNames.count(n)){throw invalid_argument("The Name already taken: " + n);}

        //Adding the name to the set.
        usedNames.insert(n);
        cout << "The Unicorn name: " << name << " has been created." << endl;
    };

    //Getter.
    void getName() const{
        cout << name << endl;
    }

    //Destructor.
    ~Unique_corn(){
        cout << "\nThe Unicorn " << name << " does not exist anymore.\n";
        usedNames.erase(name);
    };

};

//Had to include this deinition because of a compile error. Defining it as an object of the class fixed it.
set<string> Unique_corn::usedNames{};


int main(){
    try {
        //Duplicates throw an error.
        Unique_corn u1("Luna");
        Unique_corn u2("Luna");
    
        Unique_corn u3("Sparkles Senior");
        Unique_corn u4("Sparkles Senior");
        
    }
    //Prints the error.
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nCreating a new unicorn after previous one is gone:\n";

    //Creating more instances with the same name outside of the scope works.
    Unique_corn u5("Luna");
    cout << "\nI am a Unicorn named ";
    u5.getName();
    
    Unique_corn u6("Sparkles Senior");
    cout << "\nI am a Unicorn named ";
    u6.getName();

    Unique_corn u7("Sparkles Junior");
    cout << "\nI am a Unicorn named ";
    u7.getName();

}