#include<iostream>
using namespace std;
/**
 * 检查给定字符串是否为回文串。
 * 
 * 回文串是指正读和反读都一样的字符串。本函数通过比较字符串的前半部分和反向的后半部分来判断字符串是否为回文。
 * 
 * @param s 待检查的字符串。
 * @return 如果字符串是回文串，则返回true；否则返回false。
 */
bool isPalindromic(string s) {
    int length = s.size();
    for (int i = 0; i < length / 2; i++) {
        if (s[i] != s[length - 1 - i]) {
            return false;
        }
    }
    return true;
}
int main() {
    string s;
    cin >> s;
    cout << isPalindromic(s);
}
