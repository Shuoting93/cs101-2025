#include <iostream>
using namespace std;

// 父類別：Car
class Car {
private:
    int m_MaxSeating;
    int m_price;
    string m_DriveMode;  // 驅動模式

public:
    string m_brand;
    string m_model;
    int m_year;

    // 建構子
    Car(string brand, string model, int year, int seating)
        : m_brand(brand), m_model(model), m_year(year), m_MaxSeating(seating) {
        m_price = m_MaxSeating * 500000;  // 價格依座位數計算
    }

    // 設定驅動模式（給子類別使用）
    void setDriveMode(string mode) {
        m_DriveMode = mode;
    }

    // 取得驅動模式
    string getDriveMode() const {
        return m_DriveMode;
    }

    // 取得價格
    int getPrice() const {
        return m_price;
    }
};

// 子類別：BMW_Car
class BMW_Car : public Car {
public:
    BMW_Car(string model, int year, int seating)
        : Car("BMW", model, year, seating) {
        cout << "Constructing BMW_Car" << endl;
        setDriveMode("Rear-wheel");
    }
};

// 子類別：AUDI_Car
class AUDI_Car : public Car {
public:
    AUDI_Car(string model, int year, int seating)
        : Car("Audi", model, year, seating) {
        cout << "Constructing AUDI_Car" << endl;
        setDriveMode("Front-wheel");
    }
};

// 子類別：BENZ_Car
class BENZ_Car : public Car {
public:
    BENZ_Car(string model, int year, int seating)
        : Car("Benz", model, year, seating) {
        cout << "Constructing BENZ_Car" << endl;
        setDriveMode("Front-wheel");
    }
};

// 測試主程式
int main() {
    BMW_Car car1("X5", 2023, 5);
    cout << car1.m_brand << " : Drive Mode = " << car1.getDriveMode() << endl;

    AUDI_Car car2("A1", 2023, 4);
    cout << car2.m_brand << " : Drive Mode = " << car2.getDriveMode() << endl;

    BENZ_Car car3("C300", 2023, 4);
    cout << car3.m_brand << " : Drive Mode = " << car3.getDriveMode() << endl;

    return 0;
}
