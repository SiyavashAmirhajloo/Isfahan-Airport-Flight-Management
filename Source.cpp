#include <iostream>
#include <conio.h>
#include <windows.h>
#include <map>
#include <string>

using namespace std;

struct Time
{
    int hour;
    int min;
};

class flight {
private:
    Time time;
    string model;
    string type;
    int passengers;
    int runway;
    int flight_number;
    int id;
    flight* nextFlight;
public:
    flight(string t) {
        runway = 0;
        setNext(NULL);
        setType(t);
    }
    flight() {
        runway = 0;
        setNext(NULL);
    }
    void setTime(int runways[6][48],int);
    void setModel(string);
    void setType(string);
    void setPassengers(int);
    void setRunway(int);
    void setFlight_num(int);
    void setID(int);
    void setNext(flight*);
    Time getTime() { return time; }
    string getModel() { return model; }
    string getType() { return type; }
    int getPassengers() { return passengers; }
    int getRunway() { return runway; }
    int getFlight_num() { return flight_number; }
    int getID() { return id; }
    flight* getNext() { return nextFlight; }
};

class Airport {
private:
    flight* first;
    int number_of_flights;
public:
    map <string, int> airplane_size;
    int runways[6][48] = { 0 };
    Airport();
    void insert();
    flight* makeFlight(string,int);
    void sort();
    void print();
    void Delete(flight*);
    flight* searchById(int);
    flight* searchByFlightNumber(int);
};

void printmenu();

int main()
{
    Airport isfahan;
    printmenu();
    int key;
    cin >> key;
    while (key > 0) {
        switch (key)
        {
        case 1:
            cout << "Enter number of airplanes: ";
            int num;
            cin >> num;
            for (int i = 0; i < num; i++) {
                cout << "Airplane " << i + 1 << " name: ";
                string name;
                cin.ignore();
                getline(cin, name);
                cout << "Smallest runway for that:(1,6) ";
                int runway;
                cin >> runway;
                isfahan.airplane_size.insert({ name,runway });
            }
            Sleep(1000);
            break;
        case 2:
            isfahan.insert();
            break;
        case 3:
            cout << "Enter the flight number: ";
            int x;
            cin >> x;
            isfahan.Delete(isfahan.searchByFlightNumber(x));
            break;
        case 4:

            break;
        case 5:
            isfahan.print();
            cout << "\nEnter a key for Back\n";
            char a;
            cin >> a;
            break;
        case 0:
            break;
        default:
            break;
        }
        system("cls");
        printmenu();
        cin >> key;
    }
    return 0;
}

void printmenu()
{
    cout << "- - - - - - - Isfahan Airport Flight Management - - - - - - - \n\n";
    cout << "              ------------- MENU --------------\n";
    cout << "(1) Airplanes information\n";
    cout << "(2) Add a flight\n";
    cout << "(3) Search and cancel a flight\n";
    cout << "(4) Sort flights\n";
    cout << "(5) Show schedule\n";
    cout << "(0) Exit\n\n";
    cout << "Enter a key: ";
}

void flight::setNext(flight* x)
{
    nextFlight = x;
}

void flight::setType(string t)
{
    type = t;
}

void flight::setModel(string m)
{
    model = m;
}

void flight::setID(int id)
{
    this->id = id;
}

void flight::setPassengers(int num)
{
    passengers = num;
}

void flight::setFlight_num(int num)
{
    flight_number = num;
}

void flight::setTime(int runways[6][48], int s_r)
{
    cout << "Set flight time by System?(y for yes, n for no) ";
    char by_s;
    cin >> by_s;
    int i;
    if (getRunway() > 0) {
        for (i = 0; i < 48 && getID() != runways[getRunway() - 1][i]; i++);
        runways[getRunway() - 1][i] = 0;
        if (by_s == 'y') {
            for (i = i + 1; i < 48 && runways[getRunway() - 1][i] != 0; i++);
            runways[getRunway() - 1][i] = getID();
        }
        if (by_s == 'n') {
            time.hour = (i) / 2;
            if ((i) % 2 == 1)time.min = 0;
            else time.min = 30;
            cout << "Your flight time must be after than " << time.hour << " : " << time.min << endl;
            cout << "Hour: ";
            cin >>time.hour;
            cout << "Minute:(0 or 30) ";
            cin >> time.min;
            i = time.hour * 2 - 1;
            if (time.min == 30)i++;
            if (runways[getRunway() - 1][i] != 0) {
                cout << "There is a flight at this time.\nSystem is set flight time.\n";
                for (i = i + 1; i < 48 && runways[getRunway() - 1][i] != 0; i++);
                if (i == 48) {
                    for (int j = getRunway(); j < 6; j++) {
                        for (i = 0; i < 48 && runways[j][i] == 0; i++);
                        if (i < 48) {
                            setRunway(j + 1);
                            break;
                        }
                    }
                }
            }
        }
    }
    if (getRunway() == 0) {
        if (by_s == 'y') {
            for (i = 0; i < 48; i++) {
                int j;
                for (j = s_r - 1; j < 6; j++) {
                    if (runways[j][i] == 0) {
                        runways[j][i] = id;
                        break;
                    }
                }
                if (j < 6) {
                    setRunway(j + 1);
                    break;
                }
            }   
        }
        if (by_s == 'n') {
            cout << "Hour: ";
            cin >> time.hour;
            cout << "Minute:(0 or 30) ";
            cin >> time.min;
            i = time.hour * 2;
            if (time.min == 30)i++;
            for (i; i < 48; i++) {
                int j;
                for (j = s_r - 1; j < 6; j++) {
                    if (runways[j][i] == 0) {
                        runways[j][i] = id;
                        break;
                    }
                }
                if (j < 6) {
                    setRunway(j + 1);
                    break;
                }
            }
        }
    }
    time.hour = (i) / 2;
    if ((i) % 2 == 0)time.min = 0;
    else time.min = 30;
    cout << "\nThis flight time is " << time.hour << " : " << time.min << endl;
}

