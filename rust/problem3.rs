fn main() {
    //let composite = 13195;
    let composite = 600851475143;

    let mut factors = ~[];

    for i in range(2, sqrt(composite) + 1) {
        if composite % i == 0 {
            factors.push(i);
        }
    }

    // Which ones are prime?
    let mut largest_prime_factor = 0;
    for i in range(0, factors.len()) {
        let n = factors[i];
        if is_prime(n) {
            largest_prime_factor = n;
        }
    }
    println!("{}", largest_prime_factor);
}

fn sqrt(n: int) -> int {
    return (n as f64).sqrt() as int;
}

fn is_prime(n: int) -> bool {
    for i in range(2, sqrt(n) + 1) {
       if n % i == 0 { return false; }
    }
    return true;
}
