class Solution {
public:
    vector<int> v={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sol(string s){
        int m=stoi(s.substr(0,2));
        int d=stoi(s.substr(3,2));
        for(int i=0;i<m-1;i++)
            d+=v[i];
        return d;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int f=max(sol(arriveAlice),sol(arriveBob));
        int s=min(sol(leaveAlice),sol(leaveBob));
        return max(s-f+1,0);
    }
};