#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
using namespace std;
int cash = 0;
void menu();
class player
{
public:
    static string name;
    int depositednow;

    void setname()
    {
        cout << "|\tEnter your Name:";
        cin >> name;
        menu();
    }
    int getcash()
    {
        return cash;
    }
    void deposit()
    {
        ofstream outf("textfile.txt", ios::app);
        cout << "\t|Enter amount to deposit  ";
        cin >> depositednow;
        cash += depositednow;
        cout << "\t|verifying your transaction...." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "\t| Successfully Deposited $" << depositednow << "\t" << endl
             << endl;
        outf << "-->\tDeposited +$" << depositednow << "\t" << endl;

        outf.close();
    }
};
string player::name;
class BR : public player
{
public:
    int stake = 0;

    void rules()
    {
        cout << "\t\t               *BLUE OR RED* \n"
             << endl;
        cout << "**********************RULES*********************" << endl;
        cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
        cout << "\t|CHOOSE WHERE WILL THE BALL LAND |" << endl;
        cout << "\t|IF YOU WIN YOU WILL GET 2X      |" << endl;
        cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
    }
    void play()
    {

        cout << "Minimum stake: $20" << endl;
        cout << "Enter Stake: ";
        cin >> stake;
        if (cash >= stake)
        {
             cash-=stake;
            int choice, predict;
            cout << "\t\t               *BLUE OR RED* \n"
                 << endl;
            cout << "\t 1. BLUE" << endl;
            cout << "\t 2. RED" << endl;
            cout << "\t YOUR CHOICE:";
            cin >> choice;

            srand(time(nullptr));
            predict = 1 + rand() % 2;
            if (choice == predict)
            {

                stake *= 2;
                cout << " \t YOU WON  " << stake << endl;
                cash += stake;
            }
            else
            {
                cout << " YOU LOST" << endl;
            }
        }
        else{
            cout << "\t\tINDUFFICIENT FUNDS" << endl;
        cout << "\t\tDEPOSIT MONEY" << endl;
        }
    }
    
};
class Dice : public player
{
public:
    int stake = 0;

    void rules()
    {
        cout << "\t\t               *DICE* \n"
             << endl;
        cout << "\t********************RULES*****************" << endl;
        cout << "\t|-----------------------------------------|" << endl;
        cout << "\t|TWO DICES WILL BE ROLLED                 |" << endl;
        cout << "\t|GUESS THE SUM WILL BE UNDER 7 OR OVER 7  |" << endl;
        cout <<"\t|CORRECT GUESS -> 2X                       | "<<endl;
        cout << "\t|-----------------------------------------|" << endl;
    }
    void play()
    {

        cout << "Minimum stake: $20" << endl;
        cout << "Enter Stake: ";
        cin >> stake;
        if (cash >= stake)
        {
             cash-=stake;
            int choice, predict;
            cout << "\t*DICE* \n"
                 << endl;
            cout << "\t 1. UNDER 7" << endl;
            cout << "\t 2. OVER 7" << endl;
            cout << "\t YOUR CHOICE:";
            cin >> choice;

            srand(time(nullptr));
            predict = (1 + rand() % 6);
            if (choice == predict)
            {

                stake *= 2;
                cout << " \t YOU WON  " << stake << endl;
                cash += stake;
            }
            else
            {
                cout << " YOU LOST" << endl;
            }
        }
        else{
            cout << "\t\tINDUFFICIENT FUNDS" << endl;
        cout << "\t\tDEPOSIT MONEY" << endl;
        }
    }
    
};
class Transaction : public player // Multiple Inheritance of some other classes to Chargers
{

public:
    string line;
    static int timess;
    void printtemp()
    {
        timess++;
        ofstream outf("textfile.txt"); // receipt for bought items
        {
            outf << "------------VEGAS CASINO---------" << endl;
            outf << "---------TRANSACTION HISTORY------" << endl;
            outf << "_________________________________" << endl;
            outf << "\t\tName: " << player::name << endl
                 << endl;
        }
        outf.close();
    }

