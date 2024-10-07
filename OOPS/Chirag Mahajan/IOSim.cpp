#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void printCentered(const string& text, int width) {
    int len = text.length();
    int pos = (width - len) / 2;
    cout << setw(pos) << "" << text << endl;
}

string getInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

string generateBillNumber() {
    srand(time(0));
    int billNum = rand() % 100000;
    return "BILL-" + to_string(billNum);
}

void generateSalarySlip() {
    const int width = 80;
    
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    char dateTime[30];
    strftime(dateTime, sizeof(dateTime), "%d/%m/%Y %H:%M", ltm);
    
    string billNumber = generateBillNumber();
    
    string month = getInput("Enter the month and year (e.g., JANUARY 1996): ");
    string empName = getInput("Enter Employee Name: ");
    string grade = getInput("Enter Grade: ");
    string empNo = getInput("Enter Employee No.: ");
    string daysPresent = getInput("Enter No. of days present: ");
    string basicSalary = getInput("Enter Basic Salary: ");
    
    string basic = getInput("Enter BASIC payment: ");
    string da = getInput("Enter DA payment: ");
    string hra = getInput("Enter HRA payment: ");
    string cca = getInput("Enter CCA payment: ");
    string dda = getInput("Enter DDA payment: ");
    string arrears = getInput("Enter ARREARS payment: ");
    string adhocAlw = getInput("Enter ADHOC.ALW payment: ");
    string totalPay = getInput("Enter TOTAL PAY: ");
    
    string pf = getInput("Enter PF deduction: ");
    string fpf = getInput("Enter FPF deduction: ");
    string vpf = getInput("Enter VPF deduction: ");
    string befund = getInput("Enter BEFUND deduction: ");
    string pTax = getInput("Enter P.TAX deduction: ");
    string canteen = getInput("Enter CANTEEN deduction: ");
    string welfare = getInput("Enter WELFARE deduction: ");
    string totalDed = getInput("Enter TOTAL DED: ");
    
    string lic = getInput("Enter LIC recovery: ");
    string ccubeContr = getInput("Enter CCUBE CONTR. recovery: ");
    string societyAdv = getInput("Enter SOCIETY ADV recovery: ");
    string rentRecv = getInput("Enter RENT RECV recovery: ");
    string pfLoan = getInput("Enter PF LOAN recovery: ");
    string salaryAdv = getInput("Enter SALARY ADV recovery: ");
    string tourAdv = getInput("Enter TOUR ADV recovery: ");
    string totalRecv = getInput("Enter TOTAL RECV: ");

    string netPay = getInput("Enter NET PAY: ");
    
    printCentered("Centre for Development of Advanced Computing", width);
    printCentered("Bangalore, India - 560 025", width);
    printCentered("Salary-Slip for the Month of " + month, width);
    cout << string(width, '-') << endl;
    
    cout << fixed << setprecision(2); 
    
    cout << "Employee Name: " << setw(20) << left << empName 
         << "\tDate & Time: " << dateTime << "\tBill No: " << billNumber << endl;
    cout << "Grade: " << setw(10) << left << grade 
         << "\t\t\tEmployee No.: " << empNo << endl;
    cout << "No. of days present: " << setw(10) << left << daysPresent 
         << "\t\tBasic Salary: " << basicSalary << endl;
    
    cout << "<---PAYMENTS--->\t<---DEDUCTIONS--->\t<---RECOVERIES--->" << endl;
    cout << setfill(' ') << "BASIC     " << setw(8) << left << basic 
         << "\tPF       " << setw(6) << left << pf 
         << "\t\tLIC        " << lic << endl;
    cout << "DA        " << setw(8) << left << da 
         << "\tFPF      " << setw(6) << left << fpf 
         << "\t\tCCUBE CONTR. " << ccubeContr << endl;
    cout << "HRA       " << setw(8) << left << hra 
         << "\tVPF      " << setw(6) << left << vpf 
         << "\t\tSOCIETY ADV  " << societyAdv << endl;
    cout << "CCA       " << setw(8) << left << cca 
         << "\tBEFUND   " << setw(6) << left << befund 
         << "\t\tRENT RECV   " << rentRecv << endl;
    cout << "DDA       " << setw(8) << left << dda 
         << "\tP.TAX    " << setw(6) << left << pTax 
         << "\t\tPF LOAN     " << pfLoan << endl;
    cout << "ARREARS   " << setw(8) << left << arrears 
         << "\tCANTEEN  " << setw(6) << left << canteen 
         << "\t\tSALARY ADV  " << salaryAdv << endl;
    cout << "ADHOC.ALW " << setw(8) << left << adhocAlw 
         << "\tWELFARE  " << setw(6) << left << welfare 
         << "\t\tTOUR ADV    " << tourAdv << endl;
    cout << "TOTAL PAY " << setw(8) << left << totalPay 
         << "\tTOTAL DED " << setw(6) << left << totalDed 
         << "\tTOTAL RECV  " << totalRecv << endl;
    cout << "NET PAY: " << netPay << endl;
    cout << setw(width - 10) << right << "(SIGNATURE)" << endl;
}

int main() {
    char choice;
    
    do {
        generateSalarySlip();
        cout << "Do you want to generate another salary slip? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}
