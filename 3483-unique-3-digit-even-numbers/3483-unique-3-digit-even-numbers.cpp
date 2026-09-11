class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans=0;
        int n =digits.size();
        set<int> st;
        for(int i=0; i<n; i++){
            if(digits[i] ==0 )continue;
            int num = digits[i];

            for(int j =0; j<n ; j++){
                if(i == j ) continue;

                num = num* 10 + digits[j];
                for(int k =0; k<n ; k++){

                    if (i==k || j == k|| digits[k] % 2 !=0) continue;
                    int num1 = num;
                    num = num*10 + digits[k];
                    if(num >= 100 && num %2 ==0) st.insert(num);
                    num = num1;
                }
                num = num/10;
            }
        }

        return st.size();
        

    }
};