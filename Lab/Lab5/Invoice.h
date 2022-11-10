#ifndef INVOICE_H
#define INVOICE_H
#include "employee.h"
#include "student.h"
#include "visitor.h"
#include "vendor.h"
#include "car.h"
#include "lowEmission.h"
#include "motorcycle.h"
#include "moped.h"

class Invoice{
    private:
        double permitPrice;
        double discount;
        double serviceCharge;
        double totalPrice;
        std::string permitType;
    public:
        Invoice();
        Invoice(double pp, double d, double sc);
        double getPermitPrice();
        double getDiscount();
        double getServiceCharge();
        std::string getPermitType();
        bool setPermitPrice(double pp);
        bool setDiscount(double d);
        bool setServiceCharge(double sc);
        bool setPermitType(std::string pt);
        double calcTotalPrice();
        std::string invoicePrintOut(Employee& myEmployee);
        std::string invoicePrintOut(Student& myEmployee);
        std::string invoicePrintOut(Visitor& myEmployee);
        std::string invoicePrintOut(Vendor& myEmployee);
        std::string invoicePrintOut(Car& myVehicle);
        std::string invoicePrintOut(lowEmission& myVehicle);
        std::string invoicePrintOut(Motorcycle& myVehicle);
        std::string invoicePrintOut(Moped& myVehicle);
        std::string invoicePrintOut();
};

#endif