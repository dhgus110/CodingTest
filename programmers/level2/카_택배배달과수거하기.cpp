#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int deliveryPoint, pickPoint; //맨 뒤에 배달&수거 할 위치

int delivery(vector<int>& deliveries, int cap) {
    int last=-1;
    bool check = false;

    for (int i = deliveryPoint; i >= -1; i--) {
        if (i == -1) {
            deliveryPoint = i;
            break;
        }
        if (deliveries[i] > 0) {
            if (!check) {
                last = i; check = true;
            }
            if (deliveries[i] > cap) {
                deliveries[i] -= cap;
                deliveryPoint = i;
                break;
            }
            else if(deliveries[i] < cap) {
                cap -= deliveries[i];
            }
            else if (deliveries[i] == cap) {
                deliveryPoint = i - 1;
                break;
            }
        }
    }
    return last;
}

int pickup(vector<int>& pickups, int cap) {
    int last=-1;
    bool check = false;
    for (int i = pickPoint; i >= -1; i--) {
        if (i == -1) {
            pickPoint = i;
            break;
        }
        if (pickups[i] > 0) {
            if (!check) {
                last = i; check = true;
            }
            if (pickups[i] > cap) {
                pickups[i] -= cap;
                pickPoint = i;
                break;
            }
            else if (pickups[i] < cap) {
                cap -= pickups[i];
            }
            else if (pickups[i] == cap) {
                pickPoint = i - 1;
                break;
            }
        }
    }
    return last;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    bool dCheck = false, pCheck = false;
    //init
    for (int i = n - 1; i >= 0; i--) {
        if (deliveries[i] > 0) {
            deliveryPoint = i;
            dCheck = true;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (pickups[i] > 0) {
            pickPoint = i;
            pCheck = true;
            break;
        }
    }
    if (!dCheck && !pCheck)return 0;
  
    while (true)
    {
        if (deliveryPoint == -1 && pickPoint == -1) break;
        int d = delivery(deliveries, cap) + 1;
        int p = pickup(pickups, cap) + 1;
        int move = d > p ? d : p;
        cout << move << " " << d << " " << p << endl;
        answer += 2 * move;
    }

    return answer;
}