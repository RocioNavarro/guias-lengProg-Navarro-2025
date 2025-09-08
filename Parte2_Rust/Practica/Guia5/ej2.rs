// Programa 1
/*fn main() {
    let x = 5;
    let y = x; // Rust copia el valor de x en y, seguimos manteniendo el acceso a x
    println!("El valor de x es {} y el valor de y es {}.", x, y);
    // El valor de x es 5 y el valor de y es 5.
}*/

// Programa 2
fn main() {
    let st1 = String::from("hello");
    let st2 = st1; // el valor de st1 se mueve a st2, ya no hay acceso valido a st1
    println!("El valor de st2 es {}.", st2);
    // println!("El valor de st1 es {} y el valor de st2 es {}.", st1, st2); // ERROR: value borrowed here after move
}