/*
Escriba un programa que, dado un número entero, encuentre la suma de sus dígitos individuales. 
Por ejemplo, la suma de 4122 es 4+1+2+2 = 9.
*/

use std::io;

fn suma_digitos(numero: i32) -> i32 {
    let s = numero.to_string();
    let mut suma = 0;

    for c in s.chars() {
        if c != '-' { // Salteo el - si el nro es negativo
            let digito = c.to_digit(10).unwrap() as i32; // Convierto de char a nro para sumar
            suma += digito;
        }
    }

    suma
}

fn main() {
    let mut input = String::new();
    println!("Ingrese un número entero:");
    io::stdin().read_line(&mut input).expect("Error al leer línea");
    let numero: i32 = input.trim().parse().expect("Ingrese un número válido");

    let resultado = suma_digitos(numero);
    println!("La suma de los dígitos de {} es {}", numero, resultado);
}
