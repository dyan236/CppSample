template <typename T>
class ListNode{
public:
    ListNode* next;
    ListNode* prev;
    T val;
    ListNode(T val):
        val(val)
    {}
    void print(){
        std::cout<<"ListNode("<<val<<")->";
    }
};