    void show()
    {
        ifstream inf("textfile.txt");
        {
            if (!inf)
            {
                cout << "File Error!" << endl;
            }
            while (getline(inf, line))
            {
                cout << line << endl; // Print each line
            }
        }
        inf.close();
    }
    void print()
    {
        ofstream outf("textfile.txt", ios::app);
        outf << "\t\t\t\tBALANCE $" << cash << endl<<endl;
        outf.close();
    }
};
int Transaction::timess;
void menu()
{
    char play_again;
    int choose;
    BR a1;
    Transaction t1;
    Dice d1;
    if (t1.timess == 0)
    {
        t1.printtemp();
    }
    
    cout << "\t------------------------------------------" << endl;
     cout << "\t\t      * VEGAS CASINO *"<<endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t                  BALANCE   $" << cash << "\t\t" << endl;
    cout << "\t|\tDEPOSIT             -> 1\t|" << endl;
    cout << "\t|\tBLUE OR RED         -> 2\t|" << endl;
    cout << "\t|\tDICE                -> 3\t|" << endl;
    cout << "\t|\tTRANSACTIONS        -> 4\t|" << endl;
    cout << "\t|\tWITHDRAW            -> 5\t|" << endl;
    cout << "\t|\tExit                -> 6\t|" << endl;
    cout << "\t\t\t\t\t\t" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cin >> choose;
    switch (choose)
    {
    case 1:

        a1.deposit();
        this_thread::sleep_for(chrono::seconds(2));
        menu();
        break;

    case 2:
        do
        {
            a1.rules();
            a1.play();
            cout << "Do you wanna play again?  ";
            cin >> play_again;
        } while ((char)toupper(play_again) == 'Y');
        menu();
        break;
    case 3:
        do
        {
            d1.rules();
            d1.play();
            cout << "Do you wanna play again?  ";
            cin >> play_again;
        } while ((char)toupper(play_again) == 'Y');
        menu();
        break;
    case 4:
        int choice;
        t1.print();
        cout << "File is already downloaded" << endl;
        cout << "press 1 to show file" << endl;
        cin >> choice;
        if (choice == 1)
        {
            t1.show();
        }
        this_thread::sleep_for(chrono::seconds(3));
        menu();
        break;

    case 5:
        int amt;
        cout << "\tENTER THE AMOUNT TO WITHDRAW  ";
        cin >> amt;
        if (cash >= amt)
        {
            cash -= amt;

            cout << "\tVERIFYING YOUR TANSACTION..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "\tSUCCESSFULLY WITHDRAWN $" << amt << endl;
            ofstream outf("textfile.txt", ios::app);
            outf << "-->\tWITHDRAWN -$" << amt << "\t" << endl;
            outf.close();
            this_thread::sleep_for(chrono::seconds(2));
            menu();
        }
        else
        {
            cout << "\tINSUFFICIENT FUNDS" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            menu();
        }
    default:
        cout << "\n\n\t\t--GOOD-BYE!--" << endl;
        this_thread::sleep_for(chrono::seconds(2));
    
    
        exit(0);
    }
}

int main()
{
    player p1;
    p1.setname();
    return 0;
}#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
using namespace std;
int cash = 0;
void menu();
class player
{
public:
    static string name;
    int depositednow;

    void setname()
    {
        cout << "|\tEnter your Name:";
        cin >> name;
        menu();
    }
    int getcash()
    {
        return cash;
    }
    void deposit()
    {
        ofstream outf("textfile.txt", ios::app);
        cout << "\t|Enter amount to deposit  ";
        cin >> depositednow;
        cash += depositednow;
        cout << "\t|verifying your transaction...." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "\t| Successfully Deposited $" << depositednow << "\t" << endl
             << endl;
        outf << "-->\tDeposited +$" << depositednow << "\t" << endl;

        outf.close();
    }
};
string player::name;
class BR : public player
{
public:
    int stake = 0;

    void rules()
    {
        cout << "\t\t               *BLUE OR RED* \n"
             << endl;
        cout << "**********************RULES*********************" << endl;
        cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
        cout << "\t|CHOOSE WHERE WILL THE BALL LAND |" << endl;
        cout << "\t|IF YOU WIN YOU WILL GET 2X      |" << endl;
        cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;
    }
    void play()
    {

        cout << "Minimum stake: $20" << endl;
        cout << "Enter Stake: ";
        cin >> stake;
        if (cash >= stake)
        {
             cash-=stake;
            int choice, predict;
            cout << "\t\t               *BLUE OR RED* \n"
                 << endl;
            cout << "\t 1. BLUE" << endl;
            cout << "\t 2. RED" << endl;
            cout << "\t YOUR CHOICE:";
            cin >> choice;

            srand(time(nullptr));
            predict = 1 + rand() % 2;
            if (choice == predict)
            {

                stake *= 2;
                cout << " \t YOU WON  " << stake << endl;
                cash += stake;
            }
            else
            {
                cout << " YOU LOST" << endl;
            }
        }
        else{
            cout << "\t\tINDUFFICIENT FUNDS" << endl;
        cout << "\t\tDEPOSIT MONEY" << endl;
        }
    }
    
};
class Dice : public player
{
public:
    int stake = 0;

