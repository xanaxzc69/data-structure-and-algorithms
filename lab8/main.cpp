
#include <iostream>
using namespace std;

class Researcher {
protected:
    string name, field;
public:
    Researcher(string n, string f): name(n), field(f) {}
    void showR(){ cout<<"Researcher: "<<name<<" "<<field<<endl; }
};

class Teacher {
protected:
    string uni;
    int hours;
public:
    Teacher(string u,int h): uni(u), hours(h){}
    void showT(){ cout<<"Teacher: "<<uni<<" "<<hours<<endl; }
};

class Professor: public Researcher, public Teacher {
    int pubs;
    string degree;
public:
    Professor(string n,string f,string u,int h,int p,string d)
    : Researcher(n,f), Teacher(u,h), pubs(p), degree(d) {}

    void show(){
        showR();
        showT();
        cout<<"Publications: "<<pubs<<" Degree: "<<degree<<endl;
    }

    friend void check(Professor p);
};

void check(Professor p){
    if(p.pubs<10) cout<<"Low scientific activity\n";
    else cout<<"Good activity\n";
}

int main(){
    Professor p("Ivan","CS","KPI",200,8,"PhD");
    p.show();
    check(p);
    return 0;
}
