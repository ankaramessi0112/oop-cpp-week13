#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
protected:
    string cccd;
    string sdt;
    string address;

public:
    Employee() {
        cccd = "";
        sdt = "";
        address = "";
    }

    Employee(string c, string s, string a) {
        cccd = c;
        sdt = s;
        address = a;
    }

    ~Employee() {}

    double tinhLuong() const { return 0; }

    // Câu 7.2
    void displayInfo() const {
        cout << "CCCD: " << cccd << " | SDT: " << sdt << " | Address: " << address;
    }

    string getCCCD() const { return cccd; }
    string getSDT() const { return sdt; }
    string getAddress() const { return address; }
};

class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;

public:
    HourlyEmployee(string c, string s, string a, int soGio, double dg)
        : Employee(c, s, a) {
        soGioLamViec = soGio;
        donGia = dg;
    }

    // Câu 7.1
    double tinhLuong() const {
        return soGioLamViec * donGia;
    }

    // Câu 7.2
    void displayInfo() const {
        Employee::displayInfo();
        cout << " | Loai: Theo gio | Luong: " << tinhLuong() << endl;
    }
};

class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;

public:
    MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs)
        : Employee(c, s, a) {
        luongCoBan = lcb;
        phuCap = pc;
        heSoThuong = hs;
    }

    // Câu 7.1
    double tinhLuong() const {
        return luongCoBan + phuCap + (luongCoBan * heSoThuong);
    }

    // Câu 7.2
    void displayInfo() const {
        Employee::displayInfo();
        cout << " | Loai: Hang thang | Luong: " << tinhLuong() << endl;
    }
};

int main() {
    // Câu 7.3 & Câu 7.4
    vector<Employee*> dsNhanVien;
    
    dsNhanVien.push_back(new HourlyEmployee("001", "0901", "Ha Noi", 150, 50000));
    dsNhanVien.push_back(new HourlyEmployee("002", "0902", "Hai Phong", 180, 55000));
    dsNhanVien.push_back(new MonthlyEmployee("003", "0903", "Da Nang", 12000000, 1500000, 1.1));
    dsNhanVien.push_back(new MonthlyEmployee("004", "0904", "Ho Chi Minh", 15000000, 2000000, 1.5));

    cout << "--- DANH SACH NHAN VIEN ---" << endl;
    for (Employee* nv : dsNhanVien) {
        nv->displayInfo();
    }

    // Câu 7.4
    double tongQuyLuong = 0;
    for (Employee* nv : dsNhanVien) {
        tongQuyLuong += nv->tinhLuong();
    }
    cout << "\n=> Tong quy luong cua cong ty: " << tongQuyLuong << endl;

    // Câu 7.5
    if (!dsNhanVien.empty()) {
        Employee* nvMax = dsNhanVien[0];
        Employee* nvMin = dsNhanVien[0];

        for (Employee* nv : dsNhanVien) {
            if (nv->tinhLuong() > nvMax->tinhLuong()) nvMax = nv;
            if (nv->tinhLuong() < nvMin->tinhLuong()) nvMin = nv;
        }

        cout << "\n--- NHAN VIEN LUONG CAO NHAT ---" << endl;
        nvMax->displayInfo();
        cout << "--- NHAN VIEN LUONG THAP NHAT ---" << endl;
        nvMin->displayInfo();
    }

    // Câu 7.6
    int demHourly = 0;
    int demMonthly = 0;
    for (Employee* nv : dsNhanVien) {
        if (dynamic_cast<HourlyEmployee*>(nv)) {
            demHourly++;
        } else if (dynamic_cast<MonthlyEmployee*>(nv)) {
            demMonthly++;
        }
    }
    cout << "\n=> So luong HourlyEmployee: " << demHourly << endl;
    cout << "=> So luong MonthlyEmployee: " << demMonthly << endl;

    // Câu 7.7
    double mucLuong;
    cout << "\nNhap muc luong can tim: ";
    cin >> mucLuong;
    cout << "--- NHAN VIEN CO LUONG > " << mucLuong << " ---" << endl;
    bool timThay = false;
    for (Employee* nv : dsNhanVien) {
        if (nv->tinhLuong() > mucLuong) {
            nv->displayInfo();
            timThay = true;
        }
    }
    if (!timThay) cout << "Khong co ai!" << endl;

    // Câu 7.8
    int n = dsNhanVien.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dsNhanVien[i]->tinhLuong() < dsNhanVien[j]->tinhLuong()) {
                Employee* temp = dsNhanVien[i];
                dsNhanVien[i] = dsNhanVien[j];
                dsNhanVien[j] = temp;
            }
        }
    }

    cout << "\n--- DANH SACH SAU KHI SAP XEP GIAM DAN THEO LUONG ---" << endl;
    for (Employee* nv : dsNhanVien) {
        nv->displayInfo();
    }

    for (Employee* nv : dsNhanVien) {
        delete nv; 
    }
    dsNhanVien.clear();

    return 0;
}