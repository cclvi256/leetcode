impl Solution {
    pub fn average(salary: Vec<i32>) -> f64 {
        let mut first = true;
        let count = salary.len() as f64;
        let mut min = 0;
        let mut max = 0;
        let mut sum = 0;

        for i in salary {
            sum += i;

            if first {
                min = i;
                max = i;
                first = false;
            } else {
                if i < min {
                    min = i;
                    continue;
                } 
                
                if i > max {
                    max = i;
                    continue;
                }
            }
        }

        ((sum - min - max) as f64) / (count - 2.0)
    }
}

