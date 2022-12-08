/*
Abdelrahman Saleh -- 211000536
John Moufid -- 211000206
Hazem Swelam -- 211001089
Rawan Khaled -- 211002079
Ziena Salah -- 211000992
 */
#include "vehicle.h"
#include "customer.h"
#include "Bus.h"
#include <bits/stdc++.h>
using namespace std;
void printAllCarsInfo(int nc, CVehicle vehicle[]){
    cout<<"Cars details: "<<endl;
    for (int i = 0; i < nc; ++i) {
        cout<<"Details of car number "<<i+1<<endl;
        vehicle[i].get_cars_info(vehicle[i]);
    }
}

void loginSuccess(int noCars, CVehicle vehicle[],CCustomer customer){
    cout<<"Enter car number: ";
    int carNo;//car number to check
    cin>>carNo;
    int f=0;//to store if found
    int rem; // to store car place in array
    for (int i = 0; i < noCars; ++i) {
        if(vehicle[i].getCarNumber()==carNo){f=1;rem=i;break;}//if found car number entered f=1 and store place and stop searching, if not then keep looping till you do, if not goto else on line 43
    }
    if(f==1){ //if found
        if(vehicle[rem].getRentState()){ // if rented
            cout<<"Car is rented by customer of ID "<<vehicle[rem].getCustomerID()<<", try again? (Y/N)"; //print id of renter
            char c;
            cin>>c;
            if (c=='Y' || c=='y'){ //if to try again do recursion
                loginSuccess(noCars,vehicle,customer);
            }
            else{cout<<"Thank you <3";} //if not leave
        }
        else{vehicle[rem].Rent_car(vehicle[rem]);// rent it
            vehicle[rem].setCustomerID(customer.getCustomerID()); // set customer id with logged in customer
            printAllCarsInfo(noCars,vehicle); // and print to see
        } //if found and not rented, rent it
    }
    else{cout<<"Car number not found, try again? (Y/N)"; // car id not found
        char c;
        cin>>c;
        if (c=='Y'|| c=='y'){ // to try again
            loginSuccess(noCars,vehicle,customer); //return to start of loop , line 20
        }
        else{cout<<"Thank you <3";}
    }
}

void login(int nc, CCustomer customer[], int noCars, CVehicle vehicle[]){
    char email[50],password[50];
    cout<<"Please login to access car rental program: \nEnter your email: ";
    cin>>email;//user email
    cout<<"Please enter your password: ";
    cin>>password;//user password
    int x=0;// to check if true
    int rem;//to store customer number
    for (int i = 0; i < nc; ++i) {
        if(!strcmp(customer[i].getCustomerEmail(),email)&&!strcmp(customer[i].getEmailPass(),password)) //if email and password match any user in the system
        {
            x=1;
            rem=i;//to store customer position in array to access later
            break;
        } //if credentials true
    }
    if(x==1){
        cout<<"Login successful \nPlease pick a car to rent from the below list:\n ";
        printAllCarsInfo(noCars,vehicle); //print cars list to choose from
        loginSuccess(noCars,vehicle,customer[rem]); //refer to log in success
    }
    else{
        cout<<"Email or password incorrect, try again? (Y/N)"; //credentials false
        char c;
        cin>>c;
        if (c=='Y'|| c=='y'){login(nc,customer,noCars,vehicle);} //try again from the start of the function, line 47
    }
}

int main(){
    int nc,n_customer,n_bus;
    cout<<"Enter number of customers: ";
    cin>>n_customer;
    CCustomer customer[n_customer];//array of customers (classes)
    for (int i = 0; i < n_customer; ++i) { //setter
        cout<<"Enter details for customer number "<<i+1<<endl;
        customer[i].setCustomerID(i+1); //automatically set customer id
        customer[i].addCustomerDetails(customer[i]); //manually add rest of customer details
    }

    cout<<"Enter number of cars: ";
    cin>>nc;//number of cars
    CVehicle vehicle[nc];//array of cars
    for (int i = 0; i < nc; ++i) { //setter
        cout<<"Enter details for car number "<<i+1<<endl;
        vehicle[i].setCarNumber(i+1); //automatically set car number by i+1
        vehicle[i].addCarDetails(vehicle[i]);//manually add rest of car details
        cout<<"Is the car rented? (Y/N)";
        char c;
        cin>>c;
        if(c == 'Y'|| c=='y'){ //if rented
            vehicle[i].Rent_car(vehicle[i]); //rent car
            int cusID;
            jump:
            cout<<"Enter ID of renter: ";
            cin>>cusID;
            int x=0;
            for(int j=0;j<n_customer;j++){
                if(customer[j].getCustomerID()==cusID)
                    {
                    x=1;break;
                    }
            } //look for customer id in the system
            if(x==0){
                cout<<"Customer ID not found, Try again? (Y/N)";
                char a;
                cin>>a;
                if(a == 'Y'|| a=='y') goto jump;
                else continue; // I know it's not necessary here, but I'm afraid if I remove it there might be errors
            }
            vehicle[i].setCustomerID(cusID); //lock car with customer id of renter
        }
        else {
            continue;
        }
    }

    cout<<"Enter number of buses: ";
    cin>>n_bus;
    CBus bus[n_bus]; //array of buses
    for (int i = 0; i < n_bus; ++i) {
        cout<<"Enter details for bus number "<<i+1<<endl;
        bus[i].setBusNumber(i+1);//automatically set bus id
        bus[i].addBusDetails(bus[i]);//manually add rest of bus details
        cout<<"Is the bus rented? (Y/N)";
        char c;
        cin>>c;
        if(c == 'Y'|| c=='y'){//if true rent
            bus[i].Rent_Bus(bus[i]);
            int cusID;
            cout<<"Enter ID of renter: ";
            cin>>cusID;
            bus[i].setCustomerID(cusID); //lock car with customer id of renter
        }
        else
            continue;
    }
    printAllCarsInfo(nc,vehicle);
    cout<<"Buses details: ";
    if (n_bus==0){
        cout<<"None";
    }
    cout<<endl;
    for (int i = 0; i < n_bus; ++i) {
        cout<<"Details of bus number "<<i+1<<endl;
        bus[i].get_Bus_info(bus[i]);
    }
    login(n_customer, customer,nc,vehicle);
    system("pause");
}
