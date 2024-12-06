use std::{
    fs::File,
    io::{BufRead, BufReader},
};

fn main() {
    let file = File::open("input.txt").expect("Couldnt open file");
    let lines = BufReader::new(file).lines().map(|l| l.unwrap());

    let mut counter_safe = 0;
    for line in lines {
        let mut nums = line
            .split_whitespace()
            .map(|num| num.parse::<i32>().unwrap());

        let tolerance = true;

        let first = nums.next().unwrap();
        let second = nums.next().unwrap();

        let diff = (first - second).abs();
        if !(diff <= 3 && diff > 0) {
            continue;
        }

        let decending_order = first > second;
        counter_safe += 1;

        let mut last_seen = second;
        while let Some(num) = nums.next() {
            let diff = (last_seen - num).abs();
            if decending_order {
                if !(last_seen > num && diff <= 3 && diff > 0) {
                    counter_safe -= 1;
                    break;
                }
            } else {
                if !(last_seen < num && diff <= 3 && diff > 0) {
                    counter_safe -= 1;
                    break;
                }
            }
            last_seen = num;
        }
    }

    println!("{counter_safe}");
}
