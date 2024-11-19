#include <iostream>
#include <string>

using namespace std;

class ChainLink {
private:
    string color;
public:
    ChainLink(string c) : color(c) {}
    string get_color() const { return color; }
};

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void append(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void prepend(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    T* view(int index) {
        Node<T>* current = head;
        int count = 0;
        while (current) {
            if (count == index) {
                return &(current->data);
            }
            current = current->next;
            count++;
        }
        return nullptr;
    }

    int size(int startIndex) {
        Node<T>* current = head;
        int count = 0;
        
        while (count < startIndex && current) {
            current = current->next;
            count++;
        }
        
        if (!current) return 0;
        
        int remainingSize = 1;
        while (current->next) {
            current = current->next;
            remainingSize++;
        }
        
        return remainingSize;
    }
};

int main() {
    LinkedList<ChainLink> colorList;
    colorList.append(ChainLink("Red"));
    colorList.prepend(ChainLink("Blue"));
    
    LinkedList<int> numberList;
    numberList.append(10);
    numberList.append(20);
    numberList.prepend(5);
    
    LinkedList<string> stringList;
    stringList.append("Hello");
    stringList.append("World");
    stringList.prepend("Hi");

    cout << "Color at index 0: " << colorList.view(0)->get_color() << endl;
    cout << "Number at index 0: " << *numberList.view(0) << endl;
    cout << "String at index 0: " << *stringList.view(0) << endl;

    return 0;
}
