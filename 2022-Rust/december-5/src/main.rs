use std::io::stdin;

fn main() {
    let (instructions, input): (Vec<String>, Vec<String>) = stdin()
        .lines()
        .map(|l| l.expect("Expected Input"))
        .partition(|l| l.starts_with("move "));

    const EMPTY: Vec<char> = vec![];
    let mut stacks: [Vec<char>; 9] = [EMPTY; 9];

    for line in input
        .iter()
        .rev()
        .skip(2)
        .map(|l| l.chars().collect::<Vec<char>>())
    {
        for (i, val) in line.iter().skip(1).step_by(4).enumerate() {
            print!("{}", val);
            if *val != ' ' {
                stacks[i].push(*val)
            }
        }
        println!()
    }

    println!("{:?}", stacks);

    for instruction in instructions.iter() {
        let parts: Vec<&str> = instruction.split(" ").collect();

        let quantity = parts[1]
            .parse::<usize>()
            .expect("quantity formatted incorrectly");
        let from = parts[3]
            .parse::<usize>()
            .expect("from formatted incorrectly")
            - 1;
        let to = parts[5].parse::<usize>().expect("to formatted incorrectly") - 1;

        // for _ in 0..quantity {
        //     let val = stacks[from - 1].pop().unwrap();
        //     stacks[to - 1].push(val);
        // }

        let mut vals: Vec<char> = stacks[from]
            .drain(stacks[from].len() - quantity..)
            .collect();
        stacks[to].append(&mut vals);
    }

    for c in stacks.map(|s| *s.last().unwrap()) {
        print!("{}", c);
    }
    println!()
}
