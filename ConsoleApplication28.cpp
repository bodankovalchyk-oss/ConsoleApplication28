#include <iostream>
#include <string>
using namespace std;

class Airplane
{
    string model;
    string type;
    int passengers;
    int maxPassengers;

public:
    Airplane()
    {
        model = "";
        type = "";
        passengers = 0;
        maxPassengers = 0;
    }

    Airplane(string model, string type, int passengers, int maxPassengers)
    {
        this->model = model;
        this->type = type;
        this->maxPassengers = maxPassengers;
        if (passengers > maxPassengers)
        {
            cout << "Too many passengers, maximum is set" << endl;
            this->passengers = maxPassengers;
        }
        else if (passengers < 0)
            this->passengers = 0;
        else
            this->passengers = passengers;
    }

    Airplane& operator++()
    {
        if (passengers < maxPassengers)
            passengers++;
        else
            cout << "Airplane " << model << " is full" << endl;
        return *this;
    }

    Airplane& operator--()
    {
        if (passengers > 0)
            passengers--;
        else
            cout << "Airplane " << model << " is empty" << endl;
        return *this;
    }

    Airplane& operator()(int count)
    {
        if (passengers + count > maxPassengers)
            cout << "Cannot add " << count << " passengers to " << model << endl;
        else
            passengers += count;
        return *this;
    }

    friend bool operator==(const Airplane& a, const Airplane& b);
    friend bool operator>(const Airplane& a, const Airplane& b);
    friend ostream& operator<<(ostream& os, const Airplane& a);
};

bool operator==(const Airplane& a, const Airplane& b)
{
    return a.type == b.type;
}

bool operator>(const Airplane& a, const Airplane& b)
{
    return a.maxPassengers > b.maxPassengers;
}

ostream& operator<<(ostream& os, const Airplane& a)
{
    os << "Model: " << a.model << ", type: " << a.type
        << ", passengers: " << a.passengers << "/" << a.maxPassengers;
    return os;
}

int main()
{
    Airplane a1("Boeing 737", "passenger", 100, 180);
    Airplane a2("Airbus A380", "passenger", 300, 550);
    Airplane a3("An-225", "cargo", 0, 10);

    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl << endl;

    if (a1 == a2)
        cout << "a1 and a2 have the same type" << endl;
    else
        cout << "a1 and a2 have different types" << endl;

    if (a1 == a3)
        cout << "a1 and a3 have the same type" << endl;
    else
        cout << "a1 and a3 have different types" << endl;

    if (a2 > a1)
        cout << "a2 has more seats than a1" << endl;
    else
        cout << "a1 has at least as many seats as a2" << endl;

    cout << endl;
    ++a1;
    cout << "++a1: " << a1 << endl;
    --a1;
    --a1;
    cout << "--a1 twice: " << a1 << endl;

    a1(15);
    cout << "a1(15): " << a1 << endl;
    a1(100);
    cout << "a1(100): " << a1 << endl;

    a3(10);
    ++a3;
    cout << a3 << endl;

    Airplane a4("Cessna", "private", 0, 4);
    --a4;
    cout << a4 << endl;

    return 0;
}
