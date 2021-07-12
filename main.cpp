#include <iostream> 
#include "KsoStrin.h"
using namespace std;

int main() {
    char str[] = "helloworld";
    KsoString<char>* str3 = new KsoString<char>(str, 10);
    KsoString<char>* str2 = new KsoString<char>(*str3);
    delete str3;
    KsoString<char> str1 = *str2;
    delete str2;
    str1.PrintAll();
    str1.insert(',', 5);
    str1.PrintAll();
    str1.deleteChar(5);
    str1.PrintAll();
    str1.pushBack('!');
    str1.PrintAll();
    auto it = str1.findElement('o');
    cout << *it << endl;
    str1.modifyElement(0, 'H');
    str1.PrintAll();
    for (int i = 0; i < str1.elementsNum(); ++i) {
        cout << str1[i] << endl;
    }
    cout << str1[str1.elementsNum()] << endl;
    return 0;
}