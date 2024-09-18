#include <iostream>
#include <string>
using namespace std;

class Worker {
protected:
    int worker_id;
    string name;
    string address;
    int department_id;
    int supervisor_id;

public:
    void input_worker(int w_id, string w_name, string w_address, int dept_id, int sup_id) {
        worker_id = w_id;
        name = w_name;
        address = w_address;
        department_id = dept_id;
        supervisor_id = sup_id;
    }

    virtual void print_details() const {
        cout << "Worker ID: " << worker_id << endl;
        cout << "Name: " << name << endl;
        cout << "Supervisor ID: " << supervisor_id << endl;
    }
};

class Supervisor : public Worker {
public:

    void input_supervisor(int sup_id, string sup_name, string sup_address, int dept_id) {
        input_worker(sup_id, sup_name, sup_address, dept_id, -1);  
    }

    void print_details() const override {
        cout << "Name: " << name << endl;
        cout << "Department ID: " << department_id << endl;
    }
};

int main() {

    Worker w;
    w.input_worker(1001, "John Doe", "123 Elm St", 201, 5001);
    cout << "Worker Details:" << endl;
    w.print_details();
    cout << endl;

    Supervisor s;
    s.input_supervisor(5001, "Jane Smith", "456 Oak St", 201);
    cout << "Supervisor Details:" << endl;
    s.print_details();

    return 0;
}
