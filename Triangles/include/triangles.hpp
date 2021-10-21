#include <iostream>
#include <cmath>

struct Point {

private:
    double x_, y_, z_;

public:
    // constructor
    Point() {x_ = 0; y_ = 0; z_ = 0;}
    // constructor (перегрузка конструктора)
    Point(double x_val, double y_val, double z_val) :
        x_(x_val),
        y_(y_val),
        z_(z_val) {}
    ~Point() {}

    // getters
    double GetX(){ return x_; }
    double GetY(){ return y_; }
    double GetZ(){ return z_; }

    // setters
    void SetX(double x_value){ x_ = x_value; }
    void SetY(double y_value){ y_ = y_value; }
    void SetZ(double z_value){ z_ = z_value; }

};


struct Sigment {

private:
    Point begin_, end_;
    double  AbcVec;
public:

    Sigment(Point begin_pt, Point end_pt) :
        begin_(begin_pt),
        end_ (end_pt) {}
    ~Sigment() {}

    Point GetBegin() { return begin_; }
    Point GetEnd()   { return end_; }

    void SetBegin(Point begin_v) { begin_ = begin_v; }
    void SetEnd  (Point end_v)   { end_   = end_v; }

    double GetAbcVec() {
        return sqrt(pow(begin_.GetX() - end_.GetX(), 2) + pow(begin_.GetY() - end_.GetY(), 2) + pow(begin_.GetZ() - end_.GetZ(), 2));
    }

};

struct Triangle {
private:
    Point A_;
    Point B_;
    Point C_;

    double P;
    double Square;
public:
    Triangle(Point A_pt, Point B_pt, Point C_pt) :
        A_(A_pt),
        B_(B_pt),
        C_(C_pt) {}
    ~Triangle() {}

    double GetP() {
        Sigment a(A_, B_);
        Sigment b(B_, C_);
        Sigment c(C_, A_);

        return a.GetAbcVec() + b.GetAbcVec() + c.GetAbcVec();
    }

    double GetSquare() {

        Sigment a(A_, B_);
        Sigment b(B_, C_);
        Sigment c(C_, A_);

        double p = GetP() / 2;
        return sqrt(p * (p - a.GetAbcVec()) * (p - b.GetAbcVec()) * (p - c.GetAbcVec()));
    }
};