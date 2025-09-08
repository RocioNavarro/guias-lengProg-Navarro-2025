// Explique qué sucede en el siguiente fragmento de código.

fn main() {
    let s1 = toma_prop();
    let s2 = String::from("hello");
    let s3 = toma_y_devuelve_prop(s2); // s2 se mueve a la función y ya no es accesible usando s2
    println!("El valor de s1 es {}", s1);
    // println!("El valor de s2 es {}", s2); // ERROR: value borrowed here after move
    println!("El valor de s3 es {}", s3);
} 

fn toma_prop() -> String {
    let cadena = String::from("hello");
    cadena
}

fn toma_y_devuelve_prop(cadena: String) -> String {
    cadena
}
