// Programa 1
fn main () {
      let x = 1;
      println (“El valor de x es {}”, x);
      x = 2;
      println (“El valor de x es {}”, x);
}


/*
ERRORES:
1. La variable 'x' es inmutable por defecto en Rust. Para poder cambiar su valor, debe declararse como mutable utilizando 'let mut x = 1;'.
2. Las comillas tienen que ser asi: ""
3. println no es una funcion, hay que usar println! que es un macro, expande en código que:
            -Formatea los valores.
            -Los envía a la salida estándar (stdout).
            -Agrega un salto de línea al final.
OBS: Mientras que una función recibe valores y devuelve resultados en tiempo de ejecución, un macro recibe fragmentos de código y los transforma o genera nuevo código antes de compilar.
*/


// Programa 2
fn main () {
      let mut x = 1;
      println (“El valor de x es {}”, x);
      x = 2;
      println (“El valor de x es {}”, x);
}
/* 
ERROR: las comillas deberían ser asi: "" 
*/


// Programa 3
fn main () {
      let x = 1;
      println (“El valor de x es {}”, x);
      let x = 2;
      println (“El valor de x es {}”, x);
}
/*
ERROR: las comillas deberían ser asi: ""
OBS: el segundo let x = 2; oculta al primero ("shadowing")
*/



// Codigo corregido
fn main () {
      let mut x = 1;
      println!("El valor de x es {}", x);
      x = 2;  // tambien podria ir el let mut x = 2;
      println!("El valor de x es {}", x);
}
