#include <bits/stdc++.h>
using namespace std;
class CBus : public CVehicle { // inherited from cvehicle
private:
    //private variables
    int Bus_Number=0,cusID=0;
    int Pass_Number=0;
    char Bus_model[50]="", Bus_type[50]="", return_time[50]="",rent_time[50]="", Driver_Name[20]="";
    float Bus_price=0;
    bool isRented= false;
public:
    //setters
    void setBusNumber(int num );
    void setPassengersNumber(int Passengers );
    void setBusPrice(float price );
    void setBusModel(char model[50] );
    void setNameOfDriver(char Name[20] );
    void setBusType(char type[50] );
    void setRentTime(char time[50]);
    void setReturnTime(char RetTime[50]);
    void setRentState(bool RentState);
    void setCustomerID(int Cus_ID) {
        cusID=Cus_ID;
    }
    //getters
    float getBusPrice() const ;
    char *getRentTime();
    int getBusNumber() const ;
    int getPassengersNumber() const ;
    char *getReturnTime();
    char *getNameOfDriver();
    char *getBusModel() ;
    char *getBusType() ;
    bool getRentState() const;
    int getCustomerID() const {
        return cusID;
    }

    //addDetails
    void addBusDetails(CBus Bus){
        cout<<"Enter Passengers Number: ";
        cin>>Pass_Number;
        Bus.setPassengersNumber(Pass_Number);
        cout<<"Enter Bus Price: ";
        cin>>Bus_price;
        Bus.setBusPrice(Bus_price);
        cout<<"Enter Bus Model: ";
        cin.ignore();
        cin.getline(Bus_model,50);
        Bus.setBusModel(Bus_model);
        cout<<"Enter Bus Type: ";
        cin.getline(Bus_type,50);
        Bus.setBusType(Bus_type);
        cout<<"Enter Driver name: ";
        cin.getline(Driver_Name,50);
        Bus.setNameOfDriver(Driver_Name);

    }
    void get_Bus_info(CBus Bus){
        cout<<"Bus number:        "<<Bus.getBusNumber()<<endl;
        cout<<"Passengers Number: "<<Bus.getPassengersNumber()<<endl;
        cout<<"Bus price:         "<<Bus.getBusPrice()<<endl;
        cout<<"Bus Model:         "<<Bus.getBusModel()<<endl;
        cout<<"Bus type:          "<<Bus.getBusType()<<endl;
        cout<<"Driver Name:       "<<Bus.getNameOfDriver()<<endl;
        cout<<"Rent time:         "<<Bus.getRentTime()<<endl;
        cout<<"Return time:       "<<Bus.getReturnTime()<<endl;

        if(Bus.getRentState())
            cout<<"Rent state:        "<<"Rented"<<endl;
        else
            cout<<"Rent state:        "<<"Not rented"<<endl;

    }
    void Rent_Bus(CBus Bus){
        cout<<"Enter rent time: ";
        cin.ignore();
        cin.getline(rent_time,50);
        Bus.setRentTime(rent_time);
        cout<<"Enter return time: ";
        cin.getline(return_time,50);
        Bus.setReturnTime(return_time);
        isRented= true;
        Bus.setRentState(isRented);
    }
};

// Member functions definitions

//setters
void CBus::setBusPrice(float price) {
    Bus_price=price;
}
void CBus::setBusNumber(int num) {
    Bus_Number = num;
}
void CBus::setPassengersNumber(int Passengers) {
    Pass_Number = Passengers;
}
void CBus::setReturnTime(char *RetTime) {
    strcpy(return_time, RetTime);
}
void CBus::setBusModel(char *model) {
    strcpy(Bus_model, model);
}
void CBus::setRentTime(char *time) {
    strcpy(rent_time, time);
}
void CBus::setBusType(char *type) {
    strcpy(Bus_type, type);
}
void CBus::setNameOfDriver(char *Name) {
    strcpy(Driver_Name, Name);
}

void CBus::setRentState(bool RentState) {
    isRented=RentState;
}

// getters

char *CBus::getBusModel() {
    return Bus_model;
}
char *CBus::getBusType() {
    return Bus_type;
}
char *CBus::getNameOfDriver() {
    return Driver_Name;
}
char *CBus::getRentTime() {
    return rent_time;
}
char *CBus::getReturnTime() {
    return return_time;
}
float CBus::getBusPrice() const {
    return Bus_price;
}
int CBus::getBusNumber() const {
    return Bus_Number ;
}
int CBus::getPassengersNumber() const {
    return Pass_Number ;
}
bool CBus::getRentState() const {
    return isRented;
}