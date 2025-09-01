/*
Queremos obtener el máximo común divisor (mcd) de dos números a y b. Para ello, utilizaremos el algoritmo de Euclides. 
Recuerde que este algoritmo funciona como sigue:
    si a y b son iguales, entonces devolver a (o b, tanto da);
    si a > b, entonces devolver el mcd de (a-b) y b;
    si no, devolver el mcd de a y (b-a).
*/

use std::io;

pub fn mcd(a: i32, b: i32) -> i32 {
    if a == b {
        a
    } else if a > b {
        mcd(a - b, b)
    } else {
        mcd(a, b - a)
    }
}

/*
fn main(){
    let a = 48;
    let b = 18;
    let resultado = mcd(a, b);
    println!("El mcd de {} y {} es {}", a, b, resultado);
}
*/

// Pidiendo los nros por consola:
fn main() {
    let mut input = String::new();

    println!("Ingrese el primer número:");
    io::stdin()
        .read_line(&mut input)
        .expect("Error al leer línea");
    let a: i32 = input.trim().parse().expect("Ingrese un número válido");

    input.clear(); // Limpiamos el buffer para el siguiente número

    println!("Ingrese el segundo número:");
    io::stdin()
        .read_line(&mut input)
        .expect("Error al leer línea");
    let b: i32 = input.trim().parse().expect("Ingrese un número válido");

    let resultado = mcd(a, b);
    println!("El mcd de {} y {} es {}", a, b, resultado);
}