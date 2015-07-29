
#include <iostream>
using namespace std;

class Employee{
protected:
  int id;
  double netPay;
public:
  Employee();
  Employee(int id);
  Employee(const Employee &e);
  int getId() const;
  void setId(int d);
  double getNetPay() const;
  bool opreator == (const Employee &e) const;
  friend ostream & operator <<(ostream &out, const Employee &e);
};
class HourlyEmployee : public Employer{
private:
  double hrlyRate;
  double hrdWorked;
public:
  static const double Entry = 10.5;
  static const double Associate = 12.5;
  static const double Partner = 50.0;
  HourlyEmployee();
  HourlyEmployee(int id, double theWageRate, double theHours);
  HourlyEmployee(const HourlyEmployee &e);
  void setRate(double rate);
  void setHoursWorked(double hrs);
  void 
};
Employee:Employee():id(0),netPay(0){}
Employee::Employee(int i):id(i),netPay(0){}
Employee::Employee(const Employee &e):id(e.id),netPay(e.netPay){}

bool Employee::getId() const {
  return id;
}
double Employee::getNetPay() const {
  return netPay;
}

void Employee::setId(int i) {
  id = i;
}

bool Employee::operator == (const Employee &e) const {
  return id == e.id && netPay == e.netPay;
}

ostream & operator << (ostream & out, const Employee &e) {
  out<< "id:"<<e.id<<" net Pay:"<<e.netPay<<endl;
  return out;
}


HourlyEmployee::HourlyEmployee():Employee(),hrlyRate(0), hrsWorked(0){}
HourlyEmployee::HourlyEmployee(int id, double theWageRate, double theHours):Employee(id){
    hrlyRate = theWageRate;
    hrsWorked = theHours;
    netPay = hrlyRate*hrsWorked;
  }
HourlyEmployee::HourlyEmployee(const HourlyEmployee &e):Employee(e){}  
void HourlyEmployee::setRate(double rate) {
  hrlyRate = rate;
  netPay = hrlyRate*hrsWorked;
}

bool HourlyEmployee:operator ==(const HourlyEmployee &e) const{
  return Employee::operator == (e) && hrlyRate == e.hrlyRate && hrsWorked == e.hrsWorked;
}
void HourlyEmployee::srtNatPay() {
  netPay = hrlyRate*hrsWorked;
}
void HourlyEmployee::setHoursWorked(doube hrs) {
  hrsWorked = hrs;
}

istream & operator >> (istream &in, HourlyEmployee &s) {
  cout<< "Enter an ID: "<<endl;
  in>>e.id;
  cout<<"Enter hrly rate: \n";
  in>>e.hrlyRate;
  cout<<"Enter the number of hours worked" << endl;
  in >> e.hrsWorked;
  e.setNetPay();
  return in;
}
ostream & operator << (ostream &out, const HourlyEmployee &e) {
  out<< (Employee)e << endl;
  out<< "Rate " << e.hrlyRate << endl;
  out<< " Hours Worked " << e.hrsWorked;
  return out;
}
