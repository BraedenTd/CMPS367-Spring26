#include <iostream>
#include <string>
#include <sstream>
#include "unorderedArrayListType.h"
using namespace std;

// ================================================================
// Problem 2 — Template arrayListType / unorderedArrayListType Test
// ================================================================


// ---------------------------------------------------------------
// mirrors arrayListType for any type T
// ---------------------------------------------------------------
template <class T>
class arrayListTypeT
{
    template <class U>
    friend ostream& operator<<(ostream&, const arrayListTypeT<U>&);

public:
    bool isEmpty()    const { return length == 0; }
    bool isFull()     const { return length == maxSize; }
    int  listSize()   const { return length; }
    int  maxListSize()const { return maxSize; }

    void print() const
    {
        for (int i = 0; i < length; i++)
            cout << list[i] << " ";
        cout << endl;
    }

    void removeAt(int location)
    {
        if (location < 0 || location >= length)
            cout << "Location of item to be removed is out of range." << endl;
        else
        {
            for (int i = location; i < length - 1; i++)
                list[i] = list[i + 1];
            length--;
        }
    }

    void retrieveAt(int location, T& retItem) const
    {
        if (location < 0 || location >= length)
            cout << "Location out of range." << endl;
        else
            retItem = list[location];
    }

    void clearList() { length = 0; }

    virtual void insertAt(int location, T insertItem) = 0;
    virtual void insertEnd(T insertItem) = 0;
    virtual void replaceAt(int location, T repItem) = 0;
    virtual int  seqSearch(T searchItem) const = 0;
    virtual void remove(T removeItem) = 0;

    arrayListTypeT(int size = 100)
    {
        maxSize = (size > 0) ? size : 100;
        length = 0;
        list = new T[maxSize];
    }

    arrayListTypeT(const arrayListTypeT<T>& other)
    {
        maxSize = other.maxSize;
        length = other.length;
        list = new T[maxSize];
        for (int i = 0; i < length; i++)
            list[i] = other.list[i];
    }

    virtual ~arrayListTypeT() { delete[] list; }

protected:
    T* list;
    int length;
    int maxSize;
};

template <class U>
ostream& operator<<(ostream& out, const arrayListTypeT<U>& L)
{
    for (int i = 0; i < L.length; i++)
        out << L.list[i] << " ";
    return out;
}


// ---------------------------------------------------------------
// mirrors unorderedArrayListType for T
// ---------------------------------------------------------------
template <class T>
class unorderedArrayListTypeT : public arrayListTypeT<T>
{
public:
    void insertAt(int location, T insertItem)
    {
        if (location < 0 || location >= this->maxSize)
            cout << "Position out of range." << endl;
        else if (this->length >= this->maxSize)
            cout << "Cannot insert in a full list." << endl;
        else
        {
            for (int i = this->length; i > location; i--)
                this->list[i] = this->list[i - 1];
            this->list[location] = insertItem;
            this->length++;
        }
    }

    void insertEnd(T insertItem)
    {
        if (this->length >= this->maxSize)
            cout << "Cannot insert in a full list." << endl;
        else
        {
            this->list[this->length] = insertItem;
            this->length++;
        }
    }

    int seqSearch(T searchItem) const
    {
        int  loc = 0;
        bool found = false;
        while (loc < this->length && !found)
        {
            if (this->list[loc] == searchItem) found = true;
            else                               loc++;
        }
        return found ? loc : -1;
    }

    void remove(T removeItem)
    {
        if (this->length == 0)
            cout << "Cannot delete from an empty list." << endl;
        else
        {
            int loc = seqSearch(removeItem);
            if (loc != -1) this->removeAt(loc);
            else cout << "The item to be deleted is not in the list." << endl;
        }
    }

    void replaceAt(int location, T repItem)
    {
        if (location < 0 || location >= this->length)
            cout << "Location out of range." << endl;
        else
            this->list[location] = repItem;
    }

    // operator+ : concatenate two lists into a new one
    unorderedArrayListTypeT<T> operator+(
        const unorderedArrayListTypeT<T>& other) const
    {
        unorderedArrayListTypeT<T> result(this->length + other.length);
        for (int i = 0; i < this->length; i++)
            result.insertEnd(this->list[i]);
        for (int i = 0; i < other.length; i++)
            result.insertEnd(other.list[i]);
        return result;
    }

