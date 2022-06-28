#include "ListNode.h"
template <typename T>
class LinkedList{
private: 
    ListNode<T>* head;
public:
    LinkedList():
        head(NULL)
    {}
    LinkedList(T val):
        head(new ListNode<T>(val))
    {}
    bool contains(T val){
        if(!head)
            return false;
        ListNode<T>* ptr=head;
        while(ptr){
            if(ptr->val==val)
                return true;
            ptr=ptr->next;
        }
        return false;
    }
    int size(){
        if(!head)
            return 0;
        int res=0;
        ListNode<T>* ptr=head;
        while(ptr){
            res++;
            ptr=ptr->next;
        }
        return res;
    }
    bool add(T val){
        if(!head){
            head=new ListNode<T>(val);
            return true;
        }
        ListNode<T>* ptr=head;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=new ListNode<T>(val);
        ptr->next->prev=ptr;
        return true;
    }
    void add(int index, T element){
        if(!head || index<0)
            throw std::out_of_range("Index out of bounds");
        int i=0;
        ListNode<T>* ptr=head;
        ListNode<T>* tmp=new ListNode<T>(element);
        if(index==0){
            head->prev=tmp;
            tmp->next=head;
            head=tmp;
            return;
        }
        ptr=ptr->next;
        i++;
        while(ptr){
            if(i==index){
                ptr->prev->next=tmp;
                tmp->next=ptr;
                tmp->prev=ptr->prev;
                ptr->prev=tmp;
                return;
            }
            ptr=ptr->next;
            i++;
        }
        throw std::out_of_range("Index out of bounds");
    }
    bool remove(T val){
        if(!head)
            return false;
        ListNode<T>* ptr=head;
        if(ptr->val==val){
            if(ptr->next){
                head=ptr->next;
                ptr->next->prev=NULL;
            }
            else{
                head=NULL;
            }
            delete ptr;
            return true;
        }
        ptr=ptr->next;
        while(ptr){
            if(ptr->val==val){
                if(ptr->next){
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                }
                else{
                    ptr->prev->next=NULL;
                }
                delete ptr;
                return true;
            }
            ptr=ptr->next;
        }
        return false;
    }
    T removeAt(int index){
        if(!head || index<0)
            throw std::out_of_range("Index out of bounds");
        int i=0;
        ListNode<T>* ptr=head;
        if(index==0){
            if(ptr->next){
                ptr->next->prev=NULL;
                head=ptr->next;
            }
            else{
                head=NULL;
            }
            T tmp=ptr->val;
            delete ptr;
            return tmp;
        }
        ptr=ptr->next;
        i++;
        while(ptr){
            if(i==index){
                if(ptr->next){
                    ptr->next->prev=ptr->prev;
                    ptr->prev->next=ptr->next;
                }
                else{
                    ptr->prev->next=NULL;
                }
                T tmp=ptr->val;
                delete ptr;
                return tmp;
            }
            ptr=ptr->next;
            i++;
        }
        throw std::out_of_range("Index out of bounds");
    }
    void clear(){
        if(!head)
            return;
        ListNode<T>* ptr=head;
        while(ptr){
            ListNode<T>* tmp=ptr->next;
            delete ptr;
            ptr=tmp;
        }
        head=NULL;
    }
    T get(int index){
        if(!head || index<0)
            throw std::out_of_range("Index out of bounds");
        int i=0;
        ListNode<T>* ptr=head;
        while(ptr){
            if(i==index)
                return ptr->val;
            ptr=ptr->next;
            i++;
        }
        throw std::out_of_range("Index out of bounds");
    }
    T set(int index, T element){
        if(!head || index<0)
            throw std::out_of_range("Index out of bounds");
        int i=0;
        ListNode<T>* ptr=head;
        while(ptr){
            if(i==index){
                T tmp=ptr->val;
                ptr->val=element;
                return tmp;
            }
            ptr=ptr->next;
            i++;
        }
        throw std::out_of_range("Index out of bounds");
    }
    int indexOf(T val){
        if(!head)
            return -1;
        int i=0;
        ListNode<T>* ptr=head;
        while(ptr){
            if(ptr->val==val){
                return i;
            }
            ptr=ptr->next;
            i++;
        }
        return -1;
    }
    int lastIndexOf(T val){
        int res=-1;
        int i=0;
        ListNode<T>* ptr=head;
        while(ptr){
            if(ptr->val==val)
                res=i;
            ptr=ptr->next;
            i++;
        }
        return res;
    }
    T peek(){
        return head->val;
    }
    T poll(){
        return removeAt(0);
    }
    void print(){
        ListNode<T>* ptr = head;
        while(ptr){
            ptr->print();
            ptr=ptr->next;
        }
        std::cout<<"NULL"<<std::endl;
    }
};