// El siguiente programa no compila. Explique el error y resuélvalo. ¿Qué conclusión puede sacar?
// Programa 9

/*
fn main() {
    let s = String::from("Hello ");   
    let s1 = s;
    s1.push_str("World!");
    println!("¡Final feliz!"); // ERROR: cannot borrow as mutable
}
*/

fn main() {
    let s = String::from("Hello ");   
    let mut s1 = s;
    s1.push_str("World!");
    println!("¡Final feliz!"); 
}