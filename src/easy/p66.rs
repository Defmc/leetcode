pub struct Solution;

impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        for d in digits.iter_mut().rev() {
            *d += 1;
            if *d > 9 {
                *d = 0;
            } else {
                return digits;
            }
        }
        digits.insert(0, 1);
        digits
    }
}
