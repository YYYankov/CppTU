#include <iostream>
#include <cmath>

class Rectangle
{
private:
    double a, b;

public:
    Rectangle();
    double face();
    double face(double *perimeter);
    ~Rectangle();
};

Rectangle::Rectangle()
{
    std::cout << "\nEnter the length and width of the rectangle:\n";
    std::cin >> a >> b;
    while (!((a > 0) && (b > 0)))
        ;
}

double Rectangle::face()
{
    return a * b;
}

double Rectangle::face(double *perimeter)
{
    *perimeter = 2 * (a + b);
    return a * b;
}

Rectangle::~Rectangle()
{
    std::cout << "\nDestructing object rectangle!\n";
}

int main()
{
    Rectangle rect;
    double perimeter;
    std::cout << "Area of the rectangle: " << rect.face() << std::endl;
    std::cout << "Perimeter of the rectangle: " << rect.face(&perimeter) << std::endl;
    std::cout << "Stored Perimeter: " << perimeter << std::endl;
    return 0;
}

// 2
#include <iostream>

class truck;

class car
{
private:
    int passengers;
    int speed;

public:
    car(int p, int s) : passengers(p), speed(s) {}

    friend int sp_greater(car c, truck t);
    friend double time_to_cover_distance(int distance, car c);
};

class truck
{
private:
    int weight;
    int speed;

public:
    truck(int w, int s) : weight(w), speed(s) {}

    friend int sp_greater(car c, truck t);
    friend double time_to_cover_distance(int distance, truck t);
};

int sp_greater(car c, truck t)
{
    return c.speed - t.speed;
}

double time_to_cover_distance(int distance, car c)
{
    return static_cast<double>(distance) / c.speed;
}

double time_to_cover_distance(int distance, truck t)
{
    return static_cast<double>(distance) / t.speed;
}

int main()
{
    int t;
    car c1(6, 55), c2(2, 120);
    truck t1(10000, 55), t2(20000, 72);
    int distance = 200;

    std::cout << "Comparing c1 and t1:\n";
    t = sp_greater(c1, t1);
    if (t < 0)
        std::cout << "Truck is faster.\n";
    else if (t == 0)
        std::cout << "Car and truck speed is the same.\n";
    else
        std::cout << "Car is faster.\n";

    std::cout << "\nComparing c2 and t2:\n";
    t = sp_greater(c2, t2);
    if (t < 0)
        std::cout << "Truck is faster.\n";
    else if (t == 0)
        std::cout << "Car and truck speed is the same.\n";
    else
        std::cout << "Car is faster.\n";

    std::cout << "\nTime to cover " << distance << " kilometers with car c1: " << time_to_cover_distance(distance, c1) << " hours.\n";
    std::cout << "Time to cover " << distance << " kilometers with truck t1: " << time_to_cover_distance(distance, t1) << " hours.\n";

    return 0;
}

// 3
#include <iostream.h>
class truck;
class car
{
    int passengers;
    int speed;

public:
    car(int p, int s)
    {
        passengers = p;
        speed = s;
    }
    int sp_greater(truck t);
};
class truck
{
    int weight;
    int speed;

public:
    truck(int w, int s)
    {
        weight = w;
        speed = s;
    }
    friend int car::sp_greater(truck t);
};

int car::sp_greater(truck t)
{
    return speed - t.speed;
    трябва да се подаде само
}
int main()
{
    int t;
    car c1(6, 55), c2(2, 120);
    truck t1(10000, 55), t2(20000, 72);
    cout << ”Comparing c1 and t1 :\n”;
    t = c1.sp_greater(t1);
    else if (t == 0) cout << ”Car and truck speed is the same.\n”;
    else cout << ”Car is faster.\n”;
    cout << ”\nComparing c2 and t2 :\n”;
    t = c2.sp_greater(t2);
    else if (t == 0) cout << ”Car and truck speed is the same.\n”;
    else cout << ”Car is faster.\n”;
    return 0;
}
