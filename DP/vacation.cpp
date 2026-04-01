//find the maximum happiness points that can be achieved in n days by doing one of three activities each day, with the constraint that the same activity cannot be done on consecutive days.
#include<bits/stdc++.h>
using namespace std;
int points[100005][3];
int dp[100005][3];
int solve(int day, int activity) {
    if(day==0) return points[0][activity];
    if(dp[day][activity]!=-1) return dp[day][activity];
    int maxPoints = 0;
    for(int i=0;i<3;i++) {
        if(i!=activity) {
            maxPoints = max(maxPoints, solve(day-1, i)+points[day][activity]);
        }
    }
    return dp[day][activity] = maxPoints;
}
int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cout<<"Enter the number of days: ";
    cin>>n;
    cout<<"Enter the points for each activity on each day:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin>>points[i][j];
        }
    }
    int maxHappiness = 0;
    for(int i=0;i<3;i++) {
        maxHappiness = max(maxHappiness, solve(n-1, i));
    }
    cout<<"Maximum happiness points: "<<maxHappiness<<endl;
    return 0;
}
