/*
Escriba un programa que calcule la desviación estándar de los números de una tupla de enteros de 32 bits. 
Recuerde que la desviación estándar es la raíz cuadrada del promedio de los cuadrados de las restas de 
cada elemento menos el promedio. Utilice el código del ejercicio 6 para obtener el promedio (aquí, 3.5).
*/

mod ej6;
use ej6::promedio;

fn desviacion_estandar() -> f32 {
    let numeros = (1, 3, 4, 6);
    let prom = promedio();
    let varianza = ((numeros.0 as f32 - prom).powi(2) + (numeros.1 as f32 - prom).powi(2) + (numeros.2 as f32 - prom).powi(2) + (numeros.3 as f32 - prom).powi(2)) / 4.0;
    varianza.sqrt() // desvio = raiz(varianza)
}

fn main(){
    let resultado = desviacion_estandar();
    println!("La desviación estándar es: {}", resultado);
}