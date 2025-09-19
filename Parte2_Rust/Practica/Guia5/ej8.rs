//El siguiente programa no compila. Explique el error y resuélvalo sin tocar el main.

// Programa 8
fn main() {
    let s = give_ownership();
    let _s = s.into_bytes(); // Consume el String (toma su ownership) y devuelve un Vec<u8>, la variable s ya no es válida
    println!("{}", s); // s ya no existe --> ERROR: value borrowed here after move
}

/*
¡Modificar únicamente el código abajo!
fn give_ownership() -> String {
    let s = String::from("hello, world");
    s
}
*/


/*
SOLUCION:
No consumit s, devolver un clon de s para que s siga siendo válido en main. 

OBS:
Devolver una referencia (&String) no es una opción válida aquí, porque la referencia dejaría de ser válida al salir de la función,
ya que la variable s se destruye al finalizar la función give_ownership.
*/

fn give_ownership() -> String {
    let s = String::from("hello, world");
    s.clone() // Devolvemos una copia/clon del String, s sigue siendo válido en main
}

/* 
No se puede solucionar sin tocar el main 
No hay forma de resolver este problema solo cambiando give_ownership(), porque:

main consume el String con into_bytes().

Luego intenta usarlo de nuevo.
give_ownership() solo puede devolver un único String, y ese será movido por into_bytes().
*/
