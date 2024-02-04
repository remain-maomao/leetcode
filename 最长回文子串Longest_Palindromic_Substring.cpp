#include<iostream>
using namespace std;
/**
 * 查找并返回给定字符串中最长的奇数长度回文子串。
 *
 * 此函数利用中心扩展算法寻找最长的奇数长度回文子串。它逐个检查字符串中的每个字符，
 * 将每个字符作为潜在回文子串的中心，向两边扩展比较字符，以确定最长的回文子串。
 * 该方法仅适用于寻找奇数长度的回文子串。
 *
 * 注意：该函数当前不处理偶数长度的回文子串。如果存在多个最长的回文子串，
 * 函数将返回第一个找到的子串。
 *
 * @param s 输入字符串，函数将在这个字符串中查找最长的奇数长度回文子串。
 * @return 返回找到的最长奇数长度回文子串。如果输入字符串为空或不存在奇数长度的回文子串，则返回空字符串。
 */
string getLongestPalindromicString(string s) {
    int length = s.size();
    int maxI = 0; // 最长回文子串中心的索引
    int maxWing = 0; // 最长回文子串的“翼长”，即中心到边缘的长度
    for (int i = 0; i < length - 1; i++) {
        int wing = 0; // 当前中心的翼长
        while (i - wing >= 0 && i + wing <= length - 1) {
            if (s[i - wing] == s[i + wing]) {
                wing++;
            } else {
                break;
            }
        }
        wing--; // 循环结束时，wing会比实际翼长多1，需要减去
        if (wing > maxWing) {
            maxI = i;
            maxWing = wing;
        }
    }
    return s.substr(maxI - maxWing, 2 * maxWing + 1);
}
int main() {
    string s;
    cin >> s;
    cout << getLongestPalindromicString(s);
}
