/// The classic n-queen problem
/// This solution is heavy based in backtracking, every step's just an evolution of its antecessor
pub struct Solution;

impl Solution {
    // if all diagonals're valid, just the last one can be invalid
    pub fn valid_last_diagonal(qs: &[i32]) -> bool {
        let q = qs.last().unwrap();
        qs.iter()
            .rev()
            .skip(1)
            .zip(1..)
            .all(|(&oq, i)| q - i != oq && q + i != oq)
    }

    // if all rows're valid, just the last one can be invalid
    pub fn last_valid_rows(qs: &[i32]) -> bool {
        let last_p = qs.last().unwrap();
        qs.iter().rev().skip(1).all(|q| q != last_p)
    }

    pub fn is_last_valid(qs: &[i32]) -> bool {
        Self::last_valid_rows(qs) && Self::valid_last_diagonal(qs)
    }

    // stack aproach
    pub fn nqueen(state: &mut Vec<i32>, n: i32, sets: &mut Vec<Vec<String>>) {
        for p in 0..n {
            state.push(p);
            if Self::is_last_valid(state) {
                if state.len() == n as usize {
                    sets.push(Self::into_table(state));
                } else {
                    Self::nqueen(state, n, sets);
                }
            }
            state.pop();
        }
    }

    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        let mut sets = Vec::new();
        Self::nqueen(&mut Vec::with_capacity(n as usize), n, &mut sets);
        sets
    }

    pub fn into_table(qs: &[i32]) -> Vec<String> {
        qs.iter()
            .copied()
            .map(|q| Self::into_row(q, qs.len() as i32))
            .collect()
    }

    pub fn into_row(q: i32, n: i32) -> String {
        let mut row = String::with_capacity(n as usize);
        (0..n).for_each(|i| row.push(if i == q { 'Q' } else { '.' }));
        row
    }
}
