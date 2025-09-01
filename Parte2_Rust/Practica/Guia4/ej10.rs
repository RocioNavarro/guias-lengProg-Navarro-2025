/*
En aritmética modular, el inverso multiplicativo de un número n módulo z es el número q tal que (n * q) mod z = 1. 
Por ejemplo, el inverso multiplicativo de 5 módulo 7 es 3, puesto que 3 * 5 = 15 mod 7 = 1. 
El inverso multiplicativo sólo existe si el mcd de n y z es 1. Por ejemplo, no existe inverso multiplicativo 
de 2 módulo 8. Escriba un programa que devuelva el inverso multiplicativo de dos números o algún código de 
error si no existe. Puede usar el código del ejercicio 11 para esta comprobación. Nota: observe que, 
dado que trabajamos módulo z, el inverso multiplicativo, si existe, debe estar entre 1 y z-1.
*/

mod ej9;
use ej9::mcd;

fn inverso_multiplicativo(n: i32, z: i32) -> Result<i32, &'static str> {
    if mcd(n, z) != 1 {
        return Err("No existe inverso multiplicativo");
    }

    for q in 1..z {
        if (n * q) % z == 1 {
            return Ok(q);
        }
    }

    Err("No se encontró inverso multiplicativo")
}

fn main(){
    let n = 5;
    let z = 7;

    match inverso_multiplicativo(n, z) {
        Ok(inverso) => println!("El inverso multiplicativo de {} módulo {} es {}", n, z, inverso),
        Err(err) => println!("{}", err),
    }
}