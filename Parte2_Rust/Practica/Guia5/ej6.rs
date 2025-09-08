// Explique la diferencia entre los siguientes fragmentos de código. ¿Cuál le parece mejor? ¿Por qué?

/*
// Programa 5
fn main() {
    let s1 = String::from("hello");
    let (s2, len) = calcular_longitud(s1);
    println!("La longitud de {} es {}.", s2, len);
}

fn calcular_longitud(s: String) -> (String, usize) {
    let length = s.len(); 
    (s, length)
}
*/


// Programa 6
fn main() {
    let s1 = String::from("hello");
    let len = calcular_longitud(&s1);
    println!("La longitud de {} es {}.", s1, len);
}

fn calcular_longitud(s: &String) -> usize {
    s.len()
}