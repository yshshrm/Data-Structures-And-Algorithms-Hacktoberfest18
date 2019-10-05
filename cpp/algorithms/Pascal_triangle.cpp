class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        if(numRows==0)
            return a;
        vector <int> t;
        t.push_back(1);
        a.push_back(t);
        if(numRows==1)
            return a;
        vector<int> tt;
        tt.push_back(1);
        tt.push_back(1);
        a.push_back(tt);
        if(numRows==2)
            return a;
        
        //For n=3 onwards
        for(int i=2;i<numRows;i++)
        {
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<i;j++)
            {
                //cout<<"valus of i and j is "<<i<<j<<endl;
                 //cout<<a[i-1][j-1]<<endl;
                 temp.push_back(a[i-1][j-1]+a[i-1][j]);
            }
             temp.push_back(1);  
            a.push_back(temp);
        }
        return a;
    }
};
