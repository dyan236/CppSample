#include <iostream>
#include "LinkedList.h"

int main(){
    std::cout<<"Hello World!"<<std::endl;
    LinkedList<int> list(0);
    for(int i=0;i<10;i++){
        list.add(i);
    }
    std::cout<<"contains(): "<<list.contains(5)<<", "<<list.contains(10)<<std::endl;
    std::cout<<"size(): "<<list.size()<<std::endl;
    list.remove(0);
    list.remove(5);
    list.remove(9);
    list.print();
    std::cout<<std::endl;
    LinkedList<int> list2;
    for(int i=0;i<10;i++)
        list2.add(i);
    std::cout<<"get(): "<<list2.get(0)<<std::endl;
    list2.set(0, 100);
    list2.set(5, 25);
    list2.add(0, 66);
    list2.add(6, 12);
    list2.removeAt(0);
    list2.removeAt(6);
    list2.removeAt(9);
    std::cout<<"indexOf(): "<<list2.indexOf(6)<<std::endl;
    list2.add(6);
    std::cout<<"lastIndexOf(): "<<list2.lastIndexOf(6)<<std::endl;
    std::cout<<"peek(): "<<list2.peek()<<std::endl;
    std::cout<<"poll(): "<<list2.poll()<<std::endl;
    //list2.clear();
    list2.print();
    return 0;
}