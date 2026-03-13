#include<iostream>
#include<vector>
using namespace std;
int singleNum(vector<int>& nums) {
        int result = 0;

        for(int i = 0; i < 32; i++) {
            int sum = 0;

            for(int num : nums) {
                if((num >> i) & 1) {
                    sum++;
                }
            }

            if(sum % 3) {
                result |= (1 << i);
            }
        }

        return result;
    }
int main(){
  vector<int> v;
  v.push_back(2);
  v.push_back(2);
  v.push_back(3);
  v.push_back(2);

  cout<<"single element is : "<<(singleNum(v));
}



