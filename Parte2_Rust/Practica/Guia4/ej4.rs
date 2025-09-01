/*
Escriba un programa que, utilizando el código del ejercicio del ejercicio 3, imprima en pantalla los números primos entre 0 y 100.
*/

mod ej3;
use ej3::es_primo;

pub fn run() {
    println!("Números primos entre 0 y 100:");

    for number in 0..=100 {
        if es_primo(number) {
            print!("{} ", number);
        }
    }

    println!(); // salto de línea
}

fn main() {
    run();
}