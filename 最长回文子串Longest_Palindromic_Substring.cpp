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
/**
 * 打印给定字符串的所有可能子串。
 * 
 * 此函数遍历字符串的所有可能子串长度，从1到字符串的总长度。
 * 对于每个可能的子串长度，函数计算所有可能的起始位置，并打印从该位置开始的特定长度的子串。
 * 通过嵌套循环实现，外层循环控制子串的长度，内层循环控制子串的起始位置。
 * 
 * @param s 输入字符串，函数将展示这个字符串的所有子串。
 */
void showSubString(string s) {
    int length = s.size();
    for (int subLen = 1; subLen <= length; subLen++) {
        for (int start = 0; start + subLen - 1 <= length - 1; start++) {
            string substring = s.substr(start, subLen);
            cout << substring << endl;
        }
    }
}
int main() {
    string s;
    cin >> s;
    showSubString(s);
}
