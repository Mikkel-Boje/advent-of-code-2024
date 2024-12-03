use std::{
    collections::HashMap,
    fs::File,
    io::{BufRead, BufReader},
};

fn main() {
    let file = File::open("input.txt").expect("Couldnt open file");
    let lines = BufReader::new(file).lines().map(|l| l.unwrap());

    let (mut left, mut right): (Vec<i32>, Vec<i32>) = lines
        .map(|line| {
            let mut split = line.split_whitespace();
            (
                split.next().unwrap().parse::<i32>().unwrap(),
                split.next().unwrap().parse::<i32>().unwrap(),
            )
        })
        .unzip();

    left.sort();
    right.sort();

    let sum = left
        .iter()
        .zip(right.iter())
        .fold(0, |acc, (left_num, right_num)| {
            acc + (left_num - right_num).abs()
        });

    // Part 1 Done
    println!("{sum}");

    let mut counter_right = HashMap::new();
    for right in right.iter() {
        *counter_right.entry(right).or_insert(0) += 1;
    }

    let mut score = 0;
    for ref num in left {
        score += num * counter_right.get(num).unwrap_or(&0);
    }

    // Part 2 Done
    println!("{score}");
}
