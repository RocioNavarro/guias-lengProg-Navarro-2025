fn cube(x: f64) -> f64 {
    x*x*x
}

fn hypotenuse(a: f64, b: f64) -> f64 { 
    (a*a+b*b).sqrt()
}

fn solve_quadratic(a: f64, b: f64, c: f64) -> (f64, f64) {
    let d = b*b - 4.0*a*c;
    if d < 0.0 {
        (0.0, 0.0)
    } else {
        let sqrt_d = d.sqrt();
        ((-b + sqrt_d) / (2.0*a), (-b - sqrt_d) / (2.0*a))
    }
}


fn main() {
    println!("{}", cube(3.0));
    println!("{}", hypotenuse(3.0, 4.0));

    println!("{:?}", solve_quadratic(1.0, -3.0, 2.0)); 
    // (1.0, 2.0)
    println!("{:?}", solve_quadratic(1.0,  2.0, 5.0));
    // ???
}