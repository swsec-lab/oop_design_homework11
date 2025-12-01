#include <iostream>
#include <memory>
#include <vector>
#include "character.h"
#include "undead.h"
#include "MySharedPtr.h"
using namespace std;

void equip_test1(shared_ptr<Character> c1) {
    c1 = make_shared<Armor>(c1);
    c1 = make_shared<Boots>(c1);
    c1 = make_shared<Sword>(c1);
    cout << c1->getDescription()
         << " | Attack: " << c1->getAttack()
         << " | Speed: " << c1->getSpeed()
         << " | Defense: " << c1->getDefense() << endl;
}

void equip_test2(shared_ptr<Character> c1) {
    c1 = make_shared<Armor>(c1);
    c1 = make_shared<Bow>(c1);
    cout << c1->getDescription()
         << " | Attack: " << c1->getAttack()
         << " | Speed: " << c1->getSpeed()
         << " | Defense: " << c1->getDefense() << endl;
}

void equip_test3(shared_ptr<Character> c1) {
    c1 = make_shared<Boots>(c1);
    c1 = make_shared<Staff>(c1);
    cout << c1->getDescription()
         << " | Attack: " << c1->getAttack()
         << " | Speed: " << c1->getSpeed()
         << " | Defense: " << c1->getDefense() << endl;
}

void doTest2() {
    cout << "=== Test 2 ===" << endl;
    vector<shared_ptr<Character>> players;
    players.push_back(make_shared<Knight>());
    players.push_back(make_shared<Wizard>());
    players.push_back(make_shared<Archer>());
    players.push_back(make_shared<UndeadAdapter>(make_shared<Zombie>()));
    players.push_back(make_shared<UndeadAdapter>(make_shared<Skeleton>()));
    players.push_back(make_shared<UndeadAdapter>(make_shared<Lich>()));


    for(auto player: players){
        cout << "-------------------------------------------------------------" << endl;
        equip_test1(player);
        equip_test2(player);
        equip_test3(player);
    }
    cout << "-------------------------------------------------------------" << endl;

}

void doTest1(){
    struct Student{
        string name;
        Student(string name): name(name) {};
        Student() = delete;
        ~Student() { cout << "Delete Student " << name << endl; }
    };

    cout << "=== Test 1 ===" << endl;
    MySharedPtr<Student> p1(new Student("Jack"));
    cout << "p1 use_count: " << p1.use_count() << endl;
    {
        MySharedPtr<Student> p2 = p1; // 복사
        cout << "After copy, p1 use_count: " << p1.use_count() << endl;
        {
            MySharedPtr<Student> p3 = p2; // 복사
            cout << "After copy, p1 use_count: " << p1.use_count() << endl;
        }
        cout << "After p3 goes out of scope, p1 use_count: " << p1.use_count() << endl;

        p2.reset(new Student("Kim"));
        cout << "After p2 reset, p1 use_count: " << p1.use_count() << ":" << p1.get()->name << endl;
        cout << "After p2 reset, p2 use_count: " << p2.use_count() << ":" << p2.get()->name << endl;
    }
    p1.reset();

    cout << "After p1 reset, p1 use_count: " << p1.use_count() << endl;

    if(p1.get() == nullptr)
        cout << "After p1 reset, p1 is nullptr" << endl;
}

int main(int argc, const char *argv[]) {
    if(argc == 2){
        switch(atoi(argv[1])){
            case 1:
                doTest1();
                return 0;
            case 2:
                doTest2();
                return 0;
        }
    }
    doTest1();
    doTest2();

    return 0;
}
