#include <iostream>
#include <cctype>
#include <vector>
using namespace std;
int main() {
    while (true) {
        //this code for the menu
        string user_choice;
        cout
                << "welcome!...what do you like to do?..click 1 or 2 or 3\n(1)cipher a message\n(2)decipher a message\n(3)exit\n";
        //getline not cin as I want user to input spaces easly
        getline(cin, user_choice);
        //البرمجه الدفاعيه
        while (user_choice != "1" && user_choice != "2" && user_choice != "3") {
            cout << "please enter a valid choice.... 1 or 2 or 3\n";
            getline(cin, user_choice);
            if (user_choice == "1" || user_choice == "2" || user_choice == "3") {
                break;
            }
        }

        string message;
        string keyword;
        //convert the string input(message and keyword) to vector as vector is easy to append a new element in it
        vector<char> msg{};
        vector<char> kword{};

        //cipher a message
        if (user_choice == "1") {
            cout << "enter the message to cipher with maximum characters 80\n";
            //getline not cin as I want user to input spaces easly
            getline(cin, message);

            //البرمجه الدفاعيه
            while (size(message) > 80 || (size(message) < 1)) {
                cout << "please enter maximum 80 character\n";
                getline(cin, message);
                if (size(message) > 0 && size(message) < 81)
                    break;
            }
            cout << "enter the keyword with maximum characters 8\n";
            //getline not cin
            getline(cin, keyword);

            //البرمجه الدفاعيه
            while (size(keyword) > 8 || size(keyword) < 1) {
                cout << "please enter maximum 8 characters\n";
                getline(cin, keyword);
                if (size(keyword) < 9 && size(keyword) > 0)
                    break;
            }

            //this code to make the key word repetitve and make its size = size of the message
            //and to the elements from the array to vector
            int counter = size(message) / size(keyword);
            int reminder = size(message) % size(keyword);
            for (int i = 0; i < counter; ++i) {
                for (int j = 0; j < size(keyword); ++j) {
                    kword.push_back(keyword[j]);
                }
            }
            for (int i = 0; i < reminder; ++i) {
                kword.push_back(keyword[i]);
            }
            for (int i = 0; i < size(message); ++i) {
                msg.push_back(message[i]);
            }

            //this code to make the Vignere Cipher
            cout << "encrypted message is: ";
            for (int i = 0; i < msg.size(); ++i) {
                if (isalpha(msg.at(i))) {
                    cout << (char) toupper(
                            (char) (int('A') + ((int(toupper(msg.at(i))) + int(toupper(kword.at(i)))) % 26)));
                } else
                    cout << msg.at(i);
            }
            cout << endl;
        }

            //decipher a message
        else if (user_choice == "2") {
            cout << "enter the message you want to decipher\n";
            getline(cin, message);
            cout << "enter the key word\n";
            getline(cin, keyword);
            while (size(keyword) > 8 || size(keyword) < 1) {
                cout << "enter a valid key word with maximum 8 character\n";
                getline(cin, keyword);
                if (size(keyword) <= 8 && size(keyword) > 0) {
                    break;
                }
            }
            int counter = size(message) / size(keyword);
            int reminder = size(message) % size(keyword);
            for (int i = 0; i < counter; ++i) {
                for (int j = 0; j < size(keyword); ++j) {
                    kword.push_back(keyword[j]);
                }
            }
            for (int i = 0; i < reminder; ++i) {
                kword.push_back(keyword[i]);
            }
            for (int i = 0; i < size(message); ++i) {
                msg.push_back(message[i]);
            }

            // decipher code
            cout << "decrypted message: ";
            for (int i = 0; i < msg.size(); i++) {
                if (isalpha(msg.at(i))) {
                    cout << char(((toupper(msg[i]) - toupper(kword[i]) + 26) % 26) + (msg[i] >= 'A' ? 'A' : 'a'));
                } else cout << msg.at(i);
            }
            cout << endl ;
        }

        //exit the program
        else if (user_choice=="3")
        {
            break;
        }
    }
    return 0;
}