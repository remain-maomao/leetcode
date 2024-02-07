#include <iostream>
#include <algorithm> // 包含算法库，用于访问sort函数
using namespace std;
// 定义一个结构体表示任务，包含两个整型成员：l（任务长度）和w（任务权重）
struct task {
    int l; // 任务长度
    int w; // 任务权重
};
// 比较函数，用于确定两个任务在排序中的先后顺序
// 根据权重与长度的差值进行比较，差值较大的任务应该更早执行
bool compareTask(const task& a, const task& b) {
    return (a.w-a.l) > (b.w-b.l);
}
// 贪心算法函数，用于计算任务序列的最小加权完成时间之和
// 参数schedule是一个任务数组，n是任务的数量
int greedyDiff(task schedule[], int n) {
    // 使用std::sort对任务数组进行排序，排序依据是compareTask函数
    sort(schedule, schedule + n, compareTask);
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
   cout << greedyDiff(schedule, n);
   return 0;
}
