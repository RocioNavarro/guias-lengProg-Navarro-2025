//En el siguiente ejercicio, haga una pequeña investigación acerca del significado de Box y modifique 
// la línea señalada para que el programa tenga un final feliz.
// Programa 10

fn main() {
    let x = Box::new(5);  
    let ...      // Modificar esta línea. ¡No tocar las otras!
    *y = 4;
    assert_eq!(*x, 5);
    println!("¡Final feliz!");
}