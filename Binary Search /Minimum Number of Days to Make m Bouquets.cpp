class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // if we have less flowers than the required to make the bouquets, so it's impossible to make the bouquets
        if((long long)m*k > (long long)n) {
            return -1;
        }
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low < high) {
            int mid = low + (high-low) / 2;
            int count = 0;
            int total = 0;
            for(auto i:bloomDay) {
                if(i<=mid) {
                    count++;
                }
                else {
                    count = 0;
                }
                if(count==k) {
                    total++;
                    count = 0;
                }       
            }
            if(total >= m) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
// minimum days a flower can take is 1/0, you can take anything but take 1 as bloomDay[i]>=1
// maximum days can be the maximum days taken bu the flower to bloom
// in this range, I'll find the mid, basically mid represents the days it takes to bloom, so we'll find how many flowers can bloom within the mid, then see how many flowers are required to make a bouquet, k->flowers m->bouquets
// we have to find adjacent flowers, so if value of bloomDay[i]>mid, so make count = 0 or if you have find the k flowers, make the count = 0;
// detect how many bouquets you can make, if you can make more or equal to m, then maybe a more less day is there so high=mid, mid is the possible answer.
// if less bouquets are made, then maybe no. of days required to bloom is less, increase it.
// returning low coz we want the least day it requires.
