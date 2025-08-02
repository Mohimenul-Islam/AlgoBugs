#include <bits/stdc++.h>
using namespace std;

int calGcd(int num1 , int num2){
    
    while(num2 != 0 ){
      int temp = num2;
      num2 = num1 % num2;
      num1 = temp;
    }
    return num1;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> prefixGcd(n,0);
        vector<int> suffixGcd(n,0);

        for(int i = 0 ; i < n ; i++){
             cin>> prefixGcd[i];
        }

        for(int i = 0 ; i < n ; i++){
             cin>> suffixGcd[i];
        }

          vector<int>arr(n);

          for(int i = 0 ; i < n  ; i++){
                arr[i] = lcm(prefixGcd[i],suffixGcd[i]);
          }
        
          bool possible = true;
          int lastgcd = 0 ;

          for(int i = 0; i < n ; i++ ){
                lastgcd = calGcd(lastgcd,arr[i]);
                if(prefixGcd[i] !=  lastgcd){
                    possible = false;
                      break;
                }
               
          }
          if(possible){
            lastgcd = 0 ;
            for(int i = n-1; i >= 0  ; i-- ){
               
                lastgcd = calGcd(lastgcd,arr[i]);
                if(suffixGcd[i] != lastgcd){
                    possible = false;
                    break;
                }
               
          }
               
          }
          
          cout<<(possible ? "YES\n" : "NO\n");
        

    }
    return 0;
}


