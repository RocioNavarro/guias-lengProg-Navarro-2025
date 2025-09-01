/*
Escriba un programa que determine si un número representa un año bisiesto o no. Recuerde que las reglas para efectuar esta determinación son las siguientes:

Un año divisible por 4 es en general bisiesto; por ejemplo, 1980 y 2016 son años bisiestos;
La excepción a la regla anterior ocurre con los años que son fines de siglo, que en general no son bisiestos: 1900 y 1700 no fueron años bisiestos;
La excepción a la regla anterior ocurre con los años que son divisibles por 400, que, a pesar de ser fines de siglo, son bisiestos: 1600 y 2000 fueron años bisiestos.
*/

use std::io;

const BASIC_DIVISOR: i32 = 4;
const CENTURY_DIVISOR: i32 = 100;
const EXCEPCIONAL_DIVISOR: i32 = 400;

fn is_leap_year(year: i32) -> bool {

    if year % EXCEPCIONAL_DIVISOR == 0 {
        true  // Divisible por 400: bisiesto (ej: 1600, 2000)
    } else if year % CENTURY_DIVISOR == 0 {
        false // Divisible por 100 pero no por 400: no bisiesto (ej: 1700, 1900)
    } else if year % BASIC_DIVISOR == 0 {
        true  // Divisible por 4 pero no por 100: bisiesto (ej: 1980, 2016)
    } else {
        false // No divisible por 4: no bisiesto
    }
}

fn main() {
    println!("Verificador de años bisiestos");
    println!("Ingrese un año para verificar si es bisiesto:");
    
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Error al leer la entrada");
    
    let year: i32 = match input.trim().parse() {
        Ok(num) => num,
        Err(_) => {
            println!("Error: Por favor ingrese un número válido");
            return;
        }
    };
    
    if is_leap_year(year) {
        println!("El año {} es bisiesto", year);
    } else {
        println!("El año {} no es bisiesto", year);
    }
}