void flight::setRunway(int rw)
{
    runway = rw;
}

Airport::Airport()
{
    number_of_flights = 0;
}

flight* Airport::makeFlight(string type, int id)
{
    flight* p = new flight;
    p->setType(type);
    string model;
    cout << "Airplane Model: ";
    cin.ignore();
    getline(cin, model);
    p->setModel(model);
    p->setID(id);
    int num;
    cout << "Number of passengers: ";
    cin >> num;
    p->setPassengers(num);
    cout << "Flight number: ";
    cin >> num;
    p->setFlight_num(num);
    p->setTime(runways, airplane_size[model]);
    return p;
}

void Airport::insert()
{
    string type;
    cout << "Which type?(Arrival or Exit) ";
    cin.ignore();
    getline(cin, type);
    cout << "Enter flight ID: ";
    int id;
    cin >> id;
    if (first == NULL) {
        first = makeFlight(type,id);
        cout << "Runway: " << first->getRunway() << endl;
        Sleep(4000);
        return;
    }
    flight* p = first;
    if (type == "Exit" && searchById(id) != NULL) {
        searchById(id)->setType(type);
        searchById(id)->setTime(runways, airplane_size[searchById(id)->getModel()]);
        cout << "Runway: " << searchById(id)->getRunway() << endl;
        Sleep(4000);
        return;
    }
    while (p->getNext() != NULL) {
        p = p->getNext();
    }
    p->setNext(makeFlight(type, id));
    cout << "Runway: " << p->getRunway() << endl;
    Sleep(4000);
}

flight* Airport::searchById(int id)
{
    flight* p= first;
    while (p != NULL) {
        if (p->getID() == id) return p;
        p = p->getNext();
    }
    return NULL;
}

void Airport::print()
{
    flight* p = first;
    cout << "\t-------Exit-------\n\n";
    while (p != NULL) {
        if (p->getType() == "Exit") {
            cout << "Flight number: " << p->getFlight_num() << endl;
            cout << "Model: " << p->getModel() << endl;
            cout << "Time: " << p->getTime().hour << ":" << p->getTime().min << endl;
            cout << "Number of passengers: " << p->getPassengers() << endl;
            cout << "ID: " << p->getID() << endl;
            cout << "Runway: " << p->getRunway() << endl;
            cout << endl;
        }
        p = p->getNext();
    }
    p = first;
    cout << "\t-------Arrival-------\n\n";
    while (p != NULL) {
        if (p->getType() == "Arrival") {
            cout << "Flight number: " << p->getFlight_num() << endl;
            cout << "Model: " << p->getModel() << endl;
            cout << "Time: " << p->getTime().hour << ":" << p->getTime().min << endl;
            cout << "Number of passengers: " << p->getPassengers() << endl;
            cout << "ID: " << p->getID() << endl;
            cout << "Runway: " << p->getRunway() << endl;
            cout << endl;
        }
        p = p->getNext();
    }
}
void Airport::Delete(flight* p)
{
    if (p == NULL) {
        cout << "There is not a flight with this flight number.\n";
        Sleep(3000);
        return;
    }
    if (p == first) {
        flight* q = first;
        first = q->getNext();
        delete q;
        cout << "the flight has been canceled.\n";
        Sleep(3000);
        return;
    }
    flight* q = first;
    while (q->getNext() != p) {
        q = q->getNext();
    }
    q->setNext(p->getNext());
    delete p;
    cout << "the flight has been canceled.\n";
    Sleep(3000);
}

flight* Airport::searchByFlightNumber(int num)
{
    flight* p = first;
    while (p != NULL) {
        if (p->getFlight_num() == num)return p;
        p = p->getNext();
    }
    return NULL;
}

void Airport::sort()
{
    flight* p = first;
    flight* q = NULL;
    if (first == NULL)
    {
        return;
    }
    while (p != NULL)
    {
        q = p->getNext();
        while (q != NULL)
        {
            if (p->getTime().hour > q->getTime().hour) {
                Time temp = p->getTime();
                p->getTime() = q->getTime();
                q->getTime() = temp;
            }
            else if (p->getTime().hour == q->getTime().hour) {
                if (p->getTime().min > q->getTime().min) {
                    Time temp = p->getTime();
                    p->getTime() = q->getTime();
                    q->getTime() = temp;
                }
            }
            q = q->getNext();
        }
        p = p->getNext();
    }
}