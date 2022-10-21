#ifndef VISITOR_H
#define VISITOR_H

using namespace std;

class Visitor {
    private: 
        string name {"x"};
        string address {"x"}; 
        string email {"x"};
        string reason {"x"};
        bool isAlumni {true};
    public:
        Visitor() = default;
        Visitor(string, string, string, string, bool);

        void setName(string);
        string getName();

        void setAddress(string);
        string getAddress();

        void setEmail(string);
        string getEmail();

        void setReason(string);
        string getReason();

        void setIsAlumni(bool);
        string getIsAlumni();
};

#endif