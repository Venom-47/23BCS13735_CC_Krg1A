#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef long long ll;


int main()
{
    
    int n;
    cin >> n;

    vector<string> words(n);

    for(int i = 0; i < n; i++){
        cin >> words[i];
    }

    
    vector<int> mask(n);
    
    for(int i = 0; i < n; i++){
        
        int bit_mask = 0;
        
        for(int j = 0; j < words[i].size(); j++){
            bit_mask = bit_mask | (1 << (words[i][j] - 'a'));
        }
        mask[i] = bit_mask;
    }

    int full_and = (1 << 26)-1;

    for(int i = 0; i < n; i++){
        full_and = full_and & mask[i];
    }

    int ans = 0;

    if(full_and == 0){

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if((mask[i]&mask[j]) == 0){
                    int length = words[i].length()*words[j].length();
                    ans = max(ans,length);
                }
            }
        }
    }

    cout << ans << endl;    

    return 0;
}
