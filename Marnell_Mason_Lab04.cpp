//Mason Marnell
//Data Structures Lab #4

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void question1() {
    string input;
    string str;
    string rstr;
    cout << "Input string: ";
    getline(cin, input);
    cout << endl;


    for (int i = 0; i < input.size(); i++) { //removes spaces and fills str
        if (input.compare(i,1," ") != 0) {
            str.push_back(input[i]);
        }
    }

     for (int i = str.size()-1; i >= 0; i--) { //fills rstr
        rstr.push_back(str[i]);
    }
    

     cout << input << endl << rstr << endl;
    
    if ((str.compare(rstr)==0)) {
        cout << "strings are a palindrome" << endl;
    }
    

    return;
}


void question2() {
    string ip;
    std::vector <string> vect;
    string temp; //will store each element of vector

    cout << "Enter IP Address: ";
    cin >> ip;
    //ip = "100.200.0.2.4";

    int dots = 0;

    for (int i = 0; i < ip.size(); i++) {
        if (ip.compare(i, 1, ".") != 0) {
            temp.push_back(ip[i]);
        }
        else {
            vect.push_back(temp);
            temp.clear();
            dots++; //counts number of dots for formatting
        }
    }
    vect.push_back(temp);
    temp.clear(); //do these two lines one more time to get last number


    //------- printing --------
    cout << "{";
    int j = 0;
    for (int i = 0; i < dots; i++) { //does all the formatting
        cout << vect[i] << ", ";
        j = i;
    }
    cout << vect[dots] << "}"; //prints the last number and bracket


}

int main() {
    
    //question1();
    question2();


    return 0;
}

