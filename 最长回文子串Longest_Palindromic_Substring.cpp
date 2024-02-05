#include<iostream>
using namespace std;
/**
 * 查找并返回给定字符串中最长的回文子串。
 *
 * 该函数使用中心扩展法查找最长的回文子串，分别处理奇数长度和偶数长度的情况。
 * 对于奇数长度的子串，选择一个字符作为中心，向两边扩展；
 * 对于偶数长度的子串，选择相邻的两个字符作为中心，向两边扩展。
 * 函数比较这两种情况下找到的最长回文子串的长度，并返回最长的那个。
 *
 * 注意：如果存在多个长度相同的最长回文子串，函数将返回在字符串中首次找到的子串。
 *
 * @param s 输入字符串，函数将在这个字符串中查找最长的回文子串。
 * @return 返回找到的最长回文子串。如果输入字符串为空，或不存在回文子串，则返回空字符串。
 */
string getLongestPalindromicString(string s) {
    int length = s.size();
    int maxI = 0; // 最长回文子串中心的索引
    int maxWing = 0; // 最长回文子串的“翼长”，即中心到边缘的长度
    for (int i = 0; i < length; i++) {
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
    string longestOddPalindromicSubstr = s.substr(maxI - maxWing, 2 * maxWing + 1);

    // 查找最长的偶数长度回文子串
    maxI = maxWing = 0;
    for (int i = 0; i < length - 1; i++) {
        int wing = 0; // 当前中心的翼长
        int LCenter = i;
        int RCenter = i + 1;
        while (LCenter - wing >= 0 && RCenter + wing <= length - 1) {
            if (s[LCenter - wing] == s[RCenter + wing]) {
                wing++;
            } else {
                break;
            }
        }
        if (wing > maxWing) {
            maxI = LCenter;
            maxWing = wing;
        }
    }
    string longestEvenPalindromicSubstr = s.substr(maxI-maxWing+1, 2* maxWing);

    // 比较奇数长度和偶数长度回文子串的长度，返回最长的那个
    return longestEvenPalindromicSubstr.size() >
            longestOddPalindromicSubstr.size() ?
            longestEvenPalindromicSubstr : longestOddPalindromicSubstr;
}
int main() {
    string s;
    cin >> s;
    cout << getLongestPalindromicString(s);
}
