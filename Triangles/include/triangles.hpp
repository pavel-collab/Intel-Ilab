#include <iostream>
#include <cmath>

template <typename type>
struct Point {

private:
    type x_, y_, z_;

public:
    // constructor
    Point() {x_ = 0; y_ = 0; z_ = 0;}
    // constructor (перегрузка конструктора)
    Point(type x_val, type y_val, type z_val) :
        x_(x_val),
        y_(y_val),
        z_(z_val) {}
    ~Point() {}

    // getters
    type GetX(){ return x_; }
    type GetY(){ return y_; }
    type GetZ(){ return z_; }

    // setters
    void SetX(type x_value){ x_ = x_value; }
    void SetY(type y_value){ y_ = y_value; }
    void SetZ(type z_value){ z_ = z_value; }

};

template <typename type, typename Point>
struct Vector {

private:
    Point begin_, end_;
    type  AbcVec;
public:

    Vector(Point begin_pt, Point end_pt) :
        begin_(begin_pt),
        end_ (end_pt) {}
    ~Vector() {}

    Point GetBegin() { return begin_; }
    Point GetEnd()   { return end_; }

    void SetBegin(Point begin_v) { begin_ = begin_v; }
    void SetEnd  (Point end_v)   { end_   = end_v; }

    double GetAbcVec() {
        return sqrt(pow(begin_.GetX() - end_.GetX(), 2) + pow(begin_.GetY() - end_.GetY(), 2) + pow(begin_.GetZ() - end_.GetZ(), 2));
    }

};

template <typename type, typename Point>
struct Triangle {
private:
    Point A_;
    Point B_;
    Point C_;

    type   P;
    double Square;
public:
    Triangle(Point A_pt, Point B_pt, Point C_pt) :
        A_(A_pt),
        B_(B_pt),
        C_(C_pt) {}
    ~Triangle() {}

    double GetP() {
        Vector<type, Point> a(A_, B_);
        Vector<type, Point> b(B_, C_);
        Vector<type, Point> c(C_, A_);

        return a.GetAbcVec() + b.GetAbcVec() + c.GetAbcVec();
    }

    double GetSquare() {

        Vector<type, Point> a(A_, B_);
        Vector<type, Point> b(B_, C_);
        Vector<type, Point> c(C_, A_);

        double p = GetP() / 2;
        return sqrt(p * (p - a.GetAbcVec()) * (p - b.GetAbcVec()) * (p - c.GetAbcVec()));
    }
};