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

float getFloatInput(const string& prompt) {
    float input;
    cout << prompt;
    cin >> input;
    cin.ignore();
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
    int daysPresent = getFloatInput("Enter No. of days present: ");
    float basicSalary = getFloatInput("Enter Basic Salary: ");
    
    float basic = getFloatInput("Enter BASIC payment: ");
    float da = getFloatInput("Enter DA payment: ");
    float hra = getFloatInput("Enter HRA payment: ");
    float cca = getFloatInput("Enter CCA payment: ");
    float dda = getFloatInput("Enter DDA payment: ");
    float arrears = getFloatInput("Enter ARREARS payment: ");
    float adhocAlw = getFloatInput("Enter ADHOC.ALW payment: ");
    float totalPay = getFloatInput("Enter TOTAL PAY: ");
    
    float pf = getFloatInput("Enter PF deduction: ");
    float fpf = getFloatInput("Enter FPF deduction: ");
    float vpf = getFloatInput("Enter VPF deduction: ");
    float befund = getFloatInput("Enter BEFUND deduction: ");
    float pTax = getFloatInput("Enter P.TAX deduction: ");
    float canteen = getFloatInput("Enter CANTEEN deduction: ");
    float welfare = getFloatInput("Enter WELFARE deduction: ");
    float totalDed = getFloatInput("Enter TOTAL DED: ");
    
    float lic = getFloatInput("Enter LIC recovery: ");
    float ccubeContr = getFloatInput("Enter CCUBE CONTR. recovery: ");
    float societyAdv = getFloatInput("Enter SOCIETY ADV recovery: ");
    float rentRecv = getFloatInput("Enter RENT RECV recovery: ");
    float pfLoan = getFloatInput("Enter PF LOAN recovery: ");
    float salaryAdv = getFloatInput("Enter SALARY ADV recovery: ");
    float tourAdv = getFloatInput("Enter TOUR ADV recovery: ");
    float totalRecv = getFloatInput("Enter TOTAL RECV: ");

    float netPay = getFloatInput("Enter NET PAY: ");
    
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
         << "\t\tTOTAL RECV  " << totalRecv << endl;
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