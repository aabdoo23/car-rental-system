#include <bits/stdc++.h>
using namespace std;
class CCustomer {
private:
    //private variables
    int Customer_ID=0;
    char Cus_name[50]="", Cus_Email[50]="", Email_Pass[50]="";
public:

    //setters
    void setCustomerID(int Cus_ID);
    void setCustomerName( char Cus_name[50] );
    void setCustomerEmail(char Cus_Email[50] );
    void setEmailPass(char Email_Password[50]);

    //getters
    int getCustomerID() const ;
    char *getCustomerName() ;
    char *getCustomerEmail();
    char *getEmailPass() ;

    //addDetails
    void addCustomerDetails(CCustomer Customer){
        cout<<"Enter Customer Name: ";
        cin.ignore();
        cin.getline(Cus_name,50);
        Customer.setCustomerName(Cus_name);
        cout<<"Enter Customer E-mail: ";
        cin.getline(Cus_Email,50);
        Customer.setCustomerEmail(Cus_Email);
        cout<<"Enter Customer e-mail Pass: ";
        cin.getline(Email_Pass,50);
        Customer.setEmailPass(Email_Pass);
    }

    void get_customer_info(CCustomer Customer){
        cout<<"Customer ID: "<<Customer.getCustomerID()<<endl;
        cout<<"Customer Name: "<<Customer.getCustomerName()<<endl;
        cout<<"Customer E-mail: "<<Customer.getCustomerEmail()<<endl;
        cout<<"Customer e-mail Pass: "<< Customer.getEmailPass()<<endl;

    }
};

// Member functions definitions

//setters
void CCustomer::setCustomerID(int Cus_ID) {
    Customer_ID=Cus_ID;
}
void CCustomer::setCustomerName( char *name ) {
    strcpy(Cus_name, name);
}
void CCustomer::setCustomerEmail(char *Email) {
    strcpy(Cus_Email, Email);
}
void CCustomer::setEmailPass(char *Password) {
    strcpy(Email_Pass, Password);
}

// getters
int CCustomer::getCustomerID () const {
    return Customer_ID ;
}
char *CCustomer::getCustomerName() {
    return Cus_name;
}
char *CCustomer::getCustomerEmail() {
    return Cus_Email;
}
char *CCustomer::getEmailPass() {
    return Email_Pass;
}