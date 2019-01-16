/* @author Ankit Apurv
*  @date 08/10/2018
*  @Week 9
*  @desc inheritence and virtual functions
*/

#include <iostream>
using namespace std;

class Shape
{
    protected:
        float length, height;

    public:
        void get_data()
        {
            cout << "Length : "; cin >> length;
            cout << "Height : "; cin >> height;
            return;
        }
        virtual void display_area()=0;
        Shape()
        {
            //get_data();
        }
        virtual ~Shape() {}
};

class Triangle : public Shape
{
    public:
        void display_area()
        {
            float area = (height/3) * length;
            cout << "Area : " << area << "\n";
            return;
        }
        Triangle() {}
        ~Triangle() {}
};

class Rectangle : public Shape
{
    public:
        void display_area()
        {
            float area = height * length;
            cout << "Area : " << area << "\n";
            return;
        }
        Rectangle() {}
        ~Rectangle() {}
};

int main(void)
{
    Triangle t;
    t.get_data();
    t.display_area();
    cout << "\n";
    Rectangle r;
    r.get_data();
    r.display_area();
    return 0;
}