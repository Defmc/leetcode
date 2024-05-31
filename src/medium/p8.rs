pub struct Solution;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let (mut n, mut sign) = (0u64, 1);
        let mut digits_count = 0;
        for c in s.chars().skip_while(|&c| c.is_whitespace()) {
            if digits_count == 0 {
                if c == '-' {
                    sign = -1;
                    digits_count += 1;
                    continue;
                } else if c == '+' {
                    sign = 1;
                    digits_count += 1;
                    continue;
                }
            }
            if let Some(d) = c.to_digit(10) {
                n = n * 10 + d as u64;
                digits_count += 1;
            } else {
                break;
            }
            if n > i32::MAX as u64 && sign == 1 {
                return i32::MAX;
            } else if -(n as i64) > i32::MIN as i64 && sign == -1 {
                return i32::MIN;
            }
        }
        n as i32 * sign
    }
}
