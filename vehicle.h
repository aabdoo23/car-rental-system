#include <bits/stdc++.h>
using namespace std;
class CVehicle {
private:
    //private variables
    int Car_Number,cusID;
    char car_model[50]{}, car_type[50]{}, return_time[50]{},rent_time[50]{};
    float car_price;
    bool isRented;
public:
    CVehicle(){ //constructor
        Car_Number=0,cusID=0;
        car_price=0,isRented= false;
        for (int i = 0; i < 50; ++i) {
            car_model[i]='\0';
            car_type[i]='\0';
            return_time[i]='\0';
            rent_time[i]='\0';
        }
    }
    //setters
    void setCarNumber(int num );
    void setCarPrice(float price );
    void setCarModel(char model[50] );
    void setCarType(char type[50] );
    void setRentTime(char time[50]);
    void setReturnTime(char RetTime[50]);
    void setRentState(bool RentState);
    void setCustomerID(int Cus_ID);

    //getters
    float getCarPrice() const ;
    char *getRentTime();
    int getCarNumber() const ;
    char *getReturnTime();
    char* getCarModel() ;
    char* getCarType() ;
    bool getRentState() const;
    int getCustomerID() const;

    //addDetails
    void addCarDetails(CVehicle vehicle){ //setter
        cout<<"Enter Car Price: ";
        cin>>car_price;
        vehicle.setCarPrice(car_price);
        cout<<"Enter Car Model: ";
        cin.ignore();
        cin.getline(car_model,50);
        vehicle.setCarModel(car_model);
        cout<<"Enter Car Type: ";
        cin.getline(car_type,50);
        vehicle.setCarType(car_type);

    }
    void get_cars_info(CVehicle vehicle){
        cout<<"Car number:        "<<vehicle.getCarNumber()<<endl;
        cout<<"Car price:         "<<vehicle.getCarPrice()<<endl;
        cout<<"Car model:         "<<vehicle.getCarModel()<<endl;
        cout<<"Car type:          "<<vehicle.getCarType()<<endl;
        cout<<"Rent time:         "<<vehicle.getRentTime()<<endl;
        cout<<"Return time:       "<<vehicle.getReturnTime()<<endl;
        cout<<"Renter ID:         "<<vehicle.getCustomerID()<<endl;

        if(vehicle.getRentState())
            cout<<"Rent state:        "<<"Rented"<<endl;
        else
            cout<<"Rent state:        "<<"Not rented"<<endl;
    }

    void Rent_car( CVehicle vehicle){
        cout<<"Enter rent time: ";
        cin.ignore();
        cin.getline(rent_time,50);
        vehicle.setRentTime(rent_time);
        cout<<"Enter return time: ";
        cin.getline(return_time,50);
        vehicle.setReturnTime(return_time);
        if(*rent_time=='0'&&rent_time[1]=='\0'&&*return_time=='0'&&return_time[1]=='\0')
            isRented= false;
        else
            isRented= true;
        vehicle.setRentState(isRented);
    }
};

// Member functions definitions

//setters
void CVehicle::setCarPrice(float price) {
    car_price=price;
}
void CVehicle::setCarNumber(int num) {
    Car_Number = num;
}
void CVehicle::setReturnTime(char *RetTime) {
    strcpy(return_time, RetTime);
}
void CVehicle::setCarModel(char *model) {
    strcpy(car_model, model);
}
void CVehicle::setRentTime(char *time) {
    strcpy(rent_time, time);
}
void CVehicle::setCarType(char *type) {
    strcpy(car_type, type);
}
void CVehicle::setRentState(bool RentState) {
    isRented=RentState;
}
void CVehicle::setCustomerID(int Cus_ID) {
    cusID=Cus_ID;
}

// getters
char *CVehicle::getCarModel() {
    return car_model;
}
char *CVehicle::getCarType() {
    return car_type;
}
char *CVehicle::getRentTime() {
    return rent_time;
}
char *CVehicle::getReturnTime() {
    return return_time;
}
float CVehicle::getCarPrice() const {
    return car_price;
}
int CVehicle::getCarNumber() const {
    return Car_Number ;
}
bool CVehicle::getRentState() const {
    return isRented;
}
int CVehicle::getCustomerID() const {
    return cusID;
}