    void rules()
    {
        cout << "\t\t               *DICE* \n"
             << endl;
        cout << "\t********************RULES*****************" << endl;
        cout << "\t|-----------------------------------------|" << endl;
        cout << "\t|TWO DICES WILL BE ROLLED                 |" << endl;
        cout << "\t|GUESS THE SUM WILL BE UNDER 7 OR OVER 7  |" << endl;
        cout <<"\t|CORRECT GUESS -> 2X                       | "<<endl;
        cout << "\t|-----------------------------------------|" << endl;
    }
    void play()
    {

        cout << "Minimum stake: $20" << endl;
        cout << "Enter Stake: ";
        cin >> stake;
        if (cash >= stake)
        {
             cash-=stake;
            int choice, predict;
            cout << "\t*DICE* \n"
                 << endl;
            cout << "\t 1. UNDER 7" << endl;
            cout << "\t 2. OVER 7" << endl;
            cout << "\t YOUR CHOICE:";
            cin >> choice;

            srand(time(nullptr));
            predict = (1 + rand() % 6);
            if (choice == predict)
            {

                stake *= 2;
                cout << " \t YOU WON  " << stake << endl;
                cash += stake;
            }
            else
            {
                cout << " YOU LOST" << endl;
            }
        }
        else{
            cout << "\t\tINDUFFICIENT FUNDS" << endl;
        cout << "\t\tDEPOSIT MONEY" << endl;
        }
    }
    
};
class Transaction : public player // Multiple Inheritance of some other classes to Chargers
{

public:
    string line;
    static int timess;
    void printtemp()
    {
        timess++;
        ofstream outf("textfile.txt"); // receipt for bought items
        {
            outf << "------------VEGAS CASINO---------" << endl;
            outf << "---------TRANSACTION HISTORY------" << endl;
            outf << "_________________________________" << endl;
            outf << "\t\tName: " << player::name << endl
                 << endl;
        }
        outf.close();
    }

    void show()
    {
        ifstream inf("textfile.txt");
        {
            if (!inf)
            {
                cout << "File Error!" << endl;
            }
            while (getline(inf, line))
            {
                cout << line << endl; // Print each line
            }
        }
        inf.close();
    }
    void print()
    {
        ofstream outf("textfile.txt", ios::app);
        outf << "\t\t\t\tBALANCE $" << cash << endl<<endl;
        outf.close();
    }
};
int Transaction::timess;
void menu()
{
    char play_again;
    int choose;
    BR a1;
    Transaction t1;
    Dice d1;
    if (t1.timess == 0)
    {
        t1.printtemp();
    }
    
    cout << "\t------------------------------------------" << endl;
     cout << "\t\t      * VEGAS CASINO *"<<endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t                  BALANCE   $" << cash << "\t\t" << endl;
    cout << "\t|\tDEPOSIT             -> 1\t|" << endl;
    cout << "\t|\tBLUE OR RED         -> 2\t|" << endl;
    cout << "\t|\tDICE                -> 3\t|" << endl;
    cout << "\t|\tTRANSACTIONS        -> 4\t|" << endl;
    cout << "\t|\tWITHDRAW            -> 5\t|" << endl;
    cout << "\t|\tExit                -> 6\t|" << endl;
    cout << "\t\t\t\t\t\t" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cin >> choose;
    switch (choose)
    {
    case 1:

        a1.deposit();
        this_thread::sleep_for(chrono::seconds(2));
        menu();
        break;

    case 2:
        do
        {
            a1.rules();
            a1.play();
            cout << "Do you wanna play again?  ";
            cin >> play_again;
        } while ((char)toupper(play_again) == 'Y');
        menu();
        break;
    case 3:
        do
        {
            d1.rules();
            d1.play();
            cout << "Do you wanna play again?  ";
            cin >> play_again;
        } while ((char)toupper(play_again) == 'Y');
        menu();
        break;
    case 4:
        int choice;
        t1.print();
        cout << "File is already downloaded" << endl;
        cout << "press 1 to show file" << endl;
        cin >> choice;
        if (choice == 1)
        {
            t1.show();
        }
        this_thread::sleep_for(chrono::seconds(3));
        menu();
        break;

    case 5:
        int amt;
        cout << "\tENTER THE AMOUNT TO WITHDRAW  ";
        cin >> amt;
        if (cash >= amt)
        {
            cash -= amt;

            cout << "\tVERIFYING YOUR TANSACTION..." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            cout << "\tSUCCESSFULLY WITHDRAWN $" << amt << endl;
            ofstream outf("textfile.txt", ios::app);
            outf << "-->\tWITHDRAWN -$" << amt << "\t" << endl;
            outf.close();
            this_thread::sleep_for(chrono::seconds(2));
            menu();
        }
        else
        {
            cout << "\tINSUFFICIENT FUNDS" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            menu();
        }
    default:
        cout << "\n\n\t\t--GOOD-BYE!--" << endl;
        this_thread::sleep_for(chrono::seconds(2));
    
    
        exit(0);
    }
}

int main()
{
    player p1;
    p1.setname();
    return 0;
}