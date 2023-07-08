#include <iostream>

using namespace std;

// 1. virtual function
class Base {
public:
    Base() {
        cout<<"base constructor"<<endl;
    }
    // what if we add virtual?
    void run() {
        cout<<"base run"<<endl;
    }
    // what if we add virtual?
    ~Base() {
        cout<<"base destructor"<<endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout<<"derived constructor"<<endl;
    }
    void run() {
        cout<<"derived run"<<endl;
    }
    ~Derived() {
        cout<<"derived destructor"<<endl;
    }
};

void virtualFunction() {
    Base* obj = new Derived();
    obj->run();
    delete obj;
}

// 2. struct VS. class
struct carStruct {
    carStruct() {
        cout<<"struct car"<<endl;
    }
};

class carClass {
public:
    carClass() {
        cout<<"class car"<<endl;
    }
};

void structAndClass() {
    carStruct car1;
    carClass car2;
}

// 3. new VS. malloc
class Apple {
public:
    Apple(string name) {
        cout<<"Apple name is: "<<name<<endl;
    }
};
void newAndMalloc() {
    Apple* apple = new Apple("new");
    Apple* apple2 = (Apple*) malloc(sizeof(Apple*)*1);

    delete apple;
    free(apple2);
}

// 4. RAII
class AppleWrapper {
    Apple* apple;
public:
    AppleWrapper(string name) {
        apple = new Apple(name);
    }
    ~AppleWrapper() {
        delete apple;
    }
};

void RAII() {
    AppleWrapper wrapper("wrapper");
}

//Abstract class
class AbstractOrane {
public:
    AbstractApple() {

    }
    virtual void run() = 0;
};

class Orange : public AbstractOrane {
public:
    Orange() {

    }
    void run() {
        cout<<"Orange run"<<endl;
    };

};

int main() {
    //structAndClass();
    //newAndMalloc();
    //RAII();
    return 0;
}
