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
 * 查找并返回给定字符串中最长的回文子串。
 * 
 * 此函数通过检查输入字符串的所有可能子串来找到最长的回文子串。
 * 它遍历所有子串，使用`isPalindromic`函数检查每个子串是否为回文。
 * 如果找到一个更长的回文子串，函数会更新最长回文子串的长度和起始位置。
 * 在遍历完成后，函数返回最长的回文子串。
 * 
 * 注意：如果存在长度相同的多个最长回文子串，函数将返回第一个找到的子串。
 * 
 * @param s 输入字符串，函数将在这个字符串中查找最长的回文子串。
 * @return 返回找到的最长回文子串。如果输入字符串为空或不存在回文子串，则返回空字符串。
 */
string getLongestPalindromicString(string s) {
    int length = s.size();
    int maxLen = INT_MIN;
    int maxStart = 0;
    for (int subLen = 1; subLen <= length; subLen++) {
        for (int start = 0; start + subLen - 1 <= length - 1; start++) {
            string substring = s.substr(start, subLen);
            if (isPalindromic(substring) && subLen > maxLen) {
                maxLen = subLen;
                maxStart = start;
            }
        }
    }
    return s.substr(maxStart, maxLen);
}
int main() {
    string s;
    cin >> s;
    cout << getLongestPalindromicString(s);
}
