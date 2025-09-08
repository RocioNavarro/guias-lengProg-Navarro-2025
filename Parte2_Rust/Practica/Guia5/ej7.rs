// Haga funcionar el siguiente código sin modificar el main. Explique el problema.

// Programa 7 
fn main() {
    let s1 = String::from("Hello world");
    let s2 = take_ownership(s1); // take_ownership(s1) toma la propiedad de s1 pero la devuelve, ahora s1 tiene la propiedad de "Hello world" 
    println!("{}", s2);
}

/* ¡Modificar únicamente el código abajo!
fn take_ownership(s: String) {
    println!("{}", s);
}
*/

fn take_ownership(s: String) -> String {
    println!("{}", s);
    s // Devolvemos la propiedad del String al que llama a la funcion
}