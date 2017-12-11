#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

typedef tuple <double, double, double> triple_double_tuple;

double PI = 3.14159265359;

class Triangle{
    public:
    // Constructors
    Triangle (double a, double b, double c, ofstream &fout);
    Triangle (double a, double angle, ofstream &fout);
    Triangle (double a, ofstream &fout);
    //Boolean
    bool isTriangle();
    //Functions
    double area();
    double perimeter();
    //Mutators
    void setSides(double a, double b, double c, ofstream &fout);
    void setSides(double a, double angle, ofstream &fout);
    void setSides(double a, ofstream &fout);
    //Accessors
    triple_double_tuple getAngles();
    triple_double_tuple getSides();
    //Print
    void print(ofstream &fout);

    private:
    double s1, s2, s3;
    double s;
    double angle1, angle2, angle3;
};

int main()
{
    ofstream fout;
    fout.open("testTriangleClass.txt");

    Triangle T (100,100,72, fout);
    fout << "Results for Triangle 1: " << endl;
    T.print(fout);
    fout << endl;
    fout << "------------------------------------------------------" << endl;
    T.setSides(100,100,(100*sqrt(2)), fout);
    fout << "Results for Triangle 1 Reset: " <<endl;
    T.print(fout);
    fout << endl;
    fout << "------------------------------------------------------" << endl;
    T.setSides(100,50,50, fout);
    fout << "Results for Triangle 1 Reset Part 2: " <<endl;
    T.print(fout);

    fout << endl;
    fout << endl;
    fout << endl;

    Triangle T2 (100,72, fout);
    fout << "Results for Triangle 2: " << endl;
    T2.print(fout);
    fout << endl;
    fout << "------------------------------------------------------" << endl;
    T2.setSides(100,90, fout);
    fout << "Results for Triangle 2 Reset: " <<endl;
    T2.print(fout);
    fout << endl;
    fout << "------------------------------------------------------" << endl;
    T2.setSides(100,60, fout);
    fout << "Results for Triangle 2 Reset Part 2: " <<endl;
    T2.print(fout);

    fout.close();

    return 0;
}

Triangle::Triangle (double a, double b, double c, ofstream &fout){
    s1 = a;
    s2 = b;
    s3 = c;
    s = 0.5 * (s1 + s2 + s3);
    if (!isTriangle()){
        fout << s1 << ", " << s2 << ", and " << s3 << " do not make a proper Triangle!" << endl;
    }
    angle1 = (acos((s2*s2+s3*s3-s1*s1)/(2*s2*s3))) * (180/PI);
    angle2 = (acos((s3*s3+s1*s1-s2*s2)/(2*s3*s1))) * (180/PI);
    angle3 = (acos((s1*s1+s2*s2-s3*s3)/(2*s1*s2))) * (180/PI);
}

Triangle::Triangle (double a, double angle, ofstream &fout){
    s1 = a;
    s2 = a;
    s3 = sqrt ((a*a) + (a*a) - (2*a*a*(cos(angle * (PI/180)))));
    s = 0.5 * (s1 + s2 + s3);
    if (!isTriangle()){
        fout << s1 << ", " << s2 << ", and " << s3 << " do not make a proper Triangle!" << endl;
    }
    angle1 = (180-angle)/2;
    angle2 = angle1;
    angle3 = angle;
}

Triangle::Triangle (double a, ofstream &fout){
    s1 = a;
    s2 = a;
    s3 = a;
    s = 1.5 * a;
    if (!isTriangle()){
        fout << s1 << ", " << s2 << ", and " << s3 << " do not make a proper Triangle!" << endl;
    }
    angle1 = 60;
    angle2 = 60;
    angle3 = 60;
}

bool Triangle::isTriangle(){
    return (s>s1) && (s>s2) && (s>s3);
}

double Triangle::area(){
    return sqrt(s * (s-s1) * (s-s2) * (s-s3));
}

double Triangle::perimeter(){
    return s1 + s2 + s3;
}

void Triangle::setSides (double a, double b, double c, ofstream &fout){
    s1 = a;
    s2 = b;
    s3 = c;
    s = 0.5 * (s1 + s2 + s3);
    if (!isTriangle()){
        fout << s1 << ", " << s2 << ", and " << s3 << " do not make a proper Triangle!" << endl;
    }
    angle1 = (acos((s2*s2+s3*s3-s1*s1)/(2*s2*s3))) * (180/PI);
    angle2 = (acos((s3*s3+s1*s1-s2*s2)/(2*s3*s1))) * (180/PI);
    angle3 = (acos((s1*s1+s2*s2-s3*s3)/(2*s1*s2))) * (180/PI);
}

void Triangle::setSides (double a, double angle, ofstream &fout){
    s1 = a;
    s2 = a;
    s3 = sqrt ((a*a) + (a*a) - (2*a*a*(cos(angle * (PI/180)))));
    s = 0.5 * (s1 + s2 + s3);
    if (!isTriangle()){
        fout << s1 << ", " << s2 << ", and " << s3 << " do not make a proper Triangle!" << endl;
    }
    angle1 = (180-angle)/2;
    angle2 = angle1;
    angle3 = angle;
}

void Triangle::setSides (double a, ofstream &fout){
    s1 = a;
    s2 = a;
    s3 = a;
    s = 1.5 * a;
    if (!isTriangle()){
        fout << s1 << ", " << s2 << ", and " << s3 << " do not make a proper Triangle!" << endl;
    }
    angle1 = 60;
    angle2 = 60;
    angle3 = 60;
}

triple_double_tuple Triangle:: getAngles(){
    return make_tuple(angle1, angle2, angle3);
}

triple_double_tuple Triangle:: getSides(){
    return make_tuple(s1, s2, s3);
}

void Triangle::print(ofstream &fout){
    fout << "Side 1: " << s1 << endl;
    fout << "Side 2: " << s2 << endl;
    fout << "Side 3: " << s3 << endl;
    fout << "Angle 1: " << angle1 << endl;
    fout << "Angle 2: " << angle2 << endl;
    fout << "Angle 3: " << angle3 << endl;
    fout << "Perimeter: " << perimeter() << endl;
    fout << "Area: " << area();
}
