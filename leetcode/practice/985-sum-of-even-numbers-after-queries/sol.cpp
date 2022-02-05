#include<bits/stdc++.h>
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) 
    {
        int sum=0;
        // Stores the sum of all even values in variable "sum".
        for(int i=0; i<A.size(); i++)
        {
            if(A[i]%2==0)sum+=A[i];
        }
        // cout<<sum<<endl;
        
        vector<int>answer;
        /*DEBUGGING
        for(int i=0; i<answer.size(); i++)
        {
            cout<<answer[i]<<endl;
        }
        */
        /* DEBUGGING-->
        for(int i=0; i<queries.size(); i++)
        {
            cout<<queries[i][0]<<" "<<queries[i][1]<<endl;
        }
        */
        
        int val,index,original;
        
        for(int i=0; i<queries.size(); i++)
        {
            val=queries[i][0];
            index=queries[i][1];
            original=A[index];
            A[index]+=val;
            
            // If the value is even and the original value
            // was also even then add "val" to sum else do nothing.
            if(val%2==0)
            {
                if(original%2==0)sum+=val;
            }
            
            // If the value is odd then two case arises-->
            else
            {
                // 1.-->if original value is odd then result is even
                // so the sum is sum+original+val.
                if(original%2!=0)sum+=original+val;
                // 2,-->If original value is even then result is odd
                // so the sum will be sum-original.
                else sum-=original;
            }
            answer.push_back(sum);
        }
        
        
        return answer;
    }
};
