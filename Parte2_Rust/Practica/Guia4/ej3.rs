/*
Escriba un programa para determinar si un número es primo o no. 
Recuerde que un número es primo si es mayor que 1 y no admite otro divisor que 1 y sí mismo.
*/

// Hice publica la funcion para poder usarla en el ej 4
pub fn es_primo(number: u32) -> bool {
    const MIN_PRIME: u32 = 2;

    if number < MIN_PRIME {
        return false;
    }

    // Solo necesitamos chequear hasta la raíz cuadrada de number
    let limite = (number as f64).sqrt() as u32;
    for i in MIN_PRIME..=limite {
        if number % i == 0 {
            return number == i; // Solo se divide entre sí mismo
        }
    }
    true
}

fn main() {
    let number = 107; 

    if es_primo(number) {
        println!("El número {} es primo.", number);
    } else {
        println!("El número {} no es primo.", number);
    }
}

