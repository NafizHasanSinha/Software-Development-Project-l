#include<bits/stdc++.h>

using namespace std;

struct node
{
    long long int cardNo;
    int pin;
    string name;
    int cash;
    string pendingRequest;
    node *next;
    node *prev;
};

class ATM
{
    node *head;
    string x;
    long long int y;
    int z;
    int c;


public:
    ATM()
    {
        head = NULL;
        x = "";
        y = 0;
        z = 0;
        c = 0;

    }
    int count_digits(long long int n)
    {

        string num = to_string(n);
        return num.size();
    }
    void Account()
    {
        ofstream outFile("accounts.txt", ios::app);
        if (!outFile)
        {
            cout << "Unable to open file for writing." << endl;
            return;
        }

        if (head == NULL)
        {
            node *newnode = new node;
            cout << "Please enter your name: ";
            cin >> x;
            newnode->name = x;

            cout << "Please enter your Card No: ";
            cin >> y;
            while (count_digits(y) != 11)
            {
                cout << "Put 11 digits cardNo: ";
                cin >> y;
            }
            newnode->cardNo = y;

            cout << "Please enter your Pin: ";
            cin >> z;
            while (count_digits(z) != 4)
            {
                cout << "Put 4 digits pin: ";
                cin >> z;
            }
            newnode->pin = z;

            newnode->cash = 0;
            newnode->next = NULL;
            newnode->prev = NULL;
            head = newnode;

            outFile << newnode->name << endl;
            outFile << newnode->cardNo << endl;
            outFile << newnode->pin << endl;
            outFile << newnode->cash << endl;
            outFile << newnode->pendingRequest << endl;
            outFile.close();

            cout << "Your Account Created" << endl;
        }
        else
        {

            outFile.close();
        }
    }


    int LoginAccount()
    {
        long long int cardNo;
        int pin;
        ifstream inFile("accounts.txt");

        if (!inFile)
        {
            cout << "Unable to open file for reading." << endl;
            return 1;
        }

        node *temp = head;
        cout << "Please enter your Card No: ";
        cin >> y;

        cout << "Please enter your Pin: ";
        cin >> z;

        bool found = false;
        while (inFile >> x >> y >> z >> c)
        {
            if (y == cardNo && z == pin)
            {
                found = true;
                break;
            }
        }

        inFile.close();

        if (found)
        {
            cout << "*****************************************" << endl;
            cout << "Enter Name: " << x << endl;
            return 0;
        }
        else
        {
            cout << "Your cardNo or Pin is wrong\n";
            cout << "Please Try Again....\n\n";
            return 1;
        }
    }
    void user_menu()
    {
        cout << "_____________________" << endl;
        cout << "       USER MENU" << endl;
        cout << "_____________________" << endl;
        cout << " 1. Deposit Money" << endl;
        cout << " 2. Withdraw Money" << endl;
        cout << " 3. Check Balance" << endl;
        cout << " 4. Money Transfer" << endl;
        cout << " 5. Main Menu" << endl;
        cout << "_____________________" << endl;

        int command;

        cout << "Enter the command: ";
        cin >> command;

        switch(command)
        {
        case 1:
           // Deposit();
            user_menu();
            break;
        case 2:
           // Withdraw();
            user_menu();
            break;
        case 3:
           // Balance_check();
            user_menu();
            break;
        case 4:
            //  Transfer();
            user_menu();
            break;
        case 5:
            main_menu();
            break;
        default:
            cout << "Wrong input" << endl;
            cout << "Please Try Again...."<<endl << endl;
            return user_menu();
        }
    }

    void main_menu()
    {
        cout << "|___________________|" << endl;
        cout << "|    MAIN MENU      |" << endl;
        cout << "|___________________|" << endl;
        cout << "|1. Create Account  |" << endl;
        cout << "|2. Login to Account|" << endl;
        cout << "|4. Exit            |" << endl;
        cout << "|___________________|" << endl;
        int scommand;

        cout << "Enter the command: ";
        cin >> scommand;

        switch (scommand)
        {
        case 1:
            Account();
            main_menu();
            break;
        case 2:
            if (LoginAccount() == 0)
            break;
        case 3:
            break:
        case 4:

            cout << "Exiting..." << endl;
            break;
        default:
            cout<<endl << "Wrong input" << endl;
            cout << "Please Try Again...."<<endl << endl;
            return main_menu();
        }
    }
};
int main()
{
    ATM obj;
    obj.main_menu();
}
run this code
