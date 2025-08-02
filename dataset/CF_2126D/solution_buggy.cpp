#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <deque>
#include <iterator>
#include <initializer_list>
#include <climits>
#include <functional>
#include <stack>
#include <cctype>
#include <cstdint>
#include <utility>
#include <numeric>
#include <ranges> 
#define int long long
#define here std::cout << "here" << std::endl;

void print(int n){
    std::cout << n << std::endl;
}

void print(std::vector<int> &a){
    for (auto i : a){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void print(std::vector<std::vector<int>> &m){
    for (auto i : m){
        for (auto j : i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

}

int gcd(int a, int b){
    while (b != 0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

bool compare(std::vector<int> &a, std::vector<int> &b){
    if (a.at(2) <= b.at(2)){
        return true;
    }
    else {
        return false;
    }
}

int solution(std::vector<std::vector<int>> &a, int k){
    std::sort(a.begin(), a.end(), compare);
    for (auto i : a){
        if (k >= i.at(2)){
            continue;
        }
        else if (k >= i.at(0) && k <= i.at(1)){
            k = i.at(2);
        }
    }
    return k;
}

int32_t main(){
    int times = 1;
    std::cin >> times;
    while (times--){
        int n, k;
        std::cin >> n >> k;
        std::vector<std::vector<int>> a(n, std::vector<int> (3));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 3; j++){
                std::cin >> a.at(i).at(j);
            }
        }
        
        
        int answer = solution(a, k);
        std::cout << answer << std::endl;
    }
    return 0;
}