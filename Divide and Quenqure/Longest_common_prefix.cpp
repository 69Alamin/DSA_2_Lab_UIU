#include <bits/stdc++.h>
using namespace std;

string common(string left,string right){
    int min_n=min(left.size(),right.size());
    string result="";
    for(int i=0;i<min_n;i++){
        
            if(left[i]==right[i])
              result+=left[i];
              else break;
        
    }
    return result;
}

string longestCommonPrefix(vector<string>arr,int low,int high){
    if(low==high)
        return arr[low];
        else{
            int mid=(low+high)/2;
            string st1=longestCommonPrefix(arr,low,mid);
            string st2=longestCommonPrefix(arr,mid+1,high);

            return common(st1,st2);
        }
}

int main() {
    
   
    int N;
    cout << "Enter the number of strings: ";
    cin >> N;

    vector<string> arr(N);
    cout << "Enter the strings:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    string result = longestCommonPrefix(arr, 0, N - 1);

    if (result.empty())
        cout << "No common prefix found." << endl;
    else
        cout << "Longest Common Prefix: " << result << endl;
    return 0;
}