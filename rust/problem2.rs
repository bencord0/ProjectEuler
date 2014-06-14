fn main() {
    let cap = 4000000;
    let mut a = 0;
    let mut b = 1;
    let mut sum = 0;

    while a < cap {
        let c = a + b;
        a = b;
        b = c;
        if a % 2 == 0 {
            sum += a;
        }
    }

    println!("{}", sum);
}
