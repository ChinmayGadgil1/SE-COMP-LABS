#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
#ifndef CHINMAY_CUSTOM
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int num;
    char str[200];
    char rate[10];
    char amount[10];
    int space_count;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int sr_num = 1;
        int items;
        cin >> items;
        cout.fill(' ');
        cout << "\n\n";
        cout << setw(33) << "RAJU CATERERS\n";
        cout << setw(36) << "Naguishim, Bandora\n";
        cout << setw(33) << "Ponda - Goa\n";

        cin.ignore();
        int random_number = 100 + rand() % 900;
        cout<<"NO: "+to_string(random_number);

        time_t t = time(0);
        char *ct = ctime(&t);

        cout << setw(50) << ct << "\n\n";
        cout << "M/s. Goa College Of Engineering, Farmagudi Ponda Goa\n\n";
        cout << "--------------------------------------------------------\n";
        cout << "|  SR. NO |" << setw(18) << "PARTICULARS" << "          |" << " RATE | AMOUNT |\n";
        cout << "--------------------------------------------------------\n";
        for (int i = 0; i < items; i++)
        {

            cin.getline(str, 200);
            cin >> rate;
            cin >> amount;
            cout.fill(' ');
            cout << "|    " << sr_num++ << "    |";
            space_count = 0;
            for (int i = 0; i < 28 && str[i] != '\0'; i++, space_count++)
            {
                cout << str[i];
            }
            while (space_count < 28)
            {
                cout << " ";
                space_count++;
            }
            cout << "|" << setw(6) << rate << "|" << setw(7) << amount << " |\n";

            cout << "|         |";
            space_count = 0;
            for (int i = 28; i < 56 && str[i] != '\0'; i++, space_count++)
            {
                cout << str[i];
            }
            while (space_count < 28)
            {
                cout << " ";
                space_count++;
            }
            cout << "|" << "      |        |\n";

            cout << "|         |";
            space_count = 0;
            for (int i = 56; i < 84 && str[i] != '\0'; i++, space_count++)
            {
                cout << str[i];
            }
            cout << "|" << "      |        |\n";

            cout << "|         |";
            space_count = 0;
            for (int i = 84; i < 112, str[i] != '\0'; i++, space_count++)
            {
                cout << str[i];
            }
            while (space_count < 28)
            {
                cout << " ";
                space_count++;
            }
            cout << "|" << "      |        |\n";

            cout.fill('-');
            cout.width(57);
            cout << "\n";
            cin.ignore();
        }
        cout << "\n\n";
    }
    return 0;
}