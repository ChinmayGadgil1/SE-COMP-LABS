#include <iostream>
using namespace std;

class Student {
protected:
    int regNo;
public:
    void setRegNo(int r){
         regNo = r; 
         }
    int getRegNo(){
        return regNo; 
        }
};

class Medical : public Student {
protected:
    int medicalMarks;
public:
    void setMedicalMarks(int m){ 
        medicalMarks = m;
        }
    int getMedicalMarks(){
        return medicalMarks; 
    }
};

class Engineering : public Student {
protected:
    int engineeringMarks;
public:
    void setEngineeringMarks(int m){
        engineeringMarks = m;
        }
    int getEngineeringMarks(){
        return engineeringMarks;
        }
};

class Arts : public Student {
protected:
    int artsMarks;
public:
    void setArtsMarks(int m){
        artsMarks = m;
        }
    int getArtsMarks(){
        return artsMarks;
        }
};

class Mech : public Engineering {
protected:
    int mechMarks;
public:
    void setMechMarks(int m){
        mechMarks = m;
    }
    int getMechMarks(){
        return mechMarks;
        }
};

class ETC : public Engineering {
protected:
    int etcMarks;
public:
    void setETCMarks(int m){
        etcMarks = m;
        }
    int getETCMarks(){
        return etcMarks;
    }
};

class Comp : public Engineering {
protected:
    int compMarks;
public:
    void setCompMarks(int m){
        compMarks = m;
        }
    int getCompMarks(){
        return compMarks;
        }
};

int main() {
    Medical med;
    med.setRegNo(1);
    med.setMedicalMarks(85);

    Arts art;
    art.setRegNo(2);
    art.setArtsMarks(90);

    Mech mech;
    mech.setRegNo(3);
    mech.setEngineeringMarks(80);
    mech.setMechMarks(75);

    ETC etc;
    etc.setRegNo(4);
    etc.setEngineeringMarks(82);
    etc.setETCMarks(88);

    Comp comp;
    comp.setRegNo(5);
    comp.setEngineeringMarks(78);
    comp.setCompMarks(92);

    cout << "Medical Student: RegNo = " << med.getRegNo() << ", Marks = " << med.getMedicalMarks() << endl;
    cout << "Arts Student: RegNo = " << art.getRegNo() << ", Marks = " << art.getArtsMarks() << endl;
    cout << "Mech Student: RegNo = " << mech.getRegNo() << ", Engineering Marks = " << mech.getEngineeringMarks() << ", Mech Marks = " << mech.getMechMarks() << endl;
    cout << "ETC Student: RegNo = " << etc.getRegNo() << ", Engineering Marks = " << etc.getEngineeringMarks() << ", ETC Marks = " << etc.getETCMarks() << endl;
    cout << "Comp Student: RegNo = " << comp.getRegNo() << ", Engineering Marks = " << comp.getEngineeringMarks() << ", Comp Marks = " << comp.getCompMarks() << endl;

    return 0;
}