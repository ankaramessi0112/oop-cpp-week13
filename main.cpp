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
    People p2("123456789012", "Lionel Messi", "Ho Chi Minh");

    Student s1;
    Student s2("987654321098", "Cristiano Ronaldo", "Ha Noi", "SV001", 2020);
    
    FIEStudent f1;
    FIEStudent f2("123456789012", "Donald Trump", "Ho Chi Minh", "SV001", 2020, 120);
    cout << "==Thong tin doi tuong f1 (khoi tao mac dinh)==\n";
    f1.displayInfo();
    cout << "\n==Thong tin doi tuong f2 (khoi tao co tham so)==\n";
    f2.displayInfo();
    
    return 0;
}
