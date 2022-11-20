/*This is Class file for Class: CommissionEmployee.h
.h file can not use namespace automatically */

#ifndef COMMISSION_H
#define COMMISSION_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <ctime>

class CommissionEmployee :public Employee
{
public:
          //construcor: const lock argument --> get() functions must be const
          //& --> pass arguement by reference
    CommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, double sales, double rate)
        : Employee(first, last, ssn)
    {
           setGrossSales(sales);
           setCommissionRate(rate);
    }

    //virtual destructor
    virtual ~CommissionEmployee() = default;

    void setGrossSales(double sales)
    {
        if(sales<0.0)
            {throw std::invalid_argument("Gross sales value must greater than 0. ");}

        grossSales=sales;
    }

    double getGrossSales() const
    {
        return grossSales;
    }

    void setCommissionRate(double rate)
    {
        if(rate<=0.0 || rate>=1.0)
            {throw std::invalid_argument("Commission rate value between 0 and 1, exclusive of 0 and 1. ");}

        commissionRate=rate;
    }

    double getCommissionRate() const
    {
        return commissionRate;
    }

    /*override pure virtual function in abstract base class: Employee
      calculate the earning for this derived class object */
    virtual double earnings() const
    {
        //get current month from system time
        time_t now = time(0);
        tm *ltm=localtime(&now);

        int mon=1+ltm->tm_mon;


        if(Employee::getBirthMonth() == mon)
        {
             throw std::runtime_error("Happy birth Day from a throw message in HourlyEmloyee.h: earnings()! \n");
        }
        else
            return getGrossSales()*getCommissionRate();
    }

    //override virtual function in Base Class: display CommissionEmployee object's information as a string returned
    virtual std::string print() const
    {
        std::ostringstream output;
        output<<std::fixed<<std::setprecision(2);
        output<<Employee::print()
              <<"\nGross Sales: "<<getGrossSales()
              <<"\nCommission Rate: "<<getCommissionRate();

        return output.str();    //return a string
    }


private:
    double grossSales;
    double commissionRate;


};




#endif // COMMISSION_H
