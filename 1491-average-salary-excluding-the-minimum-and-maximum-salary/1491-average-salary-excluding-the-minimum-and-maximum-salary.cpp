class Solution {
public:
    double average(vector<int>& salary) {
        int s=salary.size();
        double sum=0,ma=DBL_MIN,mi=DBL_MAX;
        for(int i=0;i<s;i++)
            sum+=salary[i];
        ma=*max_element(salary.begin(),salary.end());
        mi=*min_element(salary.begin(),salary.end());
        return (sum-ma-mi)/(s-2);
    }
};