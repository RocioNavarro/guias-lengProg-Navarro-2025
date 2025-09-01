/*
Escriba un programa que calcule el promedio de los números de una tupla de enteros de 32 bits. 
El programa debe devolver el resultado en un formato que permita decimales. 
En otras palabras, queremos que el promedio de (1, 3, 4, 6) sea 3.5 y no 3.
*/

fn main(){
    let numeros = (1, 3, 4, 6);
    let suma: i32 = numeros.0 + numeros.1 + numeros.2 + numeros.3;
    let promedio: f32 = suma as f32 / 4.0; // Convierto la suma a f32 para obtener un resultado con decimales
    println!("El promedio es: {}", promedio);
}