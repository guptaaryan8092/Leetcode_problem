#include <iostream>
using namespace std;

void palindrome(int num) {
    int original = num;
    int rev = 0;
    while (num > 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num = num / 10 ;
    }
    if (original == rev) {
        cout << "Palindrome Number" << endl;
    } else {
        cout << "Not a Palindrome Number" << endl;
    }
}

int main(){
    int num;
    cout <<"Enter a number: ";
    cin >> num;

    palindrome(num);
    return 0;
}