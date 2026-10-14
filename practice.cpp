#include <iostream>
using namespace std;
 
class People {
    private:
        string cccd;
        string name;
        string address;
    public:
        People() {
            cccd = "000000000000";
            name = "Unknown";
            address = "Unknown";

        }


        People(string peopleCccd, string peopleName, string peopleAddress) {
            cccd = peopleCccd;
            name = peopleName;
            address = peopleAddress;
        }

        string getCccd() const{return cccd;}
        string getName() const{return name;}
        string getAddress() const{return address;}

        void setCccd(string peopleCccd) {cccd = peopleCccd;}
        void setName(string peopleName) {name = peopleName;}
        void setAddress(string peopleAddress) {address = peopleAddress;}

        void displayInfo() const {
            cout << "CCCD: " << cccd << endl;
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
        }
        
    };

class Student : public People {
    private:
        string mssv;
        int yearEntrance;
    public:
        Student() : People() {
            mssv = "N//A";
            yearEntrance = 0;
        }
        Student(string peopleCccd, string peopleName, string peopleAddress, string studentMssv, int studentYearEntrance) : People(peopleCccd, peopleName, peopleAddress) {
            mssv = studentMssv;
            yearEntrance = studentYearEntrance;
        }
        string getMssv() const{return mssv;}
        int getYearEntrance() const{return yearEntrance;}
        void setMssv(string m) {mssv = m;}
        void setYearEntrance(int y) {yearEntrance = y;}
        
        void displayInfo() const {
            cout << "CCCD: " << getCccd() << endl;
            cout << "Name: " << getName() << endl;
            cout << "Address: " << getAddress() << endl;
            cout << "MSSV: " << mssv << endl;
            cout << "Year of Entrance: " << yearEntrance << endl;
        }
    };

class FIEStudent : public Student {
    private:
        int credits;
    public:
        FIEStudent() : Student() {
            credits = 0;
        }
        FIEStudent(string peopleCccd, string peopleName, string peopleAddress, string studentMssv, int studentYearEntrance, int cr) : Student(peopleCccd, peopleName, peopleAddress, studentMssv, studentYearEntrance) {
            credits = cr;
        }
        int getCredits() const{return credits;}
        void setCredits(int cr) {credits = cr;}

        void displayInfo() const {
            cout << "CCCD: " << getCccd() << endl;
            cout << "Name: " << getName() << endl;
            cout << "Address: " << getAddress() << endl;
            cout << "MSSV: " << getMssv() << endl;
            cout << "Year of Entrance: " << getYearEntrance() << endl;
            cout << "Credits: " << credits << endl;
        }


    };  


int main() {
    People p1;
    cout << "--- People p1 (mac dinh) ---" << endl;
    p1.displayInfo();
    cout << endl;

    People p2("123456789012", "Lionel Messi", "Ho Chi Minh");
    cout << "--- People p2 (khoi tao co tham so) ---" << endl;
    p2.displayInfo();
    cout << endl;

    Student s1; 
    cout << "--- Student s1 (mac dinh) ---" << endl;
    s1.displayInfo();
    cout << endl;
    Student s2("987654321098", "Cristiano Ronaldo", "Ha Noi", "SV001", 2020);
    cout << "--- Student s2 (khoi tao co tham so) ---" << endl;
    s2.displayInfo();
    cout << endl;
    cout << "--- FIEStudent f1 (mac dinh) ---" << endl;
    FIEStudent f1;
    f1.displayInfo();
    cout << endl;
    FIEStudent f2("123456789012", "Donald Trump", "Ho Chi Minh", "SV001", 2020, 120);
    cout << "--- FIEStudent f2 (khoi tao co tham so) ---" << endl;
    f2.displayInfo();
    cout << endl;

    return 0;
}
