#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num)
{
    if (num == 0 || num == 1)
        return false;
    for (int i = 2; i < num / 2; i++)
        if (num % i == 0)
            return false;
    return true;
}

int solution(vector<int> nums)
{
    int answer = 0;
    for (int z = 0; z < nums.size(); z++)
    {
        for (int x = z + 1; x < nums.size() ; x++)
        {
            for (int c = x + 1; c < nums.size() ; c++)
            {
                int sum = nums[z] + nums[x] + nums[c];
                if (isPrime(sum))
                    answer++;
            }
        }
    }
    return answer;
}
 //dsa