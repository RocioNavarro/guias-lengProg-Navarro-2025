// Explique el siguiente programa:

// Programa 4
fn main () {
      let num = Some(7);
      // Si num es Some(valor), asigná ese valor a x y ejecutá el bloque.
      if let Some(x) = num {
             println! (“Match: {:?}”, x); 
             // Correccion de comillas:
             // println!("Match: {:?}", x);
      }
}


// Equivalencia con un match completo:
/*fn main () {
    let num = Some(7);
    match num {
        Some(x) => println!("Match: {:?}", x),
        None => {} // no hacer nada si es None
    }
}*/
// Para este caso no es necesario hacerlo asi completo porque en caso de None no se hace nada