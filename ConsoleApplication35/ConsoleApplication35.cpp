#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Array
{
private:
    int* arr;
    int size;
public:
    Array()
    {
        this->arr = nullptr;
        this->size = 0;
    }
    Array(int SIZE) {
        size = SIZE;
        this->arr = new int[size];
    }
    Array(const Array& obj) {
        size = obj.size;
        this->arr = new int[size];
        for (int i = 0; i < size; i++) {
            this->arr[i] = obj.arr[i];
        }
    }

    ~Array() {
        delete[] arr;
    }

    void Init(int SIZE, int min, int max) {
        size = SIZE;
        this->arr = new int[size];
        for (int i = 0; i < size; i++) {
            this->arr[i] = rand() % (max - min) + min;
        }
    }

    void Init2(int min, int max) {
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = rand() % (max - min) + min;
        }
    }

    void PrintArray() {
        for (int i = 0; i < this->size; i++) {
            std::cout << this->arr[i] << "  ";
        }
        std::cout << std::endl;
    }

};


class String
{
private:
    char* user_str;
    int length;
public:
    String() {
        user_str = new char[1];
        user_str[0] = '\0';
    }

    String(char* str) {
        length = strlen(str) + 1;
        user_str = new char[length];
        strcpy(user_str, str);
    }

    String(const String& str) {
        int length = strlen(str.user_str) + 1;
        user_str = new char[length];
        strcpy(user_str, str.user_str);
    }


    bool CheckStr(const String& obj) {
        return strcmp(user_str, obj.user_str) == 0;
    }

    int ReturnLenght() {
        length = strlen(user_str);
        return length;
    }

    ~String() {
        delete[] user_str;
    }

    void Print() {
        std::cout << user_str << std::endl;
    }
};



int main()
{
    //Task 1

    int* arr = new int[4];
    Array arr1(5);
    arr1.Init(10, 10, 20);
    arr1.PrintArray();
    std::cout << std::endl;
    Array arr2 = arr1;
    arr2.PrintArray();

    // Task 2

    char name1[] = "Dmytro";
    char name2[] = "Dmytro";
    String str1(name1);
    String str2(name2);
    str1.Print();
    std::cout << str1.ReturnLenght() << std::endl;
    std::cout << str1.CheckStr(str2);
}





	