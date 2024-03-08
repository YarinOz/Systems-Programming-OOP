/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;

template <class T>
class Array;

template <class T>
ostream& operator<<(ostream& os, const Array<T>& arr);

template <class T>
class Array
{
   private:
      int size;
      T* arr;  
      
   public:
      Array():size(0), arr(nullptr){}
      ~Array(){}
      void add(const T& element); 
      T remove(const int index);
      int getSize() const;
      void print(ostream& os) const;

      // operator overloading
      friend ostream& operator<< <> (ostream& os, const Array<T>& other);
      const T& operator[](const int index) const;
};


template <class T>
const T& Array<T>::operator[](const int index) const {
    return arr[index];
}

template <class T>
ostream& operator<<(ostream& os, const Array<T>& other) {
   other.print(os);
   return os;
}

template <class T>
void Array<T>::print(ostream& os) const
{
   if (getSize() == 0)
   {
      os << "The array is empty" << endl;
      return;
   }
   for (int i = 0; i < getSize(); i++)
   {
      os << i + 1 << ". " << arr[i] << endl;
   }
}

template <class T>
int Array<T>::getSize() const {
    return size;
}

template <class T>
void Array<T>::add(const T& element) {
    T* tempArr = new T[size + 1]; // temp array with size + 1
    for (int i = 0; i < size; i++) { // deep copy
        tempArr[i] = arr[i];
    }
    tempArr[size] = element; // add the new element
    delete[] arr;  // delete temp array
    arr = tempArr;
    size++;
}

template <class T>
T Array<T>::remove(const int index) {
    if (index < 0 || index >= size) { // index error check
        throw "Index out of bounds";
    }
    T* tempArr = new T[size - 1]; // temp array with size - 1
    T removed = arr[index]; // save the removed element
    for (int i = 0; i < size; i++) {
        if (i < index) {
            tempArr[i] = arr[i];
        } else if (i > index) {
            tempArr[i - 1] = arr[i];
        }
    }
    delete[] arr; // delete temp array
    arr = tempArr;
    size--;
    return removed;
}

#endif // ARRAY_H