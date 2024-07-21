class Solution {
public:
    int canEat(vector<int>& piles, int mid) {
        int hours = 0;
        for(int i=0; i<piles.size(); i++) {
            hours += ceil(piles[i] / (double)mid);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high) {
            int mid = low + (high-low) / 2;
            int possibleAns = canEat(piles, mid);
            if(possibleAns <= h) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};
// possible bananas koko can eat is [1, max pile]
// now we have to find the optimal solution in this range, as in what's the minimum number of banana koko can eat at once
// we calculate mid, now koko can eat mid bananas in a hour, for eg mid is 6, so the pile in which 7 bananas are there, koko will eat only 6 in 1 hour and rest 1 in another hour as it is said that if no. of bananas are less than the capacity, then she will eat and rest for that hour.
// so we calculate the total number of hours to eat all bananas, if it is less than the given hours, means it is a valid answer, but we need to find whether a more less ans exist or not, if koko eat less bananas, can she complete all of them within the time.
// so that's why we made the high toh mid, now we'll check in the range of low-mid
// at last either of low and high will give us the answer, you can return any

// ceil because it returns the smallest greatest number close to the number and typecast to double in order to find the decimal value. eg 10 bananas in 3 hours, so 10/3 = 3 but we requires 4, 3 hours for the first 9 and 1 for the left 1, that's why double in order to get 3.33 and ceil of 3.33 is 4 