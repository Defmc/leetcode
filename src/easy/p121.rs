/// I really liked this challenge. It uses something called Kadane's algorithm (maximum sub-array
/// problem)
/// we have some rules here:
/// - We want the max profit possible (i.e a[j] - a[i] > any other combination)
/// - The sell day should be after the buy day (i.e j > i)
/// It's everything we need
pub struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let (mut min_d, mut max_d) = (0, 0);
        let mut max_prof = 0;
        for i in 0..prices.len() {
            if prices[i] < prices[min_d] {
                // a new day to buy
                min_d = i;
                max_d = i; // we can only sell after we buy it
            }
            if prices[i] > prices[max_d] {
                max_d = i;
                let diff = prices[max_d] - prices[min_d];
                if diff > max_prof {
                    // would we do more profit selling today?
                    max_prof = diff;
                }
            }
        }
        max_prof
    }
}
