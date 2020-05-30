/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 



以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

 



图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

 

示例:

输入: [2,1,5,6,2,3]
输出: 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stack>
#include <vector>
using namespace std;

class Solution
{
private:
    void getRes(stack<int> &s, const vector<int> &heights, int i, int height, int &res)
    {
        while (!s.empty() && heights[s.top()] > height)
        {
            int index = s.top();
            s.pop();
            res = max(res, (s.empty() ? i : (i - s.top() - 1)) * heights[index]);
        }
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {

        int res = 0;
        int size = heights.size();
        stack<int> s;

        for (int i = 0; i < size; i++)
        {
            getRes(s, heights, i, heights[i], res);
            s.push(i);
        }

        getRes(s, heights, size, 0, res);
        return res;
    }
};