    unorderedArrayListTypeT(int size = 100) : arrayListTypeT<T>(size) {}
};



ostream& operator<<(ostream& out, const unorderedArrayListType& L)
{
    // retrieveAt is public; use it to read each element safely
    int item;
    for (int i = 0; i < L.listSize(); i++)
    {
        L.retrieveAt(i, item);
        out << item << " ";
    }
    return out;
}

unorderedArrayListType operator+(const unorderedArrayListType& a,
    const unorderedArrayListType& b)
{
    unorderedArrayListType result(a.listSize() + b.listSize());
    int item;
    for (int i = 0; i < a.listSize(); i++)
    {
        a.retrieveAt(i, item);
        result.insertEnd(item);
    }
    for (int i = 0; i < b.listSize(); i++)
    {
        b.retrieveAt(i, item);
        result.insertEnd(item);
    }
    return result;
}


// ---------------------------------------------------------------
// Test Program
// ---------------------------------------------------------------
int main()
{
    cout << "=== Template List Test ===" << endl;

    // --- Original int-only class with operator<< and operator+ ---
    cout << "\n-- Original unorderedArrayListType (int) with free operator<< and + --" << endl;
    unorderedArrayListType origA(5), origB(5);
    origA.insertEnd(1); origA.insertEnd(2); origA.insertEnd(3);
    origB.insertEnd(4); origB.insertEnd(5); origB.insertEnd(6);
    cout << "origA:         " << origA << endl;
    cout << "origB:         " << origB << endl;
    cout << "origA + origB: " << (origA + origB) << endl;

    // --- Template: Integer List ---
    cout << "\n-- Template Integer List --" << endl;
    unorderedArrayListTypeT<int> intList(10);
    intList.insertEnd(10);
    intList.insertEnd(30);
    intList.insertEnd(50);
    intList.insertEnd(70);
    intList.insertEnd(90);
    cout << "Initial:               " << intList;

    intList.insertAt(2, 99);
    cout << "After insertAt(2, 99): " << intList;

    intList.remove(30);
    cout << "After remove(30):      " << intList;

    int idx = intList.seqSearch(99);
    cout << "seqSearch(99) at index " << idx << endl;

    // --- Template: Character List ---
    cout << "\n-- Template Character List --" << endl;
    unorderedArrayListTypeT<char> charList(10);
    charList.insertEnd('A');
    charList.insertEnd('B');
    charList.insertEnd('C');
    charList.insertEnd('D');
    charList.insertEnd('E');
    cout << "Initial:               " << charList;

    charList.insertEnd('Z');
    cout << "After insertEnd('Z'):  " << charList;

    charList.remove('C');
    cout << "After remove('C'):     " << charList;

    int cidx = charList.seqSearch('Z');
    cout << "seqSearch('Z') at index " << cidx << endl;

    // --- Template: String List ---
    cout << "\n-- Template String List --" << endl;
    unorderedArrayListTypeT<string> strList(10);
    strList.insertEnd("Apple");
    strList.insertEnd("Banana");
    strList.insertEnd("Cherry");
    strList.insertEnd("Date");
    cout << "Initial:                       " << strList;

    strList.insertAt(1, "Blueberry");
    cout << "After insertAt(1, Blueberry):  " << strList;

    strList.remove("Date");
    cout << "After remove(Date):            " << strList;

    int sidx = strList.seqSearch("Cherry");
    cout << "seqSearch(\"Cherry\") at index " << sidx << endl;

    // --- Template: Concatenation with operator+ ---
    cout << "\n-- Template Concatenation with + (Integer Lists) --" << endl;
    unorderedArrayListTypeT<int> listA(5), listB(5);
    listA.insertEnd(1); listA.insertEnd(2); listA.insertEnd(3);
    listB.insertEnd(4); listB.insertEnd(5); listB.insertEnd(6);
    cout << "listA:         " << listA;
    cout << "listB:         " << listB;
    unorderedArrayListTypeT<int> listC = listA + listB;
    cout << "listA + listB: " << listC;

    // --- operator<< ---
    cout << "\n-- Output with << --" << endl;
    cout << "intList  via <<: " << intList << endl;
    cout << "charList via <<: " << charList << endl;
    cout << "strList  via <<: " << strList << endl;

    return 0;
}