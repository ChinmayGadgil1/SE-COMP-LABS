#include <iostream>
#include <string>

using namespace std;

class Person;

class Address {
private:
    string street;
    string city;

public:
    Address(const string& street, const string& city)
        : street(street), city(city) {}

    friend void printPersonDetails(const Person& person);
};

class Person {
private:
    string name;
    int age;
    Address address;

public:
    Person(const string& name, int age, const Address& address)
        : name(name), age(age), address(address) {}

    friend void printPersonDetails(const Person& person);
};

void printPersonDetails(const Person& person) {
    cout << "Name: " << person.name << "\n";
    cout << "Age: " << person.age << "\n";
    cout << "Street: " << person.address.street << "\n";
    cout << "City: " << person.address.city << "\n";
}

int main() {
    Address address("123 Loutolim", "Margao");
    Person person("Conrad Alves", 30, address);

    printPersonDetails(person);

    return 0;
}
