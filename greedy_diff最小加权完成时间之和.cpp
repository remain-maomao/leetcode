#include <iostream>
#include <algorithm> // 包含算法库，用于访问sort函数
using namespace std;
// 定义一个结构体表示任务，包含两个整型成员：l（任务长度）和w（任务权重）
struct task {
    int l; // 任务长度
    int w; // 任务权重
};
/**
 * 比较函数，用于决定两个任务在差值优先策略下的排序顺序。
 * 此函数用于std::sort算法，以确定任务按权重减去长度的差值降序排列。
 *
 * @param a 第一个任务的引用。
 * @param b 第二个任务的引用。
 *
 * @return 如果a的权重和长度的差值大于b的对应差值，则返回true；否则返回false。
 * */
bool compareDiff(const task& a, const task& b) {
    return (a.w-a.l) > (b.w-b.l);
}
/**
 * 比较函数，用于决定两个任务在比率优先策略下的排序顺序。
 * 此函数用于std::sort算法，以确定任务按权重与长度比率降序排列。
 *
 * @param a 第一个任务的引用。
 * @param b 第二个任务的引用。
 *
 * @return 如果a的权重与长度的比率大于b的对应比率，则返回true；否则返回false。
 * */
bool compareRatio(const task& a, const task& b) {
    return (1.0 * a.w / a.l) > (1.0 * b.w / b.l);
}
/**
 * 使用差值优先策略的贪心算法计算任务序列的最小加权完成时间之和。
 * 此函数首先根据每个任务的权重和长度的差值对任务进行排序，
 * 然后按排序结果计算加权完成时间之和。
 *
 * @param schedule 任务数组，包含n个任务。
 * @param n 任务数组中的任务数量。
 *
 * @return 给定任务序列的最小加权完成时间之和。
 * */
int greedyDiff(task schedule[], int n) {
    // 使用std::sort对任务数组进行排序，排序依据是compareDiff函数
    sort(schedule, schedule + n, compareDiff);
    int finishedTime = 0; // 完成时间，初始为0
    int weightedSum = 0; // 加权完成时间之和，初始为0
    for (int i= 0; i < n; i++) {
        finishedTime += schedule[i].l; // 更新完成时间
        weightedSum += finishedTime * schedule[i].w; // 更新加权完成时间之和
    }
    return weightedSum; // 返回加权完成时间之和
}
/**
 * 使用比率优先策略的贪心算法计算任务序列的最小加权完成时间之和。
 * 此函数首先根据每个任务的权重和长度的比值对任务进行排序，
 * 然后按排序结果计算加权完成时间之和。
 *
 * @param schedule 任务数组，包含n个任务。
 * @param n 任务数组中的任务数量。
 *
 * @return 给定任务序列的最小加权完成时间之和。
 * */
int greedyRatio(task schedule[], int n) {
    // 使用std::sort对任务数组进行排序，排序依据是compareRatio函数
    sort(schedule, schedule + n, compareRatio);
    int finishedTime = 0; // 完成时间，初始为0
    int weightedSum = 0; // 加权完成时间之和，初始为0
    for (int i= 0; i < n; i++) {
        finishedTime += schedule[i].l; // 更新完成时间
        weightedSum += finishedTime * schedule[i].w; // 更新加权完成时间之和
    }
    return weightedSum; // 返回加权完成时间之和
}
/*
 * 输入：一组n个作业，它们具有正的长度l1, l2, l3, ……, ln,
 * 和正的权重w1, w2, w3, ……, wn
 * 输出：一个作业序列，它具有最小的加权完成时间之和
 * */
int main() {
   int n; // 作业数量
   cin >> n;
   task schedule[100];
    // 循环读取每个作业的长度和权重
   for (int i = 0; i < n; i++) {
       cin >> schedule[i].l >> schedule[i].w;
   }
    // 计算并输出最小的加权完成时间之和
   cout << greedyRatio(schedule, n);
   return 0;
}
