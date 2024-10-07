#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << setfill('-') << setw(72) << "\n";
    cout << setfill(' ') << "|"
         << setw(18) << "NAME"
         << setw(18) << "CODE"
         << setw(18) << "COST"
         << setw(17) << "|\n";
    cout << setfill('-') << setw(72) << "\n";

    cout << setfill(' ') << "|"
         << setw(21) << "Turbo C++"
         << setw(15) << 1001
         << setw(19) << 250.95
         << setw(16) << "|\n";

    cout << setfill('-') << setw(72) << "\n";

    cout << setfill(' ') << "|"
         << setw(21) << "C Primer"
         << setw(15) << 9050
         << setw(19) << 95.70
         << setw(16) << "|\n";

    cout << setfill('-') << setw(72) << "\n";

    return 0;
}
