#pragma once

class Vendor {
  private:
    std::string name;
    std::string address;
    std::string email;
    std::string sellObject;
    int employeeCount;

  public:
    Vendor();
    Vendor(std::string n, std::string a, std::string e, std::string s, int c);
    std::string getName();
    std::string getAddress();
    std::string getEmail();
    std::string getSellObject();
    int getEmployeeCount();
    bool setName(std::string n);
    bool setAddress(std::string a);
    bool setEmail(std::string e);
    bool setSellObject(std::string s);
    bool setEmployeeCount(int c);
};
