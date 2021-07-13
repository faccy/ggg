#include <iostream> 
#include "sharedptr.h"
#include <vector>
using namespace std;


int main() {
    string* str = new string("HelloWorld");
    string* str2 = new string("HelloProgramer");
    sharedPtr<string> sp(str);
    sharedPtr<string> ap(str2);
    cout << *sp << endl;
    cout << sp.isEmpty() << endl;
    string* str3 = sp.get();
    cout << *str3 << endl;
    cout << "sp:" << sp.use_count() << endl;
    cout << "ap:" << ap.use_count() << endl;
    sharedPtr<string> sp2(sp);
    cout << "sp:" << sp.use_count() << endl;
    cout << "sp2:" << sp2.use_count() << endl;
    cout << "ap:" << ap.use_count() << endl;
    sp = ap;
    cout << "sp:" << sp.use_count() << endl;
    cout << "sp2:" << sp2.use_count() << endl;
    cout << "ap:" << ap.use_count() << endl;

    return 0;
}