use std::{collections::VecDeque, io::stdin};

fn main() {
    const SIZE: usize = 14;

    let mut input = "".to_string();
    let _ = stdin().read_line(&mut input).expect("Failed to read input");

    let mut prev: VecDeque<char> = VecDeque::with_capacity(SIZE);

    for (i, c) in input.chars().enumerate() {
        if prev.len() == SIZE {
            prev.pop_back();
        }
        prev.push_front(c);

        if !prev
            .iter()
            .enumerate()
            .map(|(j1, c1)| {
                prev.iter()
                    .enumerate()
                    .map(|(j2, c2)| *c1 == *c2 && j1 != j2)
                    .fold(false, |acc, x| acc || x)
            })
            .fold(false, |acc, x| acc || x)
            && i > SIZE - 1
        {
            println!("{}", i + 1);
            break;
        }
    }
}
