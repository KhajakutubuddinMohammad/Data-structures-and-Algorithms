vector<int> Solution::maxset(vector<int> &A) {

    vector<int> ret;
    int end1=0,start1=0,start,end,sum=INT_MIN,count=0,temp1,temp2;
    for(int i=0;i<A.size();i++)
    {
        count+=A[i];
        cout<<count<<endl;
        if(A[i] < 0)
        {
            count=0;
            start1=i+1;
            end1=i+1;
        }
        if(sum < count)
        {
            sum=count;
            start=start1;
            end=i;
        }
        if(sum == count)
        {
            temp1=start-end;
            temp2=start1-end1;
            if(temp1 < temp2)
            {
                start=start1;
                end=end1;
            }
        }
    }
    cout<<start<<" "<<end<<endl;
    for(int i=start;i<=end;i++)
    {
         ret.push_back(A[i]);
    }
    return ret;